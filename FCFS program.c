#include <stdio.h>

// Function to calculate average waiting time and average turnaround time
void findAvgTime(int processes[], int n, int burstTime[]) {
    int waitingTime[n], turnaroundTime[n];

    // First process has 0 waiting time
    waitingTime[0] = 0;

    // Calculating waiting time
    for (int i = 1; i < n; i++)
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];

    // Calculating turnaround time by adding burst time and waiting time
    for (int i = 0; i < n; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];

    // Calculating average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime /= n;
avgTurnaroundTime /= n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Printing details of each process
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], waitingTime[i], turnaroundTime[i]);

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
}

int main() {
    int n;

printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burstTime[i]);
    }

    findAvgTime(NULL, n, burstTime);
  return 0;
}
