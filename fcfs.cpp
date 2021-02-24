#include<stdio.h>

int main(void) {
	printf("**** I N P U T *****\n");
	int n;
	printf("Enter number of process: ");
	scanf("%d",&n);
	int process[n+1];
	for(int i=1;i<=n;i++)
	{
		printf("\nEnter the Burst Time of the process %d: ",i);
		scanf("%d",&process[i]);
	}
	printf("\nFIRST COME FIRST SERVE SCHEDULING\n");
	int waiting[n+1],turn[n+1];
	double avgwt=0,avgtat=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
		waiting[i]=0;
		turn[i]=process[i];
		}
		else
		{
			waiting[i]=waiting[i-1]+process[i-1];
			turn[i]=waiting[i]+process[i];
		}
		avgwt+=waiting[i];
		avgtat+=turn[i];
	}
	avgwt=avgwt/n;
	avgtat=avgtat/n;
	printf("Process ID   Waiting Time   Turn Around Time\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d             %d             %d\n",i,waiting[i],turn[i]);
	}
	printf("****OUTPUT****\n");
	printf("Average Waiting Time = %f ms\n",avgwt);
	printf("Average Turnaround Time = %f ms\n",avgtat);
	return 0;
}