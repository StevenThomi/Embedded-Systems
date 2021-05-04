//==============================================================================
// Copyright (C) John-Philip Taylor
// tyljoh010@myuct.ac.za
//
// This file is part of the EEE4120F Course
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
// This is an adaptition of The "Hello World" example avaiable from
// https://en.wikipedia.org/wiki/Message_Passing_Interface#Example_program
//==============================================================================


/** \mainpage Prac3 Main Page
 *
 * \section intro_sec Introduction
 *
 * The purpose of Prac3 is to learn some basics of MPI coding.
 *
 * Look under the Files tab above to see documentation for particular files
 * in this project that have Doxygen comments.
 */



//---------- STUDENT NUMBERS --------------------------------------------------
//
// Please note:  put your student numbers here !!  <<<< NB!  NB!
//
//-----------------------------------------------------------------------------

/* Note that Doxygen comments are used in this file. */
/** \file Prac3
 *  Prac3 - MPI Main Module
 *  The purpose of this prac is to get a basic introduction to using
 *  the MPI libraries for prallel or cluster-based programming.
 */

// Includes needed for the program
#include "Prac3.h"

/** This is the master node function, describing the operations
    that the master will be doing */
void Master () {
  //! <h3>Local vars</h3>
  // The above outputs a heading to doxygen function entry
  int  j;             //! j: Loop counter
  char buff[BUFSIZE]; //! buff: Buffer for transferring message data
  MPI_Status stat;    //! stat: Status of the MPI application

  // Start of "Hello World" example..............................................
  printf("0: We have %d processors\n", numprocs);
  for(j = 1; j < numprocs; j++) {
   sprintf(buff, "Hello %d! ", j);
   MPI_Send(buff, BUFSIZE, MPI_CHAR, j, TAG_0, MPI_COMM_WORLD);
  }
  for(j = 1; j < numprocs; j++) {
   // This is blocking: normally one would use MPI_Iprobe, with MPI_ANY_SOURCE,
   // to check for messages, and only when there is a message, receive it
   // with MPI_Recv.  This would let the master receive messages from any
   // slave, instead of a specific one only.
   MPI_Recv(buff, BUFSIZE, MPI_CHAR, j, TAG_0, MPI_COMM_WORLD, &stat);
   printf("0: %s\n", buff);
  }
  // End of "Hello World" example................................................

  // Read the input image
  if(!Input.Read("Data/greatwall.jpg")){
   printf("Cannot read image\n");
   return;
  }

  // Allocated RAM for the output image
  if(!Output.Allocate(Input.Width, Input.Height, Input.Components)) return;

  // This is example code of how to copy image files ----------------------------
  printf("Start of example code...\n");
  int dimension[2];      //!< dimension stores array size and the x-limit
  dimension[0] = Input.Width * Input.Components; //!< set x-limit
  int* Big_Input = new int[dimension[0]*Input.Height];  //!< large 1D array for use with Small_Input
  int* Big_Output = new int[dimension[0]*Input.Height]; //!< large 1D array for use with Small_Output
  int* Small_Input;   //!< small 1D array for use with MPI_Send
  int* Small_Output;  //!< small 1D array for use with MPI_Recv
  /*!< section: declares the minimum transmission array size
       remain:  declares the portions to be divided between some processors*/
  int section = (dimension[0]*Input.Height)/(numprocs-1);
  int remain = (dimension[0]*Input.Height)%(numprocs-1);

  //! Step 1: Form a large 1-D array (source)
  /*!
  Transfer contents of 2D array Input.Rows[y][x] into large 1D array Big_Input[i]
  MPI's buffer supports pointer types (1D arrays), but not 2D arrays (int**)
  */
  int i = 0;    //!< i: loop sentinel value
    for (int y=0 ; y < Input.Height; y++){
       for (int x=0 ; x < dimension[0]; x++){
         Big_Input[i] = Input.Rows[y][x];
         i = i + 1;
       }
     }

   double processing_time = 0;    //!< processing time -> processing
   double overhead_time = 0;      //!< overhead time -> array creation, assignment

   //! Step 2: Split Big_Input into smaller chunks for each process
   int input_count = 0;   //!< sentinel to Big_Input
   int output_count = 0;  //!< sentinel to Big_Output (input cycle)
   int merge_count = 0;   //!< sentinel to Big_Output (output cycle)

   /*!
   For each processor:
   1. determine the array size to send to it
   2. partition Big_Input to meet requirement 1
   3. carry out a send and receive cycle from/to the current processor
   4. recoup the large 1D array we started with (piece by piece)
   */
   for(j = 1; j < numprocs; j++) {
     tic();
     //! Identify size of array to send to each process
     /*!
     The goal here is to evenly distribute the remainder array elements to some
     processors, so the processors carry a fairly similar workload for >> remainder
     */
     if(remain > 0){
       dimension[1] = section + 1;
       remain = remain - 1;   //!< As the remainder is distributed, it decreases
     } else { // rem = 0 implied
       dimension[1] = section;
     }

     Small_Input = new int[dimension[1]];   //!< Array to cater to sending needs
     Small_Output = new int[dimension[1]];  //!< Array to cater to receiving needs

     //! Serve each process with a unique data set
     /*!
     Split Big_Input into smaller pieces to be sent through each process.
     Maintain knowledge of where the sentinel input_count has reached.
     */
     for(int i = 0; i < dimension[1]; i++){
       Small_Input[i] = Big_Input[i+input_count];
     }
     input_count = input_count + dimension[1];   // prepare Big_Input sentinel for next process

     overhead_time = overhead_time + toc();

     //! Transmit the datasets for processing
     tic();
     MPI_Send(dimension, 2, MPI_INT, j, TAG_1, MPI_COMM_WORLD);
     MPI_Send(Small_Input, dimension[1], MPI_INT, j, TAG_2, MPI_COMM_WORLD);
     //! Receive the processed data via Small_Output
     MPI_Recv(Small_Output, dimension[1], MPI_INT, j, TAG_3, MPI_COMM_WORLD, &stat);

     processing_time = processing_time + toc();

     //! Step 3: Form a large 1-D array from the smaller chunks
     /*! This is the opposite to what was done in Step 1*/
     tic();
     for (int k=0 ; k < dimension[1]; k++){
       Big_Output[output_count] = Small_Output[k];
       output_count = output_count + 1;
     }

     overhead_time = overhead_time + toc();

     delete Small_Input;     // free memory
     delete Small_Output;    // free memory
}


   //! Step 4: Assemble the results (Finally!)
   /*! The results are placed into JPEG object Output */
   tic();
   for (int y=0 ; y < Input.Height; y++){
     for (int x=0 ; x < dimension[0]; x++){
       Output.Rows[y][x] = Big_Output[merge_count];
       merge_count = merge_count + 1;       // prepare Big_Output sentinel for next iteration
     }
   }
   //! print the merge time, average processing time, average overhead time
   printf("Merge Time = %lg ms\n", (double)toc()/1e-3);
   printf("Processing Time = %lg ms\n", (double)processing_time/((numprocs-1)*1e-3));
   printf("Overhead Time = %lg ms\n", (double)overhead_time/((numprocs-1)*1e-3));

   delete Big_Input;     // free memory
   delete Big_Output;    // free memory

   printf("End of example code...\n\n");
   //! <h3>Output</h3> The file Output.jpg will be created on success to save
   //! the processed output.
   if(!Output.Write("Data/Output.jpg")){
     printf("Cannot write image\n");
     return;
   }
}
 //------------------------------------------------------------------------------

 /** This is the Slave function, the workers of this MPI application. */
