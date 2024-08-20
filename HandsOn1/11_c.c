//fcntl(): newfd = fcntl(oldfd, F_DUPFD, startfd);   This call makes a duplicate of oldfd by using the lowest unused file descriptor greater than or equal to startfd. This is useful if we want a guarantee that the new descriptor (newfd) falls in a certain range of values.

#include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 
 int main(){
 
 char file[50] = "employee.txt";
 
 char text1[100] = "this is written using original file descriptor";
 char text2[100] = "this is written using duplicate file descriptor";
 
 int fd = open(file,O_RDWR |O_APPEND);
 if(fd == -1){
 
   perror("error in opening file");
   return 1;
 }
 
 int new_fd = fcntl(fd,F_DUPFD,12);
 if(new_fd == -1){
 
   perror("error in duplicating file descriptor");
   return 1;
 }
 
 int bytes_write = write(fd,text1,sizeof(text1));
 if(bytes_write == -1){
 
   perror("error in writing file");
   return 1;
 }
 
 
 bytes_write = write(new_fd,text2,sizeof(text2));
 if(bytes_write == -1){
 
   perror("error in writing with duplicate  file des");
   return 1;
 }
 
 
 
 
 int fd_close = close(fd);
 int new_fd_close = (new_fd);
 
 if(fd_close == -1){
 
   perror("error in closing original file des");
   return 1;
 }
 if(new_fd_close == -1){
 
   perror("error inc closing dupliate file descriptor");
   return 1;
 }
 
 
 
 
 
 return 0;
 }
