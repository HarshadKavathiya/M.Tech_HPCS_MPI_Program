#include<mpi.h>
#include<stdio.h>
#include<string.h> 

int main(int argc, char* argv[])
{
  int myrank,size,length,length1,i;
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  char a1[20],a2[20],ar1[20];

  if (myrank == 0)
   {
    printf("Welcome to Processor 0\n");    
    printf("Enter the Message :-\n");  
    gets(a1); 
    length=strlen(a1);
    length++;

        MPI_Send(&length,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(a1,length,MPI_CHAR,1,1,MPI_COMM_WORLD);

        MPI_Recv(ar1,length,MPI_CHAR,1,2,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    
       //MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator);
   
     printf("Process %d received Echoing String from process 1 is :- %s\n",myrank,ar1);
 
   }

  else 
   {
    printf("Welcome to Processor 1\n");

    MPI_Recv(&length1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    MPI_Recv(a2,length1,MPI_CHAR,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

    MPI_Send(a2,length1,MPI_CHAR,0,2,MPI_COMM_WORLD);
    
    //MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)

   }
  return 0;
}

/*Although this might seem like a mouthful when reading all of the arguments, they become easier to remember since almost every MPI call uses similar syntax. 
The first argument is the data buffer. 
The second and third arguments describe the count and type of elements that reside in the buffer. MPI_Send sends the exact count of elements, and MPI_Recv will receive at most the count of elements (more on this in the next lesson). 
The fourth and fifth arguments specify the rank of the sending/receiving process and the tag of the message. 
The sixth argument specifies the communicator and the last argument (for MPI_Recv only) provides information about the received message.*/