void Slave(int ID){
   // Start of "Hello World" example..............................................
   char idstr[32];
   char buff [BUFSIZE];
   MPI_Status stat;

   //! receive from rank 0 (master)
   MPI_Recv(buff, BUFSIZE, MPI_CHAR, 0, TAG_0, MPI_COMM_WORLD, &stat);
   sprintf(idstr, "Processor %d ", ID);
   strncat(buff, idstr, BUFSIZE-1);
   strncat(buff, "reporting for duty", BUFSIZE-1);

   // send to rank 0 (master):
   MPI_Send(buff, BUFSIZE, MPI_CHAR, 0, TAG_0, MPI_COMM_WORLD);
   //..............................................................................
   int dimension[2];
   //! receive data size and x-limit from rank 0 (master)
   MPI_Recv(dimension, 2, MPI_INT, 0, TAG_1, MPI_COMM_WORLD, &stat);
   int* Small_Input = new int[dimension[1]];   //!< Small_Input: for use with MPI_Recv
   int* Small_Output = new int[dimension[1]];  //!< Small_Output: for use with MPI_Send

   //! receive data contents from rank 0 (master)
   MPI_Recv(Small_Input, dimension[1], MPI_INT, 0, TAG_2, MPI_COMM_WORLD, &stat);

   //! process inputs to derive outputs
   for (int x=0 ; x < dimension[1]; x++){
     Small_Output[x] = Small_Input[x];
   }

   //! transmit processed data to rank 0 (master)
   MPI_Send(Small_Output, dimension[1], MPI_INT, 0, TAG_3, MPI_COMM_WORLD);

   delete Small_Input;       // free memory
   delete Small_Output;      // free memory
   //..............................................................................
}
 //------------------------------------------------------------------------------

 /** This is the entry point to the program. */
  int main(int argc, char** argv){
   int myid;

   // MPI programs start with MPI_Init
   MPI_Init(&argc, &argv);

   // find out how big the world is
   MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

   // and this processes' rank is
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);

   // At this point, all programs are running equivalently, the rank
   // distinguishes the roles of the programs, with
   // rank 0 often used as the "master".
   if(myid == 0) Master();
   else          Slave (myid);

   // MPI programs end with MPI_Finalize
   MPI_Finalize();
   return 0;
  }
  //------------------------------------------------------------------------------
