#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
 
int main(int argc,char* argv[])
{
    int i,myrank,mysize;
    
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&mysize);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    
    int sum=0,number ;

   
    for(i=0;i<mysize;i++)
        { 
         if(myrank==i)
       		number=myrank+i;
        }   


      printf("Processor %d with Number :%d\n",myrank,number);
 
     MPI_Reduce(&number,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
   // MPI_Reduce(void* send_data, void* recv_data, int count,
     //      MPI_Datatype datatype, MPI_Op op, int root,
       //    MPI_Comm communicator)
   
    if(myrank == 0)
    {
      printf("Total Sum = %d \n",sum);  
    }
    MPI_Finalize();
}

