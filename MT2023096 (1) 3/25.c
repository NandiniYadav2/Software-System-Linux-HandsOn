
/*
============================================================================
Name : 25.c
Author : Nandini Yadav
Description : write a program to create three child process.the parent should wait for a particular child(use waitpid system call).
(man 2 wait)
Date: 4th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

 
 int pid;
 int wpid;
 int status;

 if((pid = fork())==-1){
   perror("fork");
   exit(EXIT_FAILURE);
 }
  
  if(pid==0){
     printf("1st child process it's process id is :%d  it's parent process id is %d\n",getpid(),getppid());
     exit(EXIT_SUCCESS);
   }
   else{
      
      printf("first fork call in parent.....\n");
      int pid2;
      if((pid2=fork())==-1){
          perror("fork");
          exit(EXIT_FAILURE);
       }
         if(pid2==0){
           printf("2nd child process it's process id is :%d  it's parent process id is %d\n",getpid(),getppid());
           printf("now 2nd child sleeping...\n");
           
           //sleep(90);
           
           exit(EXIT_SUCCESS);
       }
       else{
            
           printf("second fork call in parent....\n");
           int pid3;
           if((pid3=fork())==-1){
              perror("fork");
              exit(EXIT_FAILURE);
            }
            
               if(pid3==0){
                  printf("3rd child process it's process id is :%d  it's parent process id is %d\n",getpid(),getppid());
                  exit(EXIT_SUCCESS);
               }
               else{
                    printf("parent of all.\n");
                    
                   wpid = waitpid(pid3,&status,0);
                   if (wpid == -1) {
                      perror("waitpid");
                      return 1;
                    }
                  if (WIFEXITED(status)) {
                       printf("Parent process: Child with PID %d has exited with status %d\n", wpid, WEXITSTATUS(status));
                    } 
                   else {
                       printf("Parent process: Child with PID %d did not exit normally\n", wpid);
                  
                 }
              }
    
          }
   
    }
  return 0;
}
