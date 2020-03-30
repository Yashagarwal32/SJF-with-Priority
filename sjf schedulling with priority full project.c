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
  float b_time = arrivalTime[0];
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
  
  
  
  
  // ==================================================turn around section and waiting section===================================
waitingTime[0]=0.0;

completionTime[0]=arrivalTime[0]+burstTime[0];
turnaroundTime[0]=completionTime[0]-arrivalTime[0];
waitingTime[0]=turnaroundTime[0]-burstTime[0];
for(i=1;i<n;i++)
{
	if(arrivalTime[i]>completionTime[i-1])
	{
		completionTime[i]=arrivalTime[i]+burstTime[i];
	}
	else
	{
	
	completionTime[i]=completionTime[i-1]+burstTime[i];
	
}
	turnaroundTime[i]=completionTime[i]-arrivalTime[i];
	waitingTime[i]=turnaroundTime[i]-burstTime[i];
	if(waitingTime[i]<0)
	{
		waitingTime[i]=0;
	}
}


  printf("\n\n\t\t\t-------- Processes sorted by Shorted job First --------\n\n");
  printf(" \n");
  printf("Process	    Arrival Time	Burst Time	  Completion Time    Waiting Time   Turnaround Time\n");
  printf("\n\n");
for(i=0;i<n;i++)
  {
    printf("P[%0.0lf]              %0.0lf               %0.0lf                 %0.0lf                  %0.01f                %0.01f \n",process[i],arrivalTime[i],burstTime[i],completionTime[i],waitingTime[i],turnaroundTime[i]);
  }
  for(i=0;i<n;i++)
  {
  	priority[i]=1+waitingTime[i]/burstTime[i];
  	//printf("%f\n",priority[i]);
  }

float avg_turnaround1,avg_waiting1;
 
  for(i=0;i<n;i++)
  {
  	sum=sum+turnaroundTime[i];
  }
  avg_turnaround1=sum;
  for(i=0;i<n;i++)
  {
  	sum2=sum2+waitingTime[i];
  }
  avg_waiting1=sum2;

float flag2;
if(arrivalTime[1]<=completionTime[0])
{
	for(i=1;i<n;i++)
	{
		flag2=priority[i];
		for(j=i;j<n;j++)
		{
			//printf("\n%f",completionTime[i-1]);
			if(arrivalTime[j]<=completionTime[i-1])
			{
				//printf("\nar %f",arrivalTime[j]);
				if(priority[j]>flag2)
				{
					flag2=priority[j];
					temp = burstTime[j];
			        burstTime[j] = burstTime[i];
			        burstTime [i] = temp;
				
				    temp = process[j];
			        process[j] = process[i];
			        process[i] = temp;  
					
					temp = arrivalTime[j];
			        arrivalTime[j] = arrivalTime[i];
			        arrivalTime[i] = temp;   
			        
			        		
					temp = priority[j];
			        priority[j] = priority[i];
			        priority[i] = temp; 
			        
								
				}
				if(priority[j]==flag2 && burstTime[j]<=burstTime[i])
				{
										flag2=priority[j];
					temp = burstTime[j];
			        burstTime[j] = burstTime[i];
			        burstTime [i] = temp;
				
				    temp = process[j];
			        process[j] = process[i];
			        process[i] = temp;  
					
					temp = arrivalTime[j];
			        arrivalTime[j] = arrivalTime[i];
			        arrivalTime[i] = temp;   
			        
			        		
					temp = priority[j];
			        priority[j] = priority[i];
			        priority[i] = temp;
					
				}
			}
		}
		completionTime[i]=completionTime[i-1]+burstTime[i];
	}
}

 waitingTime[0]=0.0;

completionTime[0]=arrivalTime[0]+burstTime[0];
turnaroundTime[0]=completionTime[0]-arrivalTime[0];
waitingTime[0]=turnaroundTime[0]-burstTime[0];
for(i=1;i<n;i++)
{
	if(arrivalTime[i]>completionTime[i-1])
	{
		completionTime[i]=arrivalTime[i]+burstTime[i];
	}
	else
	{
	
	completionTime[i]=completionTime[i-1]+burstTime[i];
	
}
	turnaroundTime[i]=completionTime[i]-arrivalTime[i];
	waitingTime[i]=turnaroundTime[i]-burstTime[i];
	if(waitingTime[i]<0)
	{
		waitingTime[i]=0;
	}
}

  printf("\t\t\t\t\n                           Average waiting Time : %1.2f",avg_waiting1/n);
  printf("\t\t\t\t\n                         Average turnaround Time : %1.2f",avg_turnaround1/n);
  printf("\n\n\n\n\t\t\t-------- Processes sorted by Shorted job First with Priority --------\n\n");
  printf(" \n");
  printf("Process	    Arrival Time	Burst Time	  Completion Time    Waiting Time   Turnaround Time\n");
  printf("\n\n");
for(i=0;i<n;i++)
  {
    printf("P[%0.0lf]              %0.0lf               %0.0lf                 %0.0lf                  %0.01f                %0.01f \n",process[i],arrivalTime[i],burstTime[i],completionTime[i],waitingTime[i],turnaroundTime[i]);
  }
  sum=0;
  sum2=0;
  //avg_waiting=0;
  //avg_turnaround=0;
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

