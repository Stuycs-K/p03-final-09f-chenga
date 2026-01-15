#include "setup.h"

void err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

void setup(){
  int *highscore;
  int shmid;
  shmid = shmget(KEY, sizeof(int), IPC_CREAT | 0666);
  if (shmid < 0) err();
  highscore = shmat(shmid, 0, 0);
  *highscore = 0;
  shmdt(highscore);

  int semd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0666);
  if (semd < 0) err();
  union semun users;
  users.val = 1;
  semctl(semd, 0, SETVAL, users);
}
void update(int newScore){
  int semd = semget(KEY, 1, 0);
  if (semd == -1) err();
  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  sb.sem_op = -1;
  if(semop(semd, &sb, 1)==-1) err();

  int shmid = shmget(KEY, sizeof(int), 0);
  if (shmid == -1) err();
  int *highscore = shmat(shmid, 0, 0);

  if (newScore > *highscore){
    *highscore = newScore;
    printf("NEW HIGHSCORE!: %d", *highscore);
  }
  else {
    printf("Highscore: %d\n", *highscore);
  }
  shmdt(highscore);
}
void view(){
  int semd = semget(KEY, 1, 0);
  if (semd == -1) err();
  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  sb.sem_op = -1;
  if(semop(semd, &sb, 1)==-1) err();

  int shmid = shmget(KEY, sizeof(int), 0);
  if (shmid == -1) err();
  int *highscore = shmat(shmid, 0, 0);

  printf("Current Highscore: %d", *highscore);

  shmdt(highscore);
}
void remove0(){
  int shmid;
  shmid = shmget(KEY, sizeof(int), 0);
  shmctl(shmid, IPC_RMID, 0);

  int semd;
  semd = semget(KEY, 1, 0);
  semctl(semd, 0, IPC_RMID);
  printf("Removed\n");
}
