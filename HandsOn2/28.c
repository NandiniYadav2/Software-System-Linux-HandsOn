/*
============================================================================
Name :28.c
Author : Nandini Yadav
Description :  . Write a program to change the existing message queue permission. (use msqid_ds structure)
Date: 3rd Nov, 2023.
============================================================================
hint:execute using sudo
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

int main(){

int key = ftok("/tmp",'A');
if(key==-1){
 perror("ftok");
 return 1;
}

int mq = msgget(key,IPC_CREAT|0666);
if(mq==-1){
 perror("msgget");
 return 1;
}

struct msqid_ds msgds;

int new_perm = 0644;
msgds.msg_perm.mode = new_perm;

int mset=msgctl(mq,IPC_SET,&msgds);
if(mset==-1){
 perror("msgctl");
 return 1;
}

printf("new permission :%o\n",msgds.msg_perm.mode);


 return 0;
}
