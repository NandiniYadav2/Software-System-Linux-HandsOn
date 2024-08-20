/*
============================================================================
Name : 18rdlckRec.c
Author : Nandini Yadav
Description :  Write a program to perform Record locking.
2)Implement read lock.
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main() {
 struct {
  int train_num;
  int ticket_count;
 }dbs[3];
   int fd, input;
   fd = open("record.txt", O_RDWR);
   if(fd==-1){
    perror("error in opening file descriptor");
    return 1;
  
  }
   printf("Select train number: 1, 2, 3\n");
   scanf("%d", &input);

   struct flock lock;
   lock.l_type = F_RDLCK;
   

   lock.l_start = (input - 1) * sizeof(dbs);
   
   /*This actually implements record-level locking
   We start locking from the beginning of selected train's record upto the end of that record which will be at l_start + sizeof(db)*/
   lock.l_len = sizeof(dbs);
   lock.l_pid = getpid();
   
  
   lseek(fd, (input - 1) * sizeof(dbs), SEEK_SET);
   read(fd, &dbs, sizeof(dbs));
   printf("Before entering critical section\n");
   fcntl(fd, F_SETLKW, &lock);
   printf("Current ticket count: %d\n", dbs->ticket_count);
   dbs->ticket_count++;

   // Currently fd is pointing to end of current record and we have to move it to the start of current record, i.e. SEEK_CUR - sizeof(dbs)
   
   lseek(fd, -1 * sizeof(dbs), SEEK_CUR);
   write(fd, &dbs, sizeof(dbs));
   printf("To book ticket, press enter\n");
   getchar();
    
    
   getchar();
   lock.l_type = F_UNLCK;
   fcntl(fd, F_SETLK, &lock);
   printf("Ticket booked with number %d\n", dbs->ticket_count);
   int fd_close = close(fd);
   if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
   
   return 0;
}
