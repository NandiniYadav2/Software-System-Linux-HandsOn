//Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

 int fd = open("ticket.txt",O_RDWR);
 
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
 close(fd);
 printf("Finish.\n");
 

 return 0;
}
