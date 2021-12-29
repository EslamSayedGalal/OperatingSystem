// CPU-Scheduling-Algorithm-In-C
// Shortest Job First(SJF) Scheduling Algorithm(Non Pre-emptive)

#include<stdio.h>
#include<malloc.h>

void main()
{
    int n, i, j, pos, temp, * burst, * waiting, * Turnaround, * process, *arrival, * readyArray;
    float average_wt = 0, average_tat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    process = (int*)malloc(n * sizeof(int));
    burst = (int*)malloc(n * sizeof(int));
    waiting = (int*)malloc(n * sizeof(int));
    Turnaround = (int*)malloc(n * sizeof(int));
    arrival = (int*)malloc(n * sizeof(int));
    readyArray = (int*)malloc(n * sizeof(int));

    printf("\n Enter the burst time for each process \n");
    for (i = 0; i < n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &burst[i]);
        printf(" Arrival time for P%d : ", i);
        scanf("%d", &arrival[i]);
        process[i] = i;
    }
    // sort arrival time
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arrival[j] < arrival[pos])
            {
                pos = j;
            }
        }
        // arival time
        temp = arrival[i];
        arrival[i] = arrival[pos];
        arrival[pos] = temp;
        // burst time
        temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;
        // process
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    int totalTime = 0;
    waiting[0] = 0;
    Turnaround[0] = burst[0];
    totalTime = burst[0];
    average_wt += waiting[0];
    average_tat += Turnaround[0];
    int counter = 0;
    int counter2 = 1;
    for (; counter2 < n; )
    {
        //fill readyArray
        for (i = counter2; i < n; i++)
        {
            if (arrival[i] <= totalTime) {
                readyArray[counter] = i;
                counter++;
                counter2 = i+1;
            }
        }
        
        // sort readyArray index
        for (i = 0; i < counter; i++)
        {
            pos = i;
            for (j = i + 1; j < counter; j++)
            {
                if (burst[readyArray[j]] < burst[readyArray[pos]])
                {
                    readyArray[pos] = readyArray[j];
                }
            }
            temp = readyArray[i];
            readyArray[i] = readyArray[pos];
            readyArray[pos] = temp;
        }
        // calc wt tat
        for (i = 0 ; i < counter; i++)
        {
            waiting[readyArray[i]] = totalTime - arrival[readyArray[i]];
            totalTime += burst[readyArray[i]];
            Turnaround[readyArray[i]] = waiting[readyArray[i]] + burst[readyArray[i]];
            average_wt += waiting[readyArray[i]];
            average_tat += Turnaround[readyArray[i]];
        }
        counter = 0;
    }
    average_wt = average_wt / n;
    average_tat = average_tat / n;
    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", average_wt, average_tat);
}