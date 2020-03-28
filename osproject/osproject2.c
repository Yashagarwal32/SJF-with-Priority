#include<stdio.h>
#include<conio.h>
int main()
{
  
  int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%d",&n ); 
  double burstTime[n],process[n],temp;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &burstTime[i]);
	process[i]=i+1;

  }


  printf("\n\n\t\t\t-------- Sorting Processes according to Burst Time --------\n");

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

}



  
