//
// Created by chase on 2021-04-09.
//
#include <stdio.h>
#include "ATM_header.h"

void ATM(){

    int accountNum[5];
    int i;
    int pin[3];
    float funds;

    printf( "enter Account Number : ");
    scanf("%s %d", accountNum, &i);

    printf("\n Account Number entered : %s %d", accountNum, i);

    printf( "enter pin : ");
    scanf("%s %d", pin), &i;

    printf("pin accepted : %s %d", pin, i);

}


