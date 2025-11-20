#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expressao.h"

#define MAX 512

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



typedef struct {
    char items[MAX][MAX];
    int top;
} StackStr;

void pushStr(StackStr *s, const char *str) {
    strcpy(s->items[++s->top], str);
}

char *popStr(StackStr *s) {
    return s->items[s->top--];
}



typedef struct {
    float items[MAX];
    int top;
} StackF;

void pushF(StackF *s, float v) {
    s->items[++s->top] = v;
}

float popF(StackF *s) {
    return s->items[s->top--];
}



int isBinaryOperator(char *t) {
    return strcmp(t, "+") == 0 ||
           strcmp(t, "-") == 0 ||
           strcmp(t, "*") == 0 ||
           strcmp(t, "/") == 0 ||
           strcmp(t, "^") == 0;
}

int isFunction(char *t) {
    return strcmp(t, "sin") == 0 ||
           strcmp(t, "sen") == 0 ||
           strcmp(t, "cos") == 0 ||
           strcmp(t, "tan") == 0 ||
           strcmp(t, "tg") == 0  ||
           strcmp(t, "log") == 0 ||      
           strcmp(t, "log10") == 0;
}



char *getFormaInFixa(char *Str) {

    static char resultado[MAX];
    StackStr s;
    s.top = -1;

    char expr[MAX];
    strcpy(expr, Str);

    char *t = strtok(expr, " ");

    while (t != NULL) {

        if (isBinaryOperator(t)) {

            char right[MAX], left[MAX], combined[MAX];

            strcpy(right, popStr(&s));
            strcpy(left, popStr(&s));

            sprintf(combined, "(%s %s %s)", left, t, right);
            pushStr(&s, combined);

        } else if (isFunction(t)) {

            char arg[MAX], combined[MAX];
            strcpy(arg, popStr(&s));

            sprintf(combined, "%s(%s)", t, arg);
            pushStr(&s, combined);

        } else {
            pushStr(&s, t);
        }

        t = strtok(NULL, " ");
    }

    strcpy(resultado, popStr(&s));
    return resultado;
}



float getValorPosFixa(char *StrPosFixa) {

    StackF s;
    s.top = -1;

    char expr[MAX];
    strcpy(expr, StrPosFixa);

    char *t = strtok(expr, " ");

    while (t != NULL) {

        if (isBinaryOperator(t)) {

            // verificação mínima de segurança (opcional)
            if (s.top < 1) {
                printf("Erro: pilha sem operandos suficientes para operador '%s'\n", t);
                return NAN;
            }

            float b = popF(&s);
            float a = popF(&s);

            if (strcmp(t, "+") == 0) pushF(&s, a + b);
            else if (strcmp(t, "-") == 0) pushF(&s, a - b);
            else if (strcmp(t, "*") == 0) pushF(&s, a * b);
            else if (strcmp(t, "/") == 0) pushF(&s, a / b);
            else if (strcmp(t, "^") == 0) pushF(&s, powf(a, b));

        } else if (isFunction(t)) {

            if (s.top < 0) {
                printf("Erro: função '%s' sem argumento na pilha\n", t);
                return NAN;
            }

            float v = popF(&s);

            
            float rad = v * (float)M_PI / 180.0f;

            if (strcmp(t, "sin") == 0 || strcmp(t, "sen") == 0) {
                pushF(&s, sinf(rad));
            }
            else if (strcmp(t, "cos") == 0) {
                pushF(&s, cosf(rad));
            }
            else if (strcmp(t, "tan") == 0 || strcmp(t, "tg") == 0) {
               
                float c = cosf(rad);
                if (fabsf(c) < 1e-7f) {
                    printf("Erro: tangente indefinida para %f graus\n", v);
                    return NAN;
                }
                pushF(&s, tanf(rad));
            }

           
            else if (strcmp(t, "log") == 0 || strcmp(t, "log10") == 0) {
                if (v <= 0.0f) {
                    printf("Erro: log so aceita valores > 0\n");
                    return NAN;
                }
                pushF(&s, log10f(v));  
            }

        } else {
           
            pushF(&s, atof(t)); 
        }

        t = strtok(NULL, " ");
    }

    if (s.top != 0) {
        printf("Aviso: pilha resultou em %d elementos (esperado 1)\n", s.top + 1);
    }

    return popF(&s);
}
