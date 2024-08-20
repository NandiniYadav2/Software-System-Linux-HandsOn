//Write a program to find the type of a file.

 //(a) Input should be taken from command line.
 //(b) program should be able to identify any type of a file.
  
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

  
 int main(int argc,char* argv[]){

  if(argc!=2){
   
   perror("not appropriate arguments\n");
   return 1;
  }
  
  struct stat file_stats;
  
  if( stat(argv[1] , &file_stats) == -1){
  
    perror("error \n");
    return 1;
  }
  
  if(S_ISREG(file_stats.st_mode)){
  
     printf("Regular File\n");
  }  
  else if(S_ISDIR(file_stats.st_mode)){
  
     printf("Directory \n");
  }  
  else if(S_ISCHR(file_stats.st_mode)){
  
     printf("Character Device File\n");
  }  
 else if(S_ISBLK(file_stats.st_mode)){
  
     printf("Block Device\n");
  }  
  else if(S_ISFIFO(file_stats.st_mode)){
  
     printf("FIFO or PIPE\n");
  }  
 else if(S_ISSOCK(file_stats.st_mode)){
  
     printf("Socket\n");
  }  
  else if(S_ISLNK(file_stats.st_mode)){
  
     printf("Symbolic link\n");
  } 
  else{
  
     printf("Unknown File\n");
  }   
  
  
  return 0;
  
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
