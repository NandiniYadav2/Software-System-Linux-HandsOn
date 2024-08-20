/*
============================================================================
Name : 19.c
Author : Nandini Yadav
Description :  . Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 17th oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<errno.h>
#define FIFO_PERMISSIONS 0666

int main(){
 
  int mk = mknod("FIFO1",S_IFIFO,0);
  int mfifo = mkfifo("FIFO2",FIFO_PERMISSIONS);
 
 if(mk==-1){
  perror("mknod:");
  return 1;
 }
 
  if(mfifo==-1){
  perror("mkfifo:");
  return 1;
 }
   
    
   return 0;
}
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
  
