#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
//Indentation Style : Allman

int main(int argc, char const *argv[])
{
	int N,i;
	printf("Enter size of array : ");
	scanf("%d",&N);
	int a[N],b[N],c[N],d[N],e[N];
	double start=omp_get_wtime();
	#pragma omp parallel private(i)
	{
		#pragma omp parallel 
		{
			for(i=0;i<N;i++)
			{
				a[i]=1;
				b[i]=2;
				c[i]=3;
			}
		}
		//#pragma omp parallel 
		{
			for(i=0;i<N;i++)
			{
				d[i]=a[i]+b[i];
			}
		}
		//#pragma omp parallel 
		{
			for(i=0;i<N;i++)
			{
				e[i]=c[i]*c[i];
			}
		}
	}
	printf("Array D : \n");
	for(i=0;i<N;i++)
	{
		printf("%d ",d[i]);
	}
	printf("\n");
	printf("Array E : \n");
	for(i=0;i<N;i++)
	{
		printf("%d ",e[i]);
	}
	printf("\n");
	double end=omp_get_wtime();
	printf("Total Time : %lf seconds\n",(end-start));
	return 0;
}

/* Yes there a slight performance gain in the program by using the 
parallelization. The gain can be noticed in the Time taken.
Eg:- Time taken(Serial Program)=0.0159 seconds
     Time taken(Parallel without nowait)=0.0143 seconds
*/