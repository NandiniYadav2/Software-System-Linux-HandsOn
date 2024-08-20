/*
============================================================================
Name : 30b.c
Author : Nandini Yadav
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.

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

char *shadd = shmat(sh,NULL,SHM_RDONLY);



strcpy(shadd,"it is at  shared memory");/*this gives SEGMENTATION FAULT*/

printf("data written to shared memory: %s\n",shadd);



 return 0;
}


