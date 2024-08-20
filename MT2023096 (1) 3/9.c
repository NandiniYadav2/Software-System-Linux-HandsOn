/*
============================================================================
Name : 9.c
Author : Nandini Yadav
Description : Write a program to print the following information about a given file.   (a) inode (b)number of hard link  (c) uid (d) gid (e) size (f) block size (g) number of blocks (h) time of last access (i) time of last modification j. time of last change

Date: 4th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc,char* argv[]){

  if(argc!=2){
   
   perror("not appropriate arguments");
   return 1;
  }
  
  //char* file = argv[1];
  struct stat file_stats;
  
  if( stat(argv[1] , &file_stats) == -1){
  
    perror("error");
    return 1;
  }
  
  //ctime(&file_stats.st_atime): (1)&file_stats.st_atime provides the address of the timestamp of the last access. (2)ctime takes a time value (represented as the no of sec since "epoch") (3)ctime converts the time value to a human-readable string rep :"Day Month Date HH:MM:SS Year".
    
  
 printf("Inode : %lu\n", (unsigned long) file_stats.st_ino );
  
printf("No of hard links : %lu\n", (unsigned long) file_stats.st_nlink );
printf("UID : %u\n", file_stats.st_uid );
  printf("GID : %u\n", file_stats.st_gid );
  printf("Size : %ld bytes\n", file_stats.st_size );
  printf("Block Size : %d  bytes\n",  file_stats.st_blksize );
  printf("No of blocks : %ld\n",  file_stats.st_blocks );
  printf("Time of last access : %s\n",  ctime(&file_stats.st_atime) );
  printf("Time of last modification : %s\n",  ctime(&file_stats.st_mtime ));
  printf("Time of last change : %s\n",  ctime(&file_stats.st_ctime ));
  
 
return 0;
}
