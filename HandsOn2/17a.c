/*
============================================================================
Name : 17a.c
Author : Nandini Yadav
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl 
Date: 14th oct, 2023.
============================================================================
*/
   
   

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main(){
 
 int fd[2];

 int pfd = pipe(fd);
 if(pfd==-1){
  perror("pipe1");
  return 1; 
 }
 
 
int pid=fork();
 
 if(pid==0){
   
   close(1);
   int d = dup(fd[1]); /*return new desc.-- instead of go to the stdoutput it will go to the write end of the pipe fd[1]*/
   if(d==-1){
    perror("dup:");
    return 1;
    }
   
   close(fd[1]);
   
   int e = execlp("ls","ls","-l",NULL);
   if(e==-1){
      perror("exec1");
     return 1;
 }
 }
 else{
  close(0);
  int d = dup(fd[0]);
  if(d==-1){
    perror("dup:");
    return 1;
    }
  close(fd[1]);
  
 int a = execlp("wc" ,"wc",NULL);
 if(a==-1){
 perror("exec2");
 return 1;
 }
 
 }
 
 


 return 0;
}
