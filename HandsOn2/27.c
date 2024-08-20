/*
============================================================================
Name : 27.c
Author : Nandini Yadav
Description :  Write a program to receive messages from the message queue.
a. with 0 as a flag
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
 
  struct msgbuf buf;
 buf.mtype=1;
 strcpy(buf.mtext,"..message queue..");
 
 
 int send = msgsnd(mq,&buf,sizeof(buf),0);
 if(send==-1){
   perror("msgsnd");
   return 1;
 }
 
 int receive = msgrcv(mq,&buf,sizeof(buf),0,0);
 if(receive==-1){
   perror("msgrcv");
   return 1;
 }
 
 printf("message received: %s\n",buf.mtext);
 
 return 0;
}

 
 
 
 
 
 
