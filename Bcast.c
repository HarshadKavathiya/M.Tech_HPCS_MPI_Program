#include<stdio.h>
#include<mpi.h>
 
int main(int argc,char* argv[])
{
    int i,myrank,mysize;
    int buffer[4];

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&mysize);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    
    if(myrank == 0)
    {
      printf("enter the Data :\n");
      for(i=0;i<4;i++)
         scanf("%d",&buffer[i]);
    }
     MPI_Bcast(buffer,4,MPI_INT,0,MPI_COMM_WORLD);
     //MPI_Bcast(void* data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator);
   
    //MPI_Barrier(MPI_COMM_WORLD);
    
    printf("Processor : %d\n",myrank);
    for(i=0;i<4;i++)
      printf("%d ",buffer[i]);
    printf("\n");

    MPI_Finalize();
}

