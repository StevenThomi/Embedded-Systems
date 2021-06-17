/** \file search_kernel.cl
 *  search - OpenCL kernel
 *  The aim of this kernel is to search for a pattern of
 *  bytes by traversing through i:i+p memory addresses.
 */
__kernel void search(__global const int *Pattern,   //!< in: 1-D int array
                     __global const int *Block,     //!< in: 1-D int array
                     __global const int *pattern_size,  //!< in: int pointer
                     __global int *output_index     //!< out: int pointer
                     ) {
    //! <h3>Search Kernel</h3>
    int i = get_global_id(0); //!< index of the current element to be processed
    int j = 0; //!< sentinel index of the pattern

    *output_index = -1; //0xFFFFFFFF //!< output if not found

    // Do the search operation
    while(Pattern[j] == Block[i+j]){
        //! If a match is made, check for a match in the whole pattern
        j = j + 1; //!< traverse pattern

        if(j == *pattern_size){
          //! If the whole pattern matches, output memory location
          *output_index = i; //!< output if found
        }
    }
}
