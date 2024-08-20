/*
============================================================================
Name : 20_.c
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

int main(){

  int fd = open("FIFO",O_RDONLY);
  char buff[1024];
  int byte_rd = read(fd,buff,sizeof(buff));
  
  if(byte_rd==-1){
   perror("read:");
   return 1;
  }
  
  printf("message received:%s\n",buff);
  
  int cd = close(fd);
  if(cd==-1){
    perror("close:");
    return 1;
  }
  

  return 0;
}
