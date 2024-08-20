/*
============================================================================
Name : 20.c
Author : Nandini Yadav
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 4th Sep, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>

#include<stdlib.h>

int main(){

  int nice_value;
  int pid = getpid();
  
  nice_value = getpriority(PRIO_PROCESS,0);
  if(nice_value == -1){
     perror("error getting nice value\n");
     return 1;
  }
  
  printf("current priority  : %d\n",nice_value);
  
  if(nice(10) == -1){
   perror("error setting nice value");
   return 1;
  }
  
  nice_value = getpriority(PRIO_PROCESS,0);
  printf("new priority :%d\n",nice_value);
  
  return 0;
}
