#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t pid;
    printf("fork program starting \n");
    pid = fork();
    int entry;
    char *p2Args[] = {NULL};

    if (pid == -1){
        printf("error forking");
    } else if (pid == 0) {
        printf("process 2 starting... \n");
        //exec
        execvp("/home/chase/Documents/GitHub/4001Assignment3/p2", p2Args);
    } else {
        printf("process 1 is running! \n");
        scanf("%d", &entry);
        if (entry == 1){
            printf("process 1 is running! \n");
        }
        printf("process 1 is done");
    }

    sleep(5);

    return 0;
}
