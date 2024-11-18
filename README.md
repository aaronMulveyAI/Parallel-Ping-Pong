# PingPong MPI Program

This repository contains an implementation of a simple **Ping-Pong** program using the **Message Passing Interface (MPI)**. The program demonstrates basic communication between two MPI processes by exchanging messages in a loop for a specified number of rounds.

## Features

- **Basic MPI Communication**: Utilizes `MPI_Send` and `MPI_Recv` for message exchange between processes.
- **Two-Process Interaction**: One process sends a "ping," and the other responds with a "pong."
- **Configurable Rounds**: The number of ping-pong exchanges can be adjusted within the source code.
- **Synchronization**: Employs `MPI_Barrier` to ensure proper synchronization between processes in each round.

## Prerequisites

- **MPI Library**: Ensure you have an MPI implementation installed (e.g., MPICH or OpenMPI).
- **C Compiler**: Requires `mpicc`, a C compiler with MPI support.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/pingpong-mpi.git
   cd pingpong-mpi
