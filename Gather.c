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
    int *a;
     
    for(i=0;i<mysize;i++)
        { 
         if(myrank==i)
       		number=myrank+i;
        }   
    if(myrank == 0)
        {
        a = (int*)malloc(sizeof(int)*mysize);   
        }

      printf("Processor %d with Number :%d\n",myrank,number);
 
     MPI_Gather(&number,1,MPI_INT,a,1,MPI_INT,0,MPI_COMM_WORLD);
   // MPI_Gather(void* send_data, int send_count, MPI_Datatype send_datatype,
        //          void* recv_data, int recv_count, MPI_Datatype recv_datatype,
      //          int root, MPI_Comm communicator)   
    if(myrank == 0)
    {
      printf("Number which Processor %d Received are \n",myrank);
      for(i=0;i<mysize;i++)
        printf("%d  ",a[i]);  
    }
    
    MPI_Finalize();
    }

