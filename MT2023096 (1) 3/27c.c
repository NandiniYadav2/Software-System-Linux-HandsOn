/*
============================================================================
Name : 27c.c
Author : Nandini Yadav
Description:27. Write a program to execute ls -Rl by the following system calls 
c. execle

Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){

 /*char *envp[]:array of environment variables that you want to set for the new process. Here, we set the PATH variable to "/bin" to ensure that it uses /bin/ls. The array must be terminated with a NULL pointer.*/
 char *envp[] = { "PATH=/bin", NULL };
 execle("/bin/ls","ls","-Rl",NULL,envp);
 perror("execl");
 printf("execl not worked");
 
 
 return 1;
}
