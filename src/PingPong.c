#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
mpicc src/PingPong.c -o PingPong 
mpirun -np 2 ./PingPong
*/

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rounds = 3;
    int data = 0;
    int tag = 0;
    int counter = 0;

    for (int i = 0; i < rounds; i++) {
       
        if (rank == 0) {
            counter++;
            MPI_Send(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
            printf("Ping from [%d] --> %d\n", rank, counter);
            MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }else{
            int recv_counter;
            MPI_Recv(&recv_counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            recv_counter++;
            printf("Pong from [%d] --> %d\n", rank, recv_counter);              
            MPI_Send(&recv_counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
        }   
        MPI_Barrier(MPI_COMM_WORLD);
    }
    
    
    MPI_Finalize();
    return 0;
}





