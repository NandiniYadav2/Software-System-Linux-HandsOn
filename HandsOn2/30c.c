/*
============================================================================
Name : 30c.c
Author : Nandini Yadav
Description : Write a program to create a shared memory.
c. detach the shared memory
Date: 3rd Nov, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(){

int key = ftok("/tmp",'A');

int sh = shmget(key,1024,IPC_CREAT|0666);

char *shadd = shmat(sh,NULL,0);

strcpy(shadd,"it is at  shared memory");

printf("data written to shared memory: %s\n",shadd);/*it is successful*/

int shdett = shmdt(shadd); 
printf("data written to shared memory: %s\n",shadd);/*segmentation fault*/

 return 0;
}


