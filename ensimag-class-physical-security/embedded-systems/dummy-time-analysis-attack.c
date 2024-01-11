/* 
File: dummy-time-analysis-attack.c
Author: davidecaria
Description:

Simple demonstation of how a time analysis attack work. For this scope, a multiply and add algorithm is implemented. 
Inside the add branch a sleep is inserted to enphasise the difference between one bit and the other.
Assuming that we know the first bit of the key, we can easily spot the others by looking at the time it takes for each operation.
This is just a dummy example and no real life implementation would use a sleep inside such an alorithm. 
However, it turns out to be particularly easy to get the bits of the secret key if the designed did a poor job in implementing the algorithm in hardware.

Date: Jan 10, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define LENGHT 10

int main(){

    srand(time(NULL));

    int secret_key[LENGHT];
    int base_number=10;
    int output_number;

    // Generating the random set of numbers that will act as the key
    for(int i=0;i<LENGHT;i++){
        secret_key[i] = rand()%2;
    }

    //Setting up the time stamps
    clock_t init_time;
    clock_t final_time;
    double elapsed_time;

    //Assume to know the first bit of the key
    secret_key[0]=1;
    output_number=base_number;

    //Double-and-add algorithm
    for(int i=1;i<LENGHT;i++){
        init_time = clock();
        output_number = output_number*output_number;
        if(secret_key[i]==1){
            output_number=output_number+base_number;
            sleep(0.001);
        }
        final_time = clock();
        elapsed_time = (double)(final_time-init_time)/CLOCKS_PER_SEC;
        printf("Operation n.%d executed in %f seconds for the key bit equal to: %d\n", i,elapsed_time, secret_key[i]);
    }

    //Full key is shown, including the known bit
    printf("The original key is: ");
    for(int i=0;i<LENGHT;i++){
        printf("%d ",secret_key[i]);
    }


}