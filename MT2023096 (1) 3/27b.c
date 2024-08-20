/*
============================================================================
Name : 27b.c
Author : Nandini Yadav
Description:27. Write a program to execute ls -Rl by the following system calls 
b. execlp

Date: 4th Sep, 2023.
============================================================================
*/
/*refer man 3 execle*/


#include<stdio.h>
#include<unistd.h>

int main(){
 
 /*execlp():searches for the ls command in directories listed in the PATH environment variable, so you don't need to provide the full path to 'ls'.*/
 
 execlp("ls","ls","-Rl",NULL);
 perror("execlp");
 
 
 
 return 1;
}
