#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int * A, int * B);

int main(){

    int X = 25;
    int Y = 37;
    TrocarElemento(&X, &Y);

}

void TrocarElemento(int * A, int * B){

printf("%d \t %d \n ", *A, *B);

}