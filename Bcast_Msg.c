#include<stdio.h>
#include<mpi.h>
#include<string.h>
 
int main(int argc,char* argv[])
{
    int i,myrank,mysize,length;
    char msg[10];

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&mysize);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    
    if(myrank == 0)
    {
      printf("enter the Message :\n");
         gets(msg);
    }

    length=strlen(msg);
    length++;
     MPI_Bcast(&length,1,MPI_INT,0,MPI_COMM_WORLD);
     MPI_Bcast(msg,length,MPI_CHAR,0,MPI_COMM_WORLD);
     //MPI_Bcast(void* data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator);
   
    //MPI_Barrier(MPI_COMM_WORLD);
    
    printf("Processor : %d Received Message : %s\n",myrank,msg);
      
    printf("\n");

    MPI_Finalize();
}

