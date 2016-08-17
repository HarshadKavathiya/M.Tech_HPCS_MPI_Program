#include<mpi.h>
#include<stdio.h>
#include<string.h> 

int main(int argc, char* argv[])
{
  int myrank,size,length,length1,i;
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  char a1[20],a2[20];
  if (myrank == 0)
   {
    printf("Welcome to Processor 0\n");    
    gets(a1); 
    length=strlen(a1);
    length++;
    //printf("size:-%d",size);
    for(i=1;i<size;i++)
      {  
        MPI_Send(&length,1,MPI_INT,i,0,MPI_COMM_WORLD);
        MPI_Send(a1,length,MPI_CHAR,i,1,MPI_COMM_WORLD);
        //MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator);
      }
   }

    
    printf("Welcome to Slaves %d Processor \n",myrank);    
  //  MPI_Barrier(MPI_COMM_WORLD);//when any processor come here then it stops its execution and wait for others and then again start... 
    
    MPI_Recv(&length1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    MPI_Recv(&a2,length1,MPI_CHAR,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    //MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)

    printf("Process %d received String from process 0 is :- %s\n",myrank,a2);
  
  return 0;
}

/*Although this might seem like a mouthful when reading all of the arguments, they become easier to remember since almost every MPI call uses similar syntax. 
The first argument is the data buffer. 
The second and third arguments describe the count and type of elements that reside in the buffer. MPI_Send sends the exact count of elements, and MPI_Recv will receive at most the count of elements (more on this in the next lesson). 
The fourth and fifth arguments specify the rank of the sending/receiving process and the tag of the message. 
The sixth argument specifies the communicator and the last argument (for MPI_Recv only) provides information about the received message.*/
