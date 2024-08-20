/*
============================================================================
Name : 29.c
Author : Nandini Yadav
Description :  Write a program to remove the message queue.
Date: 3rd Nov, 2023.
============================================================================
hint:msgctl(2)->IPC_RMID->ignore 3rd arg.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<errno.h>

int main(){

 int key;
 int mq;
 
 if((key = ftok("/tmp",'A'))==-1){
   perror("ftok");
   return 1;
 
 }
 
 if((mq = msgget(key,IPC_CREAT|0666))==-1){
  perror("msgget");
  return 1; 
 }
 
 int m = msgctl(mq,IPC_RMID,NULL);
 if(m==-1){
  perror("msgctl");
  return 1;
 }
 
printf("Message queue removed successfully.\n");

 return 0;
}

