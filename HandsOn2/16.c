/*
============================================================================
Name : 16.c
Author : Nandini Yadav
Description :  Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 14th oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main(){

int fd1[2];
int fd2[2];
char buff[1024];
char buff1[1024];

int pfd = pipe(fd1);

if(pfd==-1){
 perror("pipe1");
 return 1;
}

pfd = pipe(fd2);

if(pfd==-1){
 perror("pipe1");
 return 1;
}

int pid = fork();

if(pid==0){
  //child..
  //pipe1 read//
  close(fd1[1]);
  read(fd1[0],buff,sizeof(buff));
  printf("message from parent for child is:%s\n",buff);
  close(fd1[0]);
  
  //pipe2 write//
  close(fd2[0]);
  printf("child enter message for parent:\n");
  scanf("%[^\n]",buff1);
  write(fd2[1],buff1,sizeof(buff1));
  close(fd2[1]);
  
  
}
else{
   //parent..
  //pipe1 write
  close(fd1[0]);
  printf("parent enter message for child:\n");
  scanf("%[^\n]",buff);
   write(fd1[1],buff,sizeof(buff));
   close(fd1[1]);
   
  //pipe2 read//
   close(fd2[1]);
   read(fd2[0],buff1,sizeof(buff1));
   close(fd2[0]);
   printf("message from child for parent is: %s\n",buff1);
   
   wait(0);

}




 return 0;
}
