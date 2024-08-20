/*
============================================================================
Name : 31.c
Author : Nandini Yadav
Description :  Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 14th oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

int main(){
 
 sem_t binsem;
 sem_t countsem;
 
 int s = sem_init(&binsem,0,1);//binary semaphores initialized with 0 or 1 
 
 if(s==-1){
   perror("init bin:");
   return 1;
 }
 
 int c = sem_init(&countsem,0,6);//counting semaphores can be initialized with values greater than 1(here initial value 6 allows 6 concurrent accesses)
 if(c==-1){
   perror("init count:");
   return 1;
 }


 if(sem_destroy(&binsem)==-1){
  perror("binsem destroy:");
  return 1;
 }
 
 if(sem_destroy(&countsem)==-1){
  perror("countsem destroy:");
  return 1;
 }


 return 0;
}
