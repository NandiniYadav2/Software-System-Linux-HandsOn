/*
============================================================================
Name : 15.c
Author : Nandini Yadav
Description :  Write a simple program to send some data from parent to the child process.
Date: 14th oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main(){

int fd[2];
int pfd = pipe(fd);
if(pfd==-1){
  perror("pipe");
  return 1;
}


int pid = fork();
if(pid==-1){
  perror("pipe");
  return 1;
}

int byte_wr;
char buf[100];
char buf_wr[]="hello child.....";

if(pid == 0){

 close(fd[1]);
 
 int byte_rd = read(fd[0],buf,sizeof(buf));
 if(byte_rd==-1){
    perror("pipe1");
    return 1;
  }
 close(fd[0]);
 
 printf("message recieved by child process: %s\n",buf);
 
}
else{
  
  close(fd[0]);
  
  byte_wr = write(fd[1],buf_wr,sizeof(buf_wr));
  if(byte_wr==-1){
    perror("pipe");
    return 1;
  }
  
  close(fd[1]);
  printf("message sent by parent.Done\n");
  
  wait(0);

}






 return 0;
}
