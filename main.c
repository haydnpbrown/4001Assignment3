#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>
#include "shared_memory.h"
#include "semfuncs.h"
#include <sys/sem.h>

int main() {

    pid_t pid;
    int stat_val;
    char *p2Args[] = {NULL};
    int shmid; //shared mem id
    printf("program starting \n");
    void *common_memory; //the shared mem address
    struct common_mem *shared_mem; //the struct that is stored in shared mem
    int running = 1;
    int semid; //semaphore id
    int sleeptime; //time for process to sleep for

    //semaphore creation and setting values
    semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);
    if (!set_semvalue(semid)){
        printf("there was an error setting them sem value");
        exit(EXIT_FAILURE);
    }

    shmid = shmget((key_t)1234, sizeof(struct common_mem), 0666 | IPC_CREAT);
    if (shmid == -1){
        printf("there was an error in shmget \n");
        exit(1);
    }

    common_memory = shmat(shmid, NULL, 0);
    if (common_memory == (void *)-1){
        printf("shmat failed");
        exit(EXIT_FAILURE);
    }

    shared_mem = (struct common_mem *)common_memory;

    pid = fork();

    if (pid == -1){
        printf("error forking");
    } else if (pid == 0) {
        printf("process 2 is starting \n");
        execvp("/home/haydn/CLionProjects/4001Assignment3/p2", p2Args);
    } else { //parent process
        while(running){
            //try to obtain the semaphore
            if (!sp(semid)){
                exit(EXIT_FAILURE);
            }
            if(shared_mem->flag){
                if (strncmp(shared_mem->some_text, "1", 1) == 0){
                    printf("you entered a 1! - p1 \n");
                } else if (strncmp(shared_mem->some_text, "2", 1) == 0){
                    printf("you entered a 2! - p1 \n");
                } else if (strncmp(shared_mem->some_text, "x", 1) == 0){
                    printf("P1 will now end. \n");
                    running = 0;
                } else {
                    printf("not a valid entry: %s \n", shared_mem->some_text);
                }
                sleep(1);
                shared_mem->flag = 0;
            }
            //release the semaphore
            if (!sv(semid)){
                exit(EXIT_FAILURE);
            }
            sleeptime = rand() % 2;
            sleep(sleeptime);
        }
    }

    if (shmdt(shared_mem) == -1){
        printf("error in shmdt\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1){
        printf("error in shmctl");
        exit(EXIT_FAILURE);
    }
    printf("P1 finished. \n");
    //deleting semaphore
    del_semvalue(semid);

    return 0;
}
