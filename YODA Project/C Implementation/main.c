#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Timer.h"
#include "Timer.c"

int main(void) {
    // Get the index of the current element to be processed
    int i = 0;
    int j = 0;

    const int block_size = pow(4, 10);
    const int pattern_size = 4;

    int *Pattern = (int*)malloc(sizeof(int)*pattern_size);
    int *Block = (int*)malloc(sizeof(int)*block_size);

    for(i = 0; i < block_size; i++){
      Block[i] = (block_size-1)-i;
    }

    Pattern[0] = 3;
    Pattern[1] = 2;
    Pattern[2] = 1;
    Pattern[3] = 0;

    int output_index = -1; //0xFFFFFFFF

    // Do the operation

    tic();
    for(i = 0; i < block_size; i++){
        j = 0;
        while(Pattern[j] == Block[i+j]){
            j = j + 1;

            if(j == pattern_size){
            // return memory position
              output_index = i;
            }
        }
    }
    printf("\nC Implementation: %.5f ms\n\n", toc()/1e-3);

    // Display the result to the screen
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

    free(Pattern);
    free(Block);
}
