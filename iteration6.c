#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct messages {
    long int message_type;
    int value;
};

int main(){
    pid_t pid;
    printf("iteration 6 program starting. \n");
    int running = 1;
    int msgqid; //id of the message queue
    struct messages msg; //the message to send
    int i; //used to create the children

    //create the message queue
    msgqid = msgget((key_t)1236, 0666 | IPC_CREAT);
    if (msgqid == -1){
        printf("error creating the message queue");
        exit(EXIT_FAILURE);
    }

    msg.message_type = 1;
    msg.value = 1;
    if(msgsnd(msgqid, (void *)&msg, MAX_TEXT, 0) == -1){
        printf("error sending message");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 2; i++){
        pid = fork();
        if (pid == -1){
            printf("fork failed");
            exit(1);
        } else if (pid == 0){
            break;
        }
    }

    //parent process
    if (pid != 0) {
        int n = i;
        while(n > 0){
            wait(NULL);
            n--;
        }

        //delete msg queue
        if (msgctl(msgqid, IPC_RMID, 0) == -1){
            printf("error closing the msg queue \n");
            exit(EXIT_FAILURE);
        }
        printf("msg queue deleted \n");
        printf("program finished \n");
    } else {
        //child
        if (i == 0){
            //first child
            if (msgrcv(msgqid, (void *)&msg, MAX_TEXT, 0, 0) == -1){
                printf("error receiving msg in p2 \n");
                exit(1);
            }
            //multiply the value by 2, print it, and send it on the queue to child 2.
            int result = msg.value * 2;
            printf("msg after p2: %d \n", result);

            msg.value = result;
            if(msgsnd(msgqid, (void *)&msg, MAX_TEXT, 0) == -1){
                printf("error sending message in p2 \n");
                exit(EXIT_FAILURE);
            }
            exit(0);
        } else if(i == 1){
            //second child
            if (msgrcv(msgqid, (void *)&msg, MAX_TEXT, 0, 0) == -1){
                printf("error receiving msg in p3 \n");
                exit(1);
            }
            //add 1 to the value received from the first child
            int result = msg.value + 1;
            printf("msg after p3: %d \n", result);

            msg.value = result;

            exit(0);
        }
    }
    return 0;

}