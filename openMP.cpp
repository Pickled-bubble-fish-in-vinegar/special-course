#include<iostream>
#include<omp.h>
#include<time.h>
#include<stdlib.h>

#define size_mb 1048576

using namespace std;

int main(int argc,char **argv)
{
	int n=atoi(argv[1]);
	
	long int cached_array_size=size_mb*n/4;
	long int large_array_size=size_mb*1024/4;

	int *ptrs=new int[large_array_size];
	int *result=new int[large_array_size];
	int *data=new int[cached_array_size];

	for(int i=0;i<cached_array_size;i++)
	{
		data[i]=i;
	}

	for(int i=0;i<large_array_size;i++)
	{
		result[i]=0;
		ptrs[i]=rand()%cached_array_size;
	}
	

	double start=omp_get_wtime();

	#pragma omp parallel
	{
		#pragma omp for
		for(int i=0;i<large_array_size;i++)
		{
			result[i]=data[ptrs[i]];
		}
	}
	
	double finish=omp_get_wtime();
	double total_t=(finish-start);
	cout<<"Used time is:"<<total_t<<endl;
	
	FILE *time_dat=fopen("time_dat.dat","a");
	fprintf(time_dat,"%d %f\n",n,total_t);



	delete(ptrs);
	delete(result);
	delete(data);
	return 0;
}
