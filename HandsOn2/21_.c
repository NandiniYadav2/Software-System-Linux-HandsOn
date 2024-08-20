/*
============================================================================
Name : 21.c
Author : Nandini Yadav
Description:Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 17th oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>

int main(){
  
  int fd = open("FIFO",O_RDWR);
  
  char buff1[100];
  char buff2[100];
  
  int byte_rd = read(fd,buff1,sizeof(buff1));
  if(byte_rd==-1){
    perror("read:");
    return 1;
  }
  //buff1[byte_rd]='\0';
  
  printf("message received from program 1 :%s\n",buff1);
  
  
  printf("what you want to write:\n");
  int b = read(0,buff2,sizeof(buff2));
  buff2[b]='\0';
  
  int byte_wr = write(fd,buff2,sizeof(buff2));
  if(byte_wr==-1){
    perror("write:");
    return 1;
  }
  
  int cfd=close(fd);
  if(cfd==-1){
    perror("close:");
    return 1;
  }
  
  
  return 0;
}
