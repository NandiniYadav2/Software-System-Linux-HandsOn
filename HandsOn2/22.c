/*
============================================================================
Name : 22.c
Author : Nandini Yadav
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){

   
   int fd = open("FIFO",O_RDWR);
   if(fd==-1){
     perror("open:");
     return 1;
   }

  fd_set rfds;
  struct timeval timeout;
  int result;
  FD_ZERO(&rfds);
  
  FD_SET(fd,&rfds);
  timeout.tv_sec=20;
  timeout.tv_usec=0;
  
  printf("waiting for input for upto 10 sec..\n");
  
  result = select(fd+1,&rfds,NULL,NULL,&timeout);
  
  if(result == -1){
     perror("select");
     return -1;
  }
  else if(result==0){
      printf("input is not available\n");
  }
  else{
    
    
     if(FD_ISSET(fd,&rfds)){
     char buff[100];
     int byte_rd = read(fd,buff,sizeof(buff));
    
      if(byte_rd == -1) {
           perror("read");
           return 1;
       }
       
       buff[byte_rd]='\0';
  
       printf("input is available : %s\n",buff);
     }
  }

  close(fd);


return 0;
}
