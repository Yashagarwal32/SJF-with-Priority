#include<stdio.h>
#include<conio.h>
int main()
{
  
  int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%d",&n ); 
  float burstTime[n],waitingTime[n],turnaroundTime[n], process[n], temp;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%f", &burstTime[i]);
	process[i]=i+1;

  }


  printf("\n\n\t\t\t-------- Sorting Processes according to Burst Time --------\n\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(burstTime[i]<burstTime[j])
      {
        
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;     
      }
    }
  }


  printf("\t\t\t Process  Burst Time \n");
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf    \n",process[i],burstTime[i]);
  }
    printf("\n");
// ==================================================waiting time section===================================
waitingTime[0]=0.0;
for(i=0;i<n;i++)
  {
  	float flag=0;
    for(j=i-1;j>-1;j--)
    {
    	flag=flag+burstTime[j];	
	}
    waitingTime[i]=flag;
  }


//===================================================turn around time section================================  
for(i=0;i<n;i++)
{
	turnaroundTime[i]=waitingTime[i]+burstTime[i];
}

  printf(" \n\n");
  printf("\t\t\t Process  Burst Time  Waiting Time  turnaround Time\n");
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf      %0.01f          %0.01f \n",process[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
}

