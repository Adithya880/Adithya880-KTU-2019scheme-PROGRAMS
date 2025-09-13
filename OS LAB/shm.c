#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include <stdlib.h>

void main()
{
  key_t k=ftok(".",666);
  if (k == -1) 
  {
    perror("ftok failed");
    exit(1);
  }
  int shmid=shmget(k,1024,0666 | IPC_CREAT);
  if (shmid == -1)
  {
    perror("shmget failed");
    exit(1);
  }
  printf("\nID of shared memory : %d",shmid);
  void* sm=shmat(shmid,NULL,0);
  printf("\nProcess atatched: %p",sm);
  char buff[100];
  printf("\nEnter data:");
  read(0,buff,100);

  strcpy(sm,buff);
  printf("\nData: %s",(char*)sm);
}