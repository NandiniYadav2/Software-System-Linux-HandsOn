/*
============================================================================
Name : 23.c
Author : Nandini Yadav
Description :  Write a program to create a Zombie state of the running program.
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
    
    printf("this is child process pid: %d\n",getpid());
  }
  else{
    printf("this is parent process pid :%d\n",getpid());
    sleep(300); 
    printf("now parent process is completed.\n");
  }
  return 0;
 }
