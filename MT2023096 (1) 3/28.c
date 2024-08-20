/*
============================================================================
Name : 28.c
Author : Nandini Yadav
Description: . Write a program to get maximum and minimum real time priority.
Date: 4th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority = sched_get_priority_max(SCHED_FIFO);
    int min_priority = sched_get_priority_min(SCHED_FIFO);

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
