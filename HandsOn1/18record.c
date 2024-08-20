//18. Write a program to perform Record locking. 
  
  #include<unistd.h>
  #include<stdio.h>
  #include<fcntl.h>
  #include<stdlib.h>
  #include<sys/types.h>
  #include<sys/stat.h>
  #include<string.h>
  struct student{
     
     int rollNo;
     char name[15];
     
     };
 
  int main(){
  
     int fd = open("wrlocked.txt",O_RDWR|O_CREAT,0666);
     if (fd == -1) {
        perror("Error opening file\n");
        return 1;
    }
    
    int rec_Size =sizeof(struct student);
    int record_N;
    
    printf("which record you want to read or write:\n");
    scanf("%d",&record_N);
    
    struct student s;
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_Size*(record_N-1);
    lock.l_len = rec_Size;
    lock.l_pid = getpid();
    
    fcntl(fd,F_SETLKW,&lock);
    
    printf("you want to read(type r) or write(type w) record?:\n");
    
    char task;
    read(0,&task,sizeof(task));
    
    if(task =='w'){
         printf("Record no %d is locked for write\nNow enter Name of student:\n",record_N);
         
        
       int roll=0;
        char stu_name[15];
        
        
        
        getchar();
        getchar();
        scanf("%d",&roll);
        
        s.rollNo=roll;
        read(0,&stu_name,sizeof(stu_name));
        strcpy(s.name,stu_name);
        
        lseek(fd,record_N*rec_Size,SEEK_SET);
        write(fd,&s,rec_Size);
        
    
    }
    else if(task =='r'){
    
    
       lseek(fd,record_N*rec_Size,SEEK_SET);
      
       read(fd,&s,rec_Size);
       
       printf("Roll No:%d\nName:%s\n",s.rollNo,s.name);
       
      
    }
    
    printf("Task completed now Enter to unlock:\n");
    getchar();
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    close(fd);
    
    printf("finish.\n");
    
    
    
    return 0;
  }
