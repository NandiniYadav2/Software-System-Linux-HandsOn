/*
============================================================================
Name : 25.c
Author : Nandini Yadav
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 19th oct, 2023.
============================================================================
hint:
msgctl(2)

*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<mqueue.h>
#include<time.h>


int main(){

 struct msqid_ds msg;
 int key;
 int mq = msgget(key,IPC_CREAT |0666);
 if(mq== -1) {
        perror("msgget");
        return 1;
   }
 
 int m = msgctl(mq,IPC_STAT,&msg);/*IPC_STAT->copy information from kernel data structures associated with msgqid into msqid_ds structure*/
 
 if(m==-1){
   perror("msgctl:");
   return 1;
 }
 
 
 printf("Acess Permissions: %o\n ",msg.msg_perm.mode);
 printf("UID: %d\n ",msg.msg_perm.uid);
 printf("GID: %d\n ",msg.msg_perm.gid);
 printf("Time of last message sent: %s",ctime(&msg.msg_stime));
 printf(" Time of last message received: %s ",ctime(&msg.msg_rtime));
 printf("Time of last change in the message queue: %s ",ctime(&msg.msg_ctime));
 printf("Number of messagees in queue: %lu\n ",msg.msg_qnum);
 printf("Max no of bytes allowed: %lu\n ",msg.msg_qbytes);
 printf("Queue size: %lu\n ",msg.msg_qbytes);
 printf("PID of msgsnd: %d\n ",msg.msg_lspid);
 printf("PID of msgrcd: %d\n ",msg.msg_lrpid);
 
 
 
 return 0;
}
