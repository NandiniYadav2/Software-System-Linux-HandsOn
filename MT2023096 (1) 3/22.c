
/*
============================================================================
Name : 22.c
Author : Nandini Yadav
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>


int main(){

 int fd = open("db.txt",O_RDWR);
 
 
 if(fd==-1){
  perror("error opening file\n");
  return 1;
 }
 
 int pid;
 if((pid = fork()) == -1){
  perror("fork");
  exit(EXIT_FAILURE);
 
 }
 
 if(pid==0){
  write(fd,"this is written by child\n",strlen("this is written by child "));
  exit(EXIT_SUCCESS);
 }
 else{
  write(fd,"this is written by parent\n",strlen("this is written by parent "));
  wait(0);
  int fd_close = close(fd);
  if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
 }
 


 return 0;
} 


