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

    int shmid;
    void *common_memory;
    struct common_mem *shared_mem;
    int running = 1;
    int semid; //semaphore id
    int sleeptime; //time for process to sleep for

    //setting semid with semget
    semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);

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

    char entry[100];
    while(running){
        //try to obtain the semaphore
        if (!sp(semid)){
            exit(EXIT_FAILURE);
        }
        if (shared_mem->flag == 0){
            printf("enter text for p2: \n");
            fgets(entry, 100, stdin);
            memccpy(shared_mem->some_text, entry, 0, 100);
            shared_mem->flag = 1;
            if (strncmp(shared_mem->some_text, "1", 1) == 0){
                printf("Msg 1 from P2! \n");
            } else if (strncmp(shared_mem->some_text, "2", 1) == 0){
                printf("Msg 2 from P2! \n");
            } else if (strncmp(shared_mem->some_text, "x", 1) == 0){
                printf("P2 will now end. \n");
                running = 0;
            }
        }
        //release the semaphore
        if (!sv(semid)){
            exit(EXIT_FAILURE);
        }
        sleeptime = rand() % 3;
        sleep(sleeptime);
    }

    if (shmdt(shared_mem) == -1){
        printf("error in shmdt p2\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
