/*
============================================================================
Name : 15.c
Author : Nandini Yadav
Description : Write a program to display the environmental variable of the user (use environ).
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern char **environ;
int prefixmatch(const char *pre,const char *str)
{

  return strncmp(pre,str,strlen(pre)) == 0;
}

int main(){

  char **env = environ;
  
  while(*env != NULL){
    if(prefixmatch("USER",*env)){
      printf("%s\n", *env);
      env++;
    
    }
  }


return 0;
}
