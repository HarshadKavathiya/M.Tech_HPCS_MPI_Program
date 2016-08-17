#include <mpi.h>
#include <stdio.h>
 
int main (int argc, char* argv[])
{
  int myrank,size;
  
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Status status;
  int number,number1;
  if (myrank == 0)
   {

    number = 10;
    MPI_Send(&number,1,MPI_INT,1,0,MPI_COMM_WORLD);
    //MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator);
   
   }

  else
   {

    MPI_Recv(&number1,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
    //MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)

    printf("Process %d received number %d from process 0\n",myrank,number1);
  }

  return 0;
}

/*Although this might seem like a mouthful when reading all of the arguments, they become easier to remember since almost every MPI call uses similar syntax. 
The first argument is the data buffer. 
The second and third arguments describe the count and type of elements that reside in the buffer. MPI_Send sends the exact count of elements, and MPI_Recv will receive at most the count of elements (more on this in the next lesson). 
The fourth and fifth arguments specify the rank of the sending/receiving process and the tag of the message. 
The sixth argument specifies the communicator and the last argument (for MPI_Recv only) provides information about the received message.*/

