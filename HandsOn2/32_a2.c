/*
============================================================================
Name : 32.c
Author : Nandini Yadav
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 14th oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){

FILE *file;
sem_t *sem;

sem = sem_open("ticketsem",O_CREAT,0644,1);

if(sem == SEM_FAILED){
  perror("semOPen:");
  return 1;
}

file = fopen("ticket.txt","r+");
if(file==NULL){
 perror("fopen");
 return 1;
}

printf("want to book ticket ? press enter:\n");
getchar();

//lock sem
sem_wait(sem);

printf("inside critical section.....\n");

int ticketno;
fscanf(file,"%d",&ticketno);



lseek(fileno(file),0,SEEK_SET);
ticketno++;

fprintf(file,"%d",ticketno);
printf("your ticket no is : %d\n",ticketno);


//unlock sem
sem_post(sem);

fclose(file);
sem_close(sem);

return 0;

}
