/*
============================================================================
Name : 6.c
Author : Nandini Yadav
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
Date: 4th Sep, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main(){

 char buf[1024];
 
 int bytes_read;
 int bytes_write;

 while((bytes_read = read(0,buf,sizeof(buf)))> 0){
   bytes_write = write(1,buf,bytes_read);
   
   if(bytes_write != bytes_read){
     perror("write error");
     return -1;
   }
 
 }
 if(bytes_read == -1){
  perror("read error");
  return -1;
 }
 

return 0;


}
