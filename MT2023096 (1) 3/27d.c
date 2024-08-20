/*
============================================================================
Name : 27d.c
Author : Nandini Yadav
Description:27. Write a program to execute ls -Rl by the following system calls 
d. execv 
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){

 char *args[] = { "ls", "-Rl", NULL };
 execv("/bin/ls",args);
 perror("execv");

 
 
 return 1;
}
