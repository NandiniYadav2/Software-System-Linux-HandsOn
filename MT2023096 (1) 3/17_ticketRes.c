/*
============================================================================
Name : 17_ticketRes.c
Author : Nandini Yadav
Description : Write a program to simulate online ticket reservation. Implement write lock Write a program to open a file, store a ticket number and exit.
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

  int tcktNo;
  printf("Enter initial ticket no: \n");
  scanf("%d",&tcktNo);
  
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_start = 0;
  lock.l_whence = SEEK_SET;
  lock.l_len = 0;
  
  int fd = open("ticket.txt",O_RDWR | O_CREAT , 0666); 
  if(fd == -1){
    perror("Error in opening file.\n");
    return 1;
  }
  
  
  fcntl(fd,F_SETLKW,&lock);
  
  
  lseek(fd,0,SEEK_SET);
  write(fd,&tcktNo,sizeof(tcktNo));
  fsync(fd);
  
  lock.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&lock);
  int fd_close = close(fd);
  if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
  printf("Ticket reserved : %d\n" ,tcktNo);
  
  return 0;
}
