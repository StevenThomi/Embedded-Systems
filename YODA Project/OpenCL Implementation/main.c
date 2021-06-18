//==============================================================================
// Copyright (C) Steve Thomi
// THMSTE021@myuct.ac.za
//
// This file is part of the EEE4120F Course PSA Project
//
// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
//
// Settings of the OpenCL application have been inspired by:
// https://www.eriksmistad.no/getting-started-with-opencl-and-gpu-computing/
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "Timer.h"
#include "Timer.c"

#define MAX_SOURCE_SIZE (0x100000)

/** \file main.c
 *  Host Application - OpenCL Host
 *  The purpose of this file is to set up the OpenCL
 *  environment, inputs and outputs, and kernel.
 */
int main(void) {
    int i;

    //! Define input array length variables
    const int block_size = pow(4, 1);
    const int pattern_size = 4;

    //! Create the two input arrays
    int *Pattern = (int*)malloc(sizeof(int)*pattern_size);
    int *Block = (int*)malloc(sizeof(int)*block_size);

    //! Populate the Block (block memory) array
    for(i = 0; i < block_size; i++){
      Block[i] = (block_size-1)-i;
    }

    //! Define the pattern to be searched for
    Pattern[0] = 3;
    Pattern[1] = 2;
    Pattern[2] = 1;
    Pattern[3] = 0;

    tic();
    //! Load the kernel source code into the array source_str
    FILE *fp;
    char *source_str;
    size_t source_size;

    fp = fopen("search_kernel.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }
    source_str = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose( fp );

    //! Get platform and device information
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
            &device_id, &ret_num_devices);

    //! Create an OpenCL context
    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);

    //! Create a command queue
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    //! Create memory buffers on the device for each vector
    cl_mem pattern_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
            pattern_size * sizeof(int), NULL, &ret);
    cl_mem block_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
            block_size * sizeof(int), NULL, &ret);
    cl_mem pattern_size_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
            1 * sizeof(int), NULL, &ret);
    cl_mem output_index_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
            1 * sizeof(int), NULL, &ret);

    //! Copy pattern_size, lists Pattern and Block to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, pattern_mem_obj, CL_TRUE, 0,
            pattern_size * sizeof(int), Pattern, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, block_mem_obj, CL_TRUE, 0,
            block_size * sizeof(int), Block, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, pattern_size_mem_obj, CL_TRUE, 0,
            1 * sizeof(int), &pattern_size, 0, NULL, NULL);
    //! Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,
            (const char **)&source_str, (const size_t *)&source_size, &ret);

    //! Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    //! Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "search", &ret);

    //! Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&pattern_mem_obj);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&block_mem_obj);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&pattern_size_mem_obj);
    ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&output_index_mem_obj);

    //! Execute the OpenCL kernel on the list
    size_t global_item_size = block_size; //!< Process the entire lists
    size_t local_item_size = 1; //!< Divide work items into groups
    tic();
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
            &global_item_size, &local_item_size, 0, NULL, NULL);
    printf("\nOpenCL Implementation: %.5f ms\n\n", toc()/1e-3);

    //! Read the memory buffer output_index on the device to the local variable output_index
    int output_index;
    ret = clEnqueueReadBuffer(command_queue, output_index_mem_obj, CL_TRUE, 0,
            1 * sizeof(int), &output_index, 0, NULL, NULL);

    //! Display the result to the screen
    printf("The pattern to be searched for is: \n");
    for(i = 0; i < pattern_size; i++) {
      printf("%d \t", Pattern[i]);
    }
    printf("\n");

    printf("The block to be searched is: \n");
    for(i = 0; i < block_size; i++) {
      printf("Index: %d \t Block Element: %d \n",i, Block[i]);
    }

    printf("\n");

    if (output_index == -1)
      printf("The pattern was not found in the block.\n");
    else
      printf("The pattern was found in the block.\n Start Index: %d \n End Index: %d \n",output_index, output_index+(pattern_size-1));

    //! Clean up
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(pattern_mem_obj);
    ret = clReleaseMemObject(block_mem_obj);
    ret = clReleaseMemObject(pattern_size_mem_obj);
    ret = clReleaseMemObject(output_index_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(Pattern);
    free(Block);
    return 0;
}
