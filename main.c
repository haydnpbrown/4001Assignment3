#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>
#include "shared_memory.h"

int main() {

    pid_t pid;
    int stat_val;
    char *p2Args[] = {NULL};
    int shmid;
    printf("program starting \n");
    void *common_memory;
    struct common_mem *shared_mem;
    int running = 1;

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
            sleep(1);
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

    return 0;
}
