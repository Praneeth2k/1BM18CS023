#include<stdio.h>
void waitingtime(int b[],int wt[],int n)
{
    int i;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+b[i-1];
    }
}
void tatime(int b[],int tat[],int n)
{
    int i;
    tat[0]=b[0];
    for(i=1;i<n;i++)
        tat[i]=b[i]+tat[i-1];
}
void print(int proces[],int burst[],int n)
{
    int i;
    int wt_time[20],tat[20];
    waitingtime(burst,wt_time,n);
    tatime(burst,tat,n);
    printf("Watintg time and turn around times are\n");
    printf("Process_id      Burst time     Waiting time       Turn around time\n");
    for(i=0;i<n;i++)
    {
    printf(    "%d                  %d               %d                   %d\n",proces[i],burst[i],wt_time[i],tat[i]);
    }
    float wait_sum=0,tat_sum=0;
    for(i=0;i<n;i++)
    {
        wait_sum+=wt_time[i];
        tat_sum+=tat[i];
    }
    float wait_avg=wait_sum/n;
    float tat_avg=tat_sum/n;
    printf("The average waiting time is = %f\n",wait_avg);
    printf("The average turnaround time is = %f",tat_avg);
   
}

void main()
{   
    int i,n;
    
    int process[20];
    int burst[20];
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter the ids of the processes one by one: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&process[i]);
    }

    printf("Enter their respective brust times: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&burst[i]);
    }
    print(process,burst,n);
    
    
}
