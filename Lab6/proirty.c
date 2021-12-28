

#include<stdio.h>
#include<malloc.h>
int main()
{
    int n, i, j, pos, temp, * burst, * waiting, * turnaround, * process, * priority, * arrival, * priorityArray;
    float average_wt = 0, average_tat = 0, totalTime = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    process = (int*)malloc(n * sizeof(int));     
    burst = (int*)malloc(n * sizeof(int));    
    priority = (int*)malloc(n * sizeof(int));    
    waiting = (int*)malloc(n * sizeof(int));    
    turnaround = (int*)malloc(n * sizeof(int));   
    arrival = (int*)malloc(n * sizeof(int)); 
    priorityArray = (int*)malloc(n * sizeof(int));
    
    printf("\n Enter the burst time and priority for each process ");
    for (i = 0; i < n; i++)
    {
        printf("\n Burst time of P%d : ", i);
        scanf("%d", &burst[i]);
        printf(" Priority of P%d : ", i);
        scanf("%d", &priority[i]);
        printf(" Arrival Time of P%d : ", i);
        scanf("%d", &arrival[i]);
        process[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            // pos = i first
            // j second
            if (arrival[j] < arrival[pos])
            {
                pos = j;
            }
        }
        // priorityTime
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;
         
        // burstTime
        temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;

        // process
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;

        // arrivalTime
        temp = arrival[i];
        arrival[i] = arrival[pos];
        arrival[pos] = temp;
    }

    waiting[0] = 0;
    turnaround[0] = burst[0];
    totalTime = burst[0];

    average_wt += waiting[0];
    average_tat += turnaround[0];
    j = 0;
    int stop = 1;
    for (i = 1; i < n; i++)
    {

        stop = i;
        j = 0;
        // array of arrival index
        for (; stop < n; stop++)
        {
            if (arrival[stop] <= totalTime) {
                priorityArray[j] = stop;
                j++;
            }
        }
        i += j - 1;
        int cou = 0, cou2 = 0;
        for (; cou < j; cou++)
        {
            pos = cou;
            for (cou2 = cou + 1; cou2 < j; cou2++)
            {
                // pos = cou first
                // cou2 second
                if (priority[priorityArray[cou2]] < priority[priorityArray[pos]])
                {
                    pos = cou2;
                }
            }
            // priorityTime
            temp = priorityArray[cou];
            priorityArray[cou] = priorityArray[pos];
            priorityArray[pos] = temp;
        }
        
        for (cou = 0; cou < j; cou++)
        {
            waiting[priorityArray[cou]] = totalTime - arrival[priorityArray[cou]];
            totalTime += burst[priorityArray[cou]];
            turnaround[priorityArray[cou]] = waiting[priorityArray[cou]] + burst[priorityArray[cou]];
            average_wt += waiting[priorityArray[cou]];
            average_tat += turnaround[priorityArray[cou]];
        }
    }

    average_wt = average_wt / n;
    average_tat = average_tat / n;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", average_wt, average_tat);

    printf("\n PROCESS \t PRIORITY \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", process[i], priority[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", average_wt, average_tat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", waiting[i], process[i], turnaround[i]);
    }
}