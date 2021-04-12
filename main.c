#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    pid_t pid;

    //printf("forked the processes \n");
    while(1) {
        int c;

        printf("enter value (parent) \n");
        c = getchar();
        int i = c - '0';

        if (i == 1) {
            printf("process 1 \n");
        }
        if (i == 2) {
            printf("it got here");
            char *args[] = {"/home/chase/CLionProjects/untitled2/cmake-build-debug/untitled2", NULL};
            execvp(args[0], args);
        }
    }


//    pid = fork();
//
//    if(pid == -1){
//        printf("error \n");
//    }
//    else if(pid == 0){
//        printf("i am process 2 (child)\n");
//        while(1){
//        }
//    }
//    else{
//        printf("i am process 1 (Parent) \n");
//        while(1)
//        }
//    }
}
