#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    int stat_val;
    printf("fork program starting \n");
    pid = fork();


    if (pid == -1){
        printf("error forking");
    } else if (pid == 0) {
        int entry;
        printf("process 2 is running! \n");

        while(1){
            scanf("%d", &entry);
            if (entry == 2){
                printf("process 2 is running! \n");
            } else {
                printf("process 2 is done \n");
                exit(1);
            }
        }

    } else {
        printf("Parent forked, now waiting for P2 to finish... \n");
        wait(&stat_val);
    }

    printf("both processes finished. \n");

    return 0;
}
