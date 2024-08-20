/*
============================================================================
Name : 10.c
Author : Nandini Yadav
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.  
(a) check the return value of lseek
(b) open the file with od and check the empty spaces in between the data.
Date: 4th Sep, 2023.
============================================================================
*/
  
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

  char file[20]="employee.txt";
  char buf[20] = "abcdefghijklmnopqr";
  char buff2[20] = "zyxwvutsABCDEF";
  
  int fd = open(file,O_RDWR);
  
  if(fd == -1){
 
    perror("error in opening file");
    return 1;
  }
  
   
  
  int bytes_write = write(fd,buf,10);
  
  if(bytes_write == -1){
     perror("error in writing");
     close(fd);
    return 1;
  }
  
 // lseek(fd, 0, SEEK_SET);  Start of file      lseek(fd, 0, SEEK_END);    Next byte after the end of file                          lseek(fd, -1, SEEK_END);     Last byte of file    lseek(fd, -10, SEEK_CUR);  Ten bytes prior to current location                 lseek(fd, 10000, SEEK_END);  10001 bytes past last byte of file                                                              Calling lseek() simply adjusts the kernel’s record of the file offset associated with a file descriptor. It does not cause any physical device access 

  
  if( lseek(fd,10,SEEK_CUR) == -1){
     perror("error in seeking");
     close(fd);
    return 1;
  }
  
  bytes_write = write(fd,buff2,10);
  
  if(bytes_write == -1){
     perror("error in writing");
     close(fd);
    return 1;
  }
  
  printf("lseek() returned offset: %ld\n",lseek(fd,0,SEEK_CUR));
  
  int fd_close = close(fd);
  if(fd_close == -1){
     perror("error in closing");
     return 1;
  }
  
  
return 0;
}
