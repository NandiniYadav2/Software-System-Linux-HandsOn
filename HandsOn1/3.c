//3. Write a program to create a file and print the file descriptor value. Use creat ( )  system call 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

char file[] = "ques3.txt";

 int fd=creat(file,0666);
 
 if(fd==-1){
   perror("error creating file");
   return 1;
 }
 
  printf("file  %s is created succssfully with file descriptor : %d \n",file,fd);
 
 
 
 int fd_close=close(fd);
 if(fd_close==-1){
 perror("error closing file descriptor");
 return 1;
 }

return 0;
}


