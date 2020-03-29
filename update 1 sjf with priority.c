#include<stdio.h>
#include<conio.h>
int main()
{
  
  int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%d",&n ); 
  if(n<=0)
  {
  	printf("No of Processes should be greater than 0.");
  	return 0;
  }
  float priority[n],avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%f", &burstTime[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%f", &arrivalTime[i]);
    
	process[i]=i+1;
	if(burstTime[i]<0 || arrivalTime[i]<0)
	{
		printf("Time cannot be negative");
		return 0;
	}

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
    waitingTime[i]=arrivalTime[0]+flag-arrivalTime[i];
    if(waitingTime[i]<0)
    {
    	waitingTime[i]=0;
	}
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
  for(i=0;i<n;i++)
  {
  	priority[i]=1+waitingTime[i]/burstTime[i];
  	//printf("%f\n",priority[i]);
  }
  
for(i=0;i<n;i++)
  {
for(j=0;j<n;j++)
    {
      if(priority[i]<priority[j])
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
        
	
	    temp = turnaroundTime[j];
        turnaroundTime[j] = turnaroundTime[i];
        turnaroundTime[i] = temp;  
		
		temp = waitingTime[j];
        waitingTime[j] = waitingTime[i];
        waitingTime[i] = temp;  
		
		temp = priority[j];
        priority[j] = priority[i];
        priority[i] = temp; 
        
                
      }
  }
}
  printf("\n\n\t\t\t-------- Processes sorted by Shorted job First with Priority --------\n\n");
  printf(" \n");
  printf("\t\t\t Process	Arrival Time	Burst Time	Waiting Time	turnaround Time\n");
  printf("\n\n");
for(i=n-1;i>=0;i--)
  {
    printf("\t\t\t  P[%0.0lf]            %0.0lf                %0.0lf                %0.01f                %0.01f   \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
  
  for(i=0;i<n;i++)
  {
  	sum=sum+turnaroundTime[i];
  }
  avg_turnaround=sum;
  for(i=0;i<n;i++)
  {
  	sum2=sum2+waitingTime[i];
  }
  avg_waiting=sum2;
  printf("\t\t\t\t\n                           Average waiting Time : %1.2f",avg_waiting/n);
  printf("\t\t\t\t\n                           Average turnaround Time : %1.2f",avg_turnaround/n);
    
}

