#include<mpi.h>
#include<stdio.h>
#include<math.h>
 
int main (int argc, char* argv[])
{
  int size,rank,r,d;
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);        /* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);        /* get number of processes */
 
   if(rank%2==0)
     printf( "Hello world I m EVEN No. Processor from process %d of %d\n", rank, size );
   else
     printf( "Hello world I m ODD No. Processor from process %d of %d\n", rank, size );
 
   r= (double)(rank);  
   d= (int)sqrt(r);
   
   if(rank==d)
     printf( "Hello world I m PERFECT SQURE No. Processor from process %d of %d\n", rank, size );

  MPI_Finalize();
  return 0;
}
