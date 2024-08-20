/*
============================================================================
Name : 30d.c
Author : Nandini Yadav
Description : Write a program to create a shared memory.
d. remove the shared memory
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
printf("data written to shared memory: %s\n",shadd);

if (shmdt(shadd) == -1) {
        perror("shmdt");
        return 1;
 }
    
if(shmctl(sh,IPC_RMID,NULL)==-1){
 perror("shmctl:");
 return 1;
}

printf("data written to shared memory: %s\n",shadd);



 return 0;
}


