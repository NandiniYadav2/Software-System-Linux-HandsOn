/*
============================================================================
Name : 18.c
Author : Nandini Yadav
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
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
 int fd2[2];
 
 int pfd = pipe(fd);
 
 if(pfd==-1){
   perror("pipe1:");
   return 1;
 }
 
 pfd = pipe(fd2);
   if(pfd==-1){
   perror("pipe2:");
   return 1;
 }
 
 int pid = fork();
 if(pid==-1){
   perror("fork1:");
   return 1;
 }
 if(pid==0){
  
      close(fd[0]);
      dup2(fd[1],STDOUT_FILENO);
      close(fd[1]);
      
      execlp("ls","ls","-l",NULL);
      perror("execlp1:");
      
    
    }
    /*else{
     wait(0);
    }*/
    
    int p1 = fork();
    if(p1==-1){
     perror("fork2:");
     return 1;
   }
    if(p1==0){
    close(fd[1]);
    dup2(fd[0],STDIN_FILENO);
    close(fd[0]);
    
    close(fd2[0]);
    dup2(fd2[1],STDOUT_FILENO);
    close(fd2[1]);
    execlp("grep","grep","^d",NULL);
    perror("execlp2:");
  
  }
  /*else{
   wait(0);
  }*/
  
  close(fd[0]);
  close(fd[1]);
  
  int p2 = fork();
  if(p2==-1){
   perror("fork3:");
   return 1;
  }
  if(p2==0){
  
   close(fd2[1]);
   dup2(fd2[0],STDIN_FILENO);
   close(fd2[0]);
   
   execlp("wc","wc",NULL);
   perror("execlp3:");
   
 }else{
   wait(0);
 
 }
 
 
 
 
  
 return 0;
}





