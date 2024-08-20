/*
============================================================================
Name : 8.c
Author : Nandini Yadav
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


int main(){

 char file[50] = "2.c";
 FILE* fd = fopen(file,"r");
 size_t len=0;
 char* line=NULL;
 
 if(fd == NULL){
   printf("error opening file");
   return 1;
 }
 
 
 int char_read;
 
 while(1){
     
     char_read = getline(&line,&len,fd);
     
     if(char_read == -1){
        break;
     }
     
     printf("%s\n",line);
    
 }
 
 int fd_close = fclose(fd);
 if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }
 return 0;
}
