/*
============================================================================
Name : 13.c
Author : Nandini Yadav
Description :  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 4th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

int main(){

  fd_set rfds;
  struct timeval timeout;
  int result;
  FD_ZERO(&rfds);
  FD_SET(0,&rfds);
  timeout.tv_sec=10;
  timeout.tv_usec=0;
  
  printf("waiting for input for upto 10 sec..\n");
  
  result = select(1,&rfds,NULL,NULL,&timeout);
  
  if(result == -1){
     perror("select");
     return -1;
  }
  else if(result){
     printf("input is available\n");
  }
  else{
    
     printf("input is not available\n");
  }




return 0;
}
