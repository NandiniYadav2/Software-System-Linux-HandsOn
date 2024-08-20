/*
============================================================================
Name : 14.c
Author : Nandini Yadav
Description :  Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor
Date: 14th oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){

int fd[2];
int pfd = pipe(fd);
if(pfd == -1){
  perror("pipe");
  return 1;
}

char buf_wr[100]="hello write end ..";

int byte_wr = write(fd[1],buf_wr,sizeof(buf_wr));
printf("data is written from write end of the pipe\n");

if(byte_wr == -1){
 perror("pipe");
 return 0;
 }
int  close_fd = close(fd[1]);
if(close_fd==-1){
  perror("pipe");
  return 1;
}
 
 char buf[100];
 
 int byte_rd = read(fd[0],buf,byte_wr);
 printf("%s\n",buf);
 
 if(byte_rd==-1){
   perror("pipe");
   return 1;
 }
 
 close_fd = close(fd[0]);
 if(close_fd==-1){
  perror("pipe");
  return 1;
}

return 0;
}
 
 
