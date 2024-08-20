/*
============================================================================
Name : 17c.c
Author : Nandini Yadav
Description : Write a program to execute ls -l | wc.
c. use fcntl 
Date: 14th oct, 2023.
============================================================================
*/
  #include<stdio.h>
  #include<unistd.h>
  #include<stdlib.h>
  #include<fcntl.h>
  #include<errno.h>
  int main(){
   
    int fd[2];
    int pfd = pipe(fd);
    
    if(pfd==-1){
      perror("pipe:");
      return 1;
    }
    
    int pid = fork();
    
    if(pid==-1){
      perror("fork:");
      return 1;
    }
    
    if(pid==0){
      close(fd[0]);
      fcntl(fd[1],F_DUPFD,STDOUT_FILENO);
      //close(fd[1]);
      
      execlp("ls","ls","-l",NULL);
      perror("execlp:");
      
    
    }
    else{
    close(fd[1]);
      fcntl(fd[0],F_DUPFD,STDIN_FILENO);
      //close(fd[0]);
      
      execlp("wc","wc",NULL);
      perror("execlp_wc:");
      
    
    
    
    }
    
    
    
   
   
  
    return 0;  
  } 
   
