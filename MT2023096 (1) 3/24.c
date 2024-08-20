/*
============================================================================
Name : 24.c
Author : Nandini Yadav
Description : write a program to create an orphan process

Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
 
 
 int main(){
 
 int pid;
 if((pid = fork())==-1){
   perror("fork");
   exit(EXIT_FAILURE);
 }
  
  if(pid==0){
    
    printf("child process id is :%d\nparent process id is:%d\n",getpid(),getppid());
    sleep(180);
    printf("child process id is :%d\nparent process id is:%d\n",getpid(),getppid());
    printf("now child process is completed.\n");
  }
  else{
    printf("parent process id:%d\nparent is exiting ....\n",getpid());
    exit(0); 
  }
  return 0;
 }
