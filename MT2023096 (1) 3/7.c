/*
============================================================================
Name : 7.c
Author : Nandini Yadav
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int main(int argc,char* argv[]){
  if(argc!=3){
   printf("not appropriate no of arguments");
   return 0;
 }
 
 int fd_read=open(argv[1],O_RDONLY);
 int fd_write=open(argv[2],O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
 
 if(fd_read==-1 || fd_write==-1){
    printf("not appropriate files");
    }
   
 while(1){
 char buf;
 int char_read=read(fd_read,&buf,1);
 if(char_read==0)
    break;
 int char_write=write(fd_write,&buf,1);
 }
 
 int fd_read_close=close(fd_read);
 int fd_write_close=close(fd_write);
 
 if(fd_read_close==-1 || fd_write_close==-1)
 {
   printf("error in closing");
  }
  
   


return 0;
}
