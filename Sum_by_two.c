#include<mpi.h>
#include<stdio.h>
#include<string.h> 

int main(int argc, char* argv[])
{
  int myrank,size,length,length1,i;
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  int a1[10],a2[10],s0=0,s1=0,j;
  if (myrank == 0)
   {
    printf("Enter the numbers  :-\n");
     for(i=0;i<10;i++)
       scanf("%d",&a1[i]);
     for(i=0;i<5;i++)
        s0=s0+a1[i];
    
     printf("sum0 == %d\n",s0);
 
        MPI_Send(&i,1,MPI_INT,1,0,MPI_COMM_WORLD);  
        MPI_Send(a1,sizeof(a1),MPI_INT,1,1,MPI_COMM_WORLD);
        //MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator);
        MPI_Recv(&i,1,MPI_INT,1,2,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Total sum := %d\n",s0+i);
    }
  else 
   {
    MPI_Recv(&i,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    MPI_Recv(a2,sizeof(a2),MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    
    for(i=5;i<10;i++)
        s1=s1+a2[i];
   
    //MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)
    printf("sum1 == %d\n",s1);
    i=s1;
    MPI_Send(&i,1,MPI_INT,0,2,MPI_COMM_WORLD);
  }
 
  // MPI_Finalize();
  return 0;
}

/*Although this might seem like a mouthful when reading all of the arguments, they become easier to remember since almost every MPI call uses similar syntax. 
The first argument is the data buffer. 
The second and third arguments describe the count and type of elements that reside in the buffer. MPI_Send sends the exact count of elements, and MPI_Recv will receive at most the count of elements (more on this in the next lesson). 
The fourth and fifth arguments specify the rank of the sending/receiving process and the tag of the message. 
The sixth argument specifies the communicator and the last argument (for MPI_Recv only) provides information about the received message.*/
