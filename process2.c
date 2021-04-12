#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    int entry;
    printf("process 2 is running! \n");
    scanf("%d", &entry);
    if (entry == 2){
        printf("process 2 is running! \n");
    }
    printf("process 2 is done");

    return 0;
}
