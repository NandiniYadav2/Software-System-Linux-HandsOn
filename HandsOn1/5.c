//5.Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

 int fds[5];
 
 for(int i=0;i<5;i++){
    
    char file5[20];
    sprintf(file5,"ques5_%d.txt",i);
    
    fds[i]=creat(file5,0666);
    
    if(fds[i] == -1){
      perror("error creating file.");
      return -1;
    }
    
    printf("created file %s with file descriptor: %d\n",file5,fds[i]);
    
 
 }
 
 while(1){
  sleep(1);
 
 }
 
return 0;
}
