/*
============================================================================
Name : 11_b.c
Author : Nandini Yadav
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
b)use dup2()
Date: 4th Sep, 2023.
============================================================================
*/

/*dup2(): to ensure we always get the file descriptor we want, we can use dup2()           -->int dup2(int oldfd, int newfd);  , If the file descriptor specified in newfd is already open, dup2() closes it first. (Any error that occurs during this close is silently ignored; safer practice is to explicitly close() newfd if it is open before the call to dup2().
*/

#include <stdio.h>
#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 
 int main(){
 
 char file[50] = "employee.txt";
 
 char text1[100] = "this is written using original file descriptor";
 char text2[100] = "this is written using duplicate file descriptor";
 
 int fd = open(file,O_RDWR |O_APPEND);
 if(fd == -1){
 
   perror("error in opening file");
   return 1;
 }
 
 int new_fd = dup2(fd,3);
 if(new_fd == -1){
 
   perror("error in duplicating file descriptor");
   return 1;
 }
 
 int bytes_write = write(fd,text1,sizeof(text1));
 if(bytes_write == -1){
 
   perror("error in writing file");
   return 1;
 }
 
 
 bytes_write = write(new_fd,text2,sizeof(text2));
 if(bytes_write == -1){
 
   perror("error in writing with duplicate  file des");
   return 1;
 }
 
 
 int fd_close = close(fd);
 int new_fd_close = (new_fd);
 
 if(fd_close == -1){
 
   perror("error in closing original file des");
   return 1;
 }
 if(new_fd_close == -1){
 
   perror("error inc closing dupliate file descriptor");
   return 1;
 }
 
 
 return 0;
 }
