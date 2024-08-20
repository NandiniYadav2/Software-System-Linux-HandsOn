/*
============================================================================
Name : 17b.c
Author : Nandini Yadav
Description : Write a program to execute ls -l | wc.
b. use dup2
Date: 14th oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

int fd[2];
int pfd =pipe(fd);
if(pfd ==-1){
 perror("pipe");
 return 1;
}

int pid = fork();
if(pid==-1){
    perror("fork:");
    return 1;
    }

if(pid==0){
  
  close(fd[0]);/*because it doesn't need to read from the pipe. It only writes data into the pipe*/
  
  int d = dup2(fd[1],STDOUT_FILENO);
  if(d ==-1){
    perror("dup2:");
    return 1;
    }
  close(fd[1]);
  
  int e = execlp("ls","ls","-l",NULL);
  if(e ==-1){
    perror("execlp:");
    return 1;
    }
}
else{
 
 close(fd[1]);
 int d = dup2(fd[0],STDIN_FILENO);
 if(d==-1){
    perror("dup:");
    return 1;
    }
   close(fd[0]);
   
   int e = execlp("wc","wc",NULL);
   if(e ==-1){
    perror("execlp:");
    return 1;
    } 



}

 return 0;
}   
   
