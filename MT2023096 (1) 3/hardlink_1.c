/*
============================================================================
Name : 1.c
Author : Nandini Yadav
Description : Create the following types of a files using (i) shell command (ii) system call
 a. softlink (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
Date: 4th Sep, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define FIFO_PERMISSIONS 0666

int main(){
int v = symlink("1.c","softlink1.c");
 if(v<0){
   perror("Error creating soft link");
   return 1;
   }
  
    printf("Softlink created successfully\n");
   
   
 int f = link("1.c","hardlink1.c");
 
 if(f<0)
 {
   perror("Error creating hardlink ");
   return 1;
   }
   
   printf("hardlink created successfully\n ");
   
   
 int e = mknod("fifo_2", S_IFIFO | FIFO_PERMISSIONS,0);
 
 if(e<0){
  perror("Failed" );
  return 1;
  }
  
  printf("fifo created \n");
  
  return 0;
  
  }     
