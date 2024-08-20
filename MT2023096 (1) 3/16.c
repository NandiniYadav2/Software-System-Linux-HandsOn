/*
============================================================================
Name : 16.c
Author : Nandini Yadav
Description :  Write a program to perform mandatory locking.
 a. Implement write lock
 Date: 4th Sep, 2023.
============================================================================
*/
 
   
   #include<stdio.h>
   #include<unistd.h>
   #include<fcntl.h>
   
   int main(){
    
    int fd = open("wrlocked.txt",O_RDWR | O_CREAT,0666);
    if(fd==-1){
      perror("Error in opening file\n");
      return 1;
    }
   
   struct flock lock;
   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;
   lock.l_pid = getpid();
   
   printf("Before entering into critical section..\n");
   
   fcntl(fd,F_SETLKW,&lock);
   
   printf("Inside critical section......\n");
   printf("ENTER to unlock:\n");
   getchar();
   
   lock.l_type=F_UNLCK;
   fcntl(fd,F_SETLK,&lock);
   printf("Unlocked.\n");
   
   int fd_close = close(fd);
   if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
   
   return 0;
   }
