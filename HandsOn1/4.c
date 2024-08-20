//Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(){

  const char file[] = "employee.txt";
  
  int fd=open(file,O_RDWR | O_EXCL);
  if(fd==-1){
    if(errno == EEXIST){
       printf("file %s already exist.\n",file);
    }
    else{
      perror("error opening file");
    }
    return 1;
  }
  
  printf("file %s opened successfully with read write mode.\n",file);
  
  int fd_close=close(fd);
  if(fd_close==-1){
    perror("error closing file descriptor");
    return 1;
  
  }

return 0;
}
