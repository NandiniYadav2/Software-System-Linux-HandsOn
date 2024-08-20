/*
============================================================================
Name : 24.c
Author : Nandini Yadav
Description : Write a program to create a message queue and print the key and message queue id.
Date: 1st Nov, 2023.
============================================================================
hint:
mq_open(3)
msgget(2)

*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

int main(){

/*struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

  int  mq = mq_open("msg", O_CREAT | O_RDWR, 0666, &attr);
    if (mq == -1) {
        perror("mq_open");
        return 1;
    }
*/
int key;
 key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    
 int   mq = msgget(key, IPC_CREAT|0666);
    if (mq == -1) {
        perror("msgget");
        return 1;
    }

 
  
  
 printf("Message Queue Key: %d\n", key);
 printf("Message Queue ID: %d\n", mq);
 
 if (mq_close(mq) == -1) {
        perror("mq_close");
        return 1;
    }

 return 0;
}





