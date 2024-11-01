#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int job_id;
    int service_time;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobA->service_time - jobB->service_time;
}

void sjf_scheduling(int jobs[], int service_times[], int num_jobs, double *avg_waiting_time, double *avg_turnaround_time) {
    Job *job_list = malloc(num_jobs * sizeof(Job));
    for (int i = 0; i < num_jobs; i++) {
        job_list[i].job_id = jobs[i];
        job_list[i].service_time = service_times[i];
    }

    // Sort jobs based on service time
    qsort(job_list, num_jobs, sizeof(Job), compare);
    
    int *waiting_time = malloc(num_jobs * sizeof(int));
    int *turnaround_time = malloc(num_jobs * sizeof(int));

    // Calculate waiting time
    waiting_time[0] = 0; // First job has no waiting time
    for (int i = 1; i < num_jobs; i++) {
        waiting_time[i] = waiting_time[i - 1] + job_list[i - 1].service_time;
    }

    // Calculate turnaround time
    for (int i = 0; i < num_jobs; i++) {
        turnaround_time[i] = waiting_time[i] + job_list[i].service_time;
    }

    // Calculate average waiting and turnaround times
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    for (int i = 0; i < num_jobs; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    *avg_waiting_time = total_waiting_time / num_jobs;
    *avg_turnaround_time = total_turnaround_time / num_jobs;

    // Clean up
    free(job_list);
    free(waiting_time);
    free(turnaround_time);
}

int main() {
    int jobs[] = {1, 2, 3, 4};
    int service_times[] = {3, 7, 4, 8};
    int num_jobs = sizeof(jobs) / sizeof(jobs[0]);

    double avg_waiting_time, avg_turnaround_time;
    sjf_scheduling(jobs, service_times, num_jobs, &avg_waiting_time, &avg_turnaround_time);

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
