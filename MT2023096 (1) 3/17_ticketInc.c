/*
============================================================================
Name : 17_ticketInc.c
Author : Nandini Yadav
Description : Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

 int fd = open("ticket.txt",O_RDWR);
 if(fd==-1){
    perror("error in opening file descriptor");
    return 1;
  
  }
 
 printf("Want to book ticket PRESS ENTER :\n ");
 getchar();
 

 struct flock lock;
 lock.l_type = F_WRLCK;
 lock.l_start = 0;
 lock.l_whence = SEEK_SET;
 lock.l_len = 0;
 fcntl(fd,F_SETLKW,&lock);
 
 
 int tcktNo;
 read(fd,&tcktNo,sizeof(tcktNo));
 
 tcktNo++;
 
 printf("Ticket is booked.\nYour Ticket No is : %d\n",tcktNo);
 
 lseek(fd,0,SEEK_SET);
 write(fd,&tcktNo,sizeof(tcktNo));
 
 lock.l_type = F_UNLCK;
 fcntl(fd,F_SETLK,&lock);
 int fd_close = close(fd);
 if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
 printf("Finish.\n");
 

 return 0;
}
