#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define N 15000

int main(int argc, char const *argv[])
{
	int i,j;
	double prime=0,start,total=0;
	start=omp_get_wtime();
	for(int k=1;k<=N;k*=2)
	{
		for(i=2;i<=k;i++)
	  	{
	  		prime=1;
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{
					prime=0;
					break;
				}
			}
			total=total+prime;
	  	}
	  	printf("For n : %d #Primes : %lf\n",k,total );
	}
  	double end=omp_get_wtime();
  	printf("Total Time : %lf seconds\n",(end-start) );
	return 0;
}

/* Time taken for sequential execution is 0.027 seconds.
*/