/*
============================================================================
Name : 20.c
Author : Nandini Yadav
Description :  Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 17th oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#define FIFO_PERMISSIONS 0666

int main(){

/*
int mk = mkfifo("FIFO",FIFO_PERMISSIONS);

if(mk==-1){
  perror("fifo:");
  return 1;
}
*/
int fd = open("FIFO",O_WRONLY);
if(fd==-1){
 perror("open:");
 return 1;
}

char buff[1024];
printf("what you want to write :\n");
read(0,buff,sizeof(buff));

int byte_wr = write(fd,buff,sizeof(buff));
if(byte_wr==-1){
  perror("write");
  return 1;
}

int cd = close(fd);

if(cd==-1){
 perror("close:");
 return 1;
}

 return 0;
}
