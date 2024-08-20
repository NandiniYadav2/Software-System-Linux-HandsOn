/*
============================================================================
Name : 27e.c
Author : Nandini Yadav
Description:27. Write a program to execute ls -Rl by the following system calls 
e. execvp
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
 char *args[] = { "ls", "-Rl", NULL };
 execvp("ls",args);
 perror("execvp");

 return 1;
}
