#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/shm.h>

int main() {

    pid_t pid;
    void *memory_location;
    int shmid;
    key_t key;
    int *z;

    key = 2570;

    printf("fork program starting \n");

    shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1){
        int error = errno;
        fprintf(stderr, "Failed");
        exit(EXIT_FAILURE);
    }

    memory_location = shmat(shmid, (void*) 0, 0);
    if (memory_location == (void*) -1){
        fprintf(stderr, "Failed Memory attach");
        exit(EXIT_FAILURE);
    }

//    if(shmdt(memory_location) == -1){
//        printf("error in smdt\n");
//        exit(EXIT_FAILURE);
//    }
//
//    if(shmctl(shmid, IPC_RMID,0) == -1){
//        printf("error in shcmctl");
//        exit(EXIT_FAILURE);
//    }

    printf("memory attached at %X\n\n");

    pid = fork();

    z = (int *) memory_location;

    if (pid == -1){
        printf("error forking");
    } else if (pid == 0) {
        printf("process 2 starting (child) ... \n");
        printf("shared memory value in process 2 (Child) before any Manipulation %d\n\n", *z);

        *z = 15;
        printf("value from Child after Manipulation %d\n\n", *z);

    } else {
        printf("process 1 is running! (parent)\n");
        printf("shared memory value in process 1 (Parent) before any Manipulation %d\n\n", *z);

        wait(NULL);
        printf("parent wait finished \n\n");

        printf("value from Child before parent manipulation %d\n", *z);

        *z = 60;
        printf("value from parent after manipulation %d\n\n", *z);
    }

    return 0;
}
