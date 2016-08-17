#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
 
int main(int argc,char* argv[])
{
    int i,myrank,mysize,N;
    int *a;
    int *b ;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&mysize);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    
    a = (int*)malloc(sizeof(int)*mysize);   
    b = (int*)malloc(sizeof(int)*mysize);   
  
    if(myrank == 0)
    {
      printf("enter the Numbers of elements in array :\n");
      scanf("%d",&N);
      printf("enter the elements :\n");
      for(i=0;i<N;i++)
         scanf("%d",&a[i]);
    }
    
    MPI_Scatter(a,2,MPI_INT,b,2,MPI_INT,0,MPI_COMM_WORLD);
     // MPI_Scatter(void* send_data, int send_count, MPI_Datatype send_datatype,
       //     void* recv_data, int recv_count, MPI_Datatype recv_datatype,
         //   int root, MPI_Comm communicator)
    
     printf("Processor :%d\n",myrank);
    for(i=0;i<2;i++)
      printf("With value : %d\n",b[i]);
   //MPI_Barrier(MPI_COMM_WORLD);

   // MPI_Finalize();
 return 0;
}

