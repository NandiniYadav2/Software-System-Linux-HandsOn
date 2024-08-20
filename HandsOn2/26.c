/*
============================================================================
Name : 26.c
Author : Nandini Yadav
Description :  Write a program to send messages to the message queue. Check $ipcs -q
Date: 30th oct, 2023.
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
 
 struct msgbuf buff;
 buff.mtype=1;
 strcpy(buff.mtext,"..message queue..");
 
 
 int send = msgsnd(mq,&buff,sizeof(buff),0);
 if(send==-1){
   perror("msgsnd");
   return 1;
 }
 
 return 0;
}

