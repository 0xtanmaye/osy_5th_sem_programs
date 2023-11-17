#include<stdio.h>

struct Process
{
	int processID;
	int arrivalTime;
	int burstTime;
	int waitingTime;
	int turnaroundTime;
};

void calculateTimes(struct Process processes[], int n)
{
	int totalWaitingTime = 0;
	int totalTurnaroundTime = 0;

	processes[0].waitingTime = 0;

	for (int i = 1; i < n; i++) {
		processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
	}

	for (int i = 0; i < n; i++) {
		processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
		totalWaitingTime += processes[i].waitingTime;
		totalTurnaroundTime += processes[i].turnaroundTime;
	}

	double averageWaitingTime = (double)totalWaitingTime / n;
	double averageTurnaroundTime = (double)totalTurnaroundTime / n;

	printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
	}
	printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
	printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main()
{
	int n;

	printf("Enter the number of processes: ");
	scanf("%d", &n);

	struct Process processes[n];

	for (int i = 0; i < n; i++) {
		processes[i].processID = i + 1;
		printf("Enter arrival time for process %d: ", i + 1);
		scanf("%d", &processes[i].arrivalTime);
		printf("Enter burst time for process %d: ", i + 1);
		scanf("%d", &processes[i].burstTime);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
				struct Process temp = processes[j];
				processes[j] = processes[j + 1];
				processes[j + 1] = temp;
			}
		}
	}

	calculateTimes(processes, n);
	return 0;
}
