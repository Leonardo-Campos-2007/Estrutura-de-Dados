#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "expressao.h"



int main()
{
    char posFixa[] = "45 60 + 30 cos *";

    printf("%s\n", getFormaInFixa(posFixa));

    return 0;
}   
