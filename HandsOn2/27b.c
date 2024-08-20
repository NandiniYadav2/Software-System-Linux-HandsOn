/*
============================================================================
Name : 27b.c
Author : Nandini Yadav
Description :  Write a program to receive messages from the message queue.

b. with IPC_NOWAIT as a flag
Date: 1st Nov, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

struct msgbuf{
 long mtype;
 char mtext[1024];

};

int main(){

 int key;
 key = ftok("/tmp",'A');/*convert a pathname identifier to a System V IPC key*/
 if(key==-1){
  perror("ftok");
  return 1;
 }
 
 int mq = msgget(key,IPC_CREAT|0666);/*returns System V msg queue identifier associated with key*/
 if(mq==-1){
  perror("msgget");
  return 1;
 }
 
  
 
 int send;
 int receive;
 struct msgbuf buff;
 buff.mtype=1;
 strcpy(buff.mtext,"..message queue..");
 
 send = msgsnd(mq,&buff,sizeof(buff),0);
 if(send==-1){
   perror("msgsnd");
   return 1;
 }
 
  if((receive = msgrcv(mq,&buff,sizeof(buff),0,0))==-1){
 
   perror("msgrcv");
   return 1;
 }
 
 printf("message received: %s\n",buff.mtext);
 
 return 0;
}
  
  
  
  
  
  
  
  
  
  
