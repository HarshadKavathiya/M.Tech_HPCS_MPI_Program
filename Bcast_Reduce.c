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
   
    int sum=0; 
    for(i=0;i<4;i++)
       sum=sum+buffer[i];  
    printf("From Processor %d with Local Sum :%d\n",myrank,sum);
    int total_sum=0;
      MPI_Reduce(&sum,&total_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
   // MPI_Reduce(void* send_data, void* recv_data, int count,
     //      MPI_Datatype datatype, MPI_Op op, int root,
       //    MPI_Comm communicator)

   
    //MPI_Barrier(MPI_COMM_WORLD);
    
    if(myrank == 0)
    {
      printf("Total Sum = %d \n",total_sum);  
    }
    MPI_Finalize();
}

