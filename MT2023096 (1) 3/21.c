/*
============================================================================
Name : 21.c
Author : Nandini Yadav
Description : Write a program, call fork and print the parent and child process id.
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>


int main(){

int pid;
if((pid = fork())== -1){
  perror("fork");
  exit(EXIT_FAILURE);

}
  
 if(pid ==0){
  //child process
  printf("child process id: %d\n",getpid());
  exit(EXIT_SUCCESS);
  
 } 
 else{
 //parent
  printf("parent process id: %d\n",getpid());
 wait(0);
 }
  


 return 0;
}
