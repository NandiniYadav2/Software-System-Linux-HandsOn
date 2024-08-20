/*
============================================================================
Name : 27a.c
Author : Nandini Yadav
Description:27. Write a program to execute ls -Rl by the following system calls a. execl

Date: 4th Sep, 2023.
============================================================================
*/
/*refer man 3 execle*/

#include<stdio.h>
#include<unistd.h>

int main(){

/*execl(): used to replace the current process with a new process.here,it is executing ls command with the -Rl flag. 
First arg:path to the executable, and subsequent arguments are the command and its options. The last argument must be NULL to terminate the argument list.*/
 
 execl("/bin/ls","ls","-Rl",NULL);
 perror("execl");
 
 
 return 1;
}
