/*
============================================================================
Name : 29.c
Author : Nandini Yadav
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 4th Sep, 2023.
============================================================================
*/

/* refer $ man sched_setscheduler*/
/*getting correct output by run as root using 'sudo' */

#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
 int pid = getpid();
 
 /*int sched_getscheduler(pid_t pid)  .. to get current scheduling policy*/
 
 int current_policy =sched_getscheduler(pid);
 if(current_policy == -1){
   perror("sched_getscheduler");
   exit(EXIT_FAILURE);
 
 }
 
printf("current scheduling policy: ");

switch(current_policy){
  case SCHED_FIFO:
      printf("SCHED_FIFO\n");
      break;
  case SCHED_RR:
      printf("SCHED_RR\n");
      break;
  case SCHED_OTHER:
      printf("SCHED_OTHER\n");
      break;
  default:
      printf("UNKNOWN\n");
      break;

}
 
struct sched_param params;
params.sched_priority =99;

int set_policy = sched_setscheduler(pid,SCHED_FIFO,&params);

if(set_policy==-1){
  perror("sched_setscheduler");
  exit(EXIT_FAILURE);
}

/*
int sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);

 The scheduling parameters are specified in the param argument, which is a pointer to a structure of the following form:

           struct sched_param {
               ...
               int sched_priority;
               ...
           };
*/



printf("New scheduling policy is : SCHED_FIFO\n");

 return 0;
}


