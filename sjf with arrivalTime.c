#include<stdio.h>
#include<conio.h>
int main()
{
  
  int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%d",&n ); 
  float burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp,min;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%f", &burstTime[i]);
    printf("\nEnter Arrival Time for Process [%d] : ", i+1 );
    scanf("%f", &arrivalTime[i]);
    
	process[i]=i+1;

  }


  printf("\n\n\t\t\t-------- Processes sorted by Arrival Time --------\n\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {
        
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	    temp = process[j];
        process[j] = process[i];
        process[i] = temp;  
		
		temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;   
      }
      if(arrivalTime[i]==arrivalTime[j])
      {
      	if(burstTime[i]<=burstTime[j])
      	{
      		 temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	    temp = process[j];
        process[j] = process[i];
        process[i] = temp;  
		
		temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;
		  }
	  }
      
    }
  }


  printf("\t\t\t Process	Arrival Time	Burst Time \n");
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]            %0.0lf                 %0.0lf    \n",process[i],arrivalTime[i],burstTime[i]);
  }
    printf("\n");



  
  
  
  int k = 1;
  float b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];
    for(i=k;i<n;i++)
    {	
      
      	
      	
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
      {

      	min=burstTime[i];
        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
        
        
      }
    }
    k++;
  }
  
  
  
  
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

  printf("\n\n\t\t\t-------- Processes sorted by Shorted job First --------\n\n");
  printf(" \n");
  printf("\t\t\t Process	Arrival Time	Burst Time	Waiting Time	turnaround Time\n");
  printf("\n\n");
for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]            %0.0lf                %0.0lf                %0.01f                %0.01f \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
}

