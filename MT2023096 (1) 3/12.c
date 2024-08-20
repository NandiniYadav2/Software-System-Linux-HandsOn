/*
============================================================================
Name : 12.c
Author : Nandini Yadav
Description : Write a program to find out the opening mode of a file. Use fcntl
Date: 4th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){


  char file[50] = "employee.txt";
  int fd = open(file,O_WRONLY | O_APPEND);
  if(fd == -1){
   perror("error opening file");
   return 1;
  }
  
  int mode = fcntl(fd,F_GETFL);
  
  if(mode == -1){
   perror("error getting file status flags");
   return 1;
  }
  if(mode & O_RDONLY){
  printf("the file is opened in read only mode.\n");
  
  }
  else if(mode & O_WRONLY){
  printf("the file is opened in write only mode.\n");
  
  }
  else if(mode & O_RDWR){
  printf("the file is opened in read - write mode.\n");
  
  }
  else{
    printf("the file is opened in unknown mode.\n");
  }
  
  int fd_close = close(fd);
 if(fd_close == -1){
   perror("error closing file");
   return 1;
  }


 return 0;
}
