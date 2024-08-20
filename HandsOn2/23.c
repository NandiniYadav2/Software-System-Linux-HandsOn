/*
============================================================================
Name : 23.c
Author : Nandini Yadav
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 19th oct, 2023.
============================================================================
hint:
man sysconf-> get configuration info at run time

*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>

int main(){

long max = sysconf(_SC_OPEN_MAX);
 if(max==-1){
   perror("sysconf:");
   return 1;
 }
 
 printf("max no of files can be opened within a process is:%ld\n",max);
 
 int fd[2];
 
 int pfd = pipe(fd);
 if(pfd==-1){
   perror("pipe:");
   return 1;
 
 }
 
 int size = 0;
 
    const char data = 'A'; 

    while (write(fd[1], &data, 1) == 1) {
        size++;
    }

    
    close(fd[1]);

 
 printf("Size of the pipe (circular buffer): %d bytes\n",size);
 
 

 return 0;
}
