#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t pid;

    printf("fork program starting \n");

    pid = fork();

    if (pid == -1){
        printf("error forking");
    } else if (pid == 0) {
        printf("I am process 1 (child) \n");
        while(1){
        }
    } else {
        printf("I am process 2 (parent) \n");
        while(1){

        }
    }

    return 0;
}
