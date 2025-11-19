#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expressao.h"

#define MAX 512

// -------------------------------
// PILHA PARA STRINGS
// -------------------------------
typedef struct {
    char items[MAX][MAX];
    int top;
} StackStr;

void pushStr(StackStr *s, const char *str) {
    strcpy(s->items[++s->top], str);
}

char * popStr(StackStr *s) {
    return s->items[s->top--];
}

// -------------------------------
// PILHA PARA FLOATS
// -------------------------------
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

// -------------------------------
// VERIFICAÇÕES
// -------------------------------
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
           strcmp(t, "tg") == 0 ||
           strcmp(t, "log") == 0;  
}

// -------------------------------
// POSFIXA → INFIXA
// -------------------------------
char * getFormaInFixa(char *Str) {

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

// -------------------------------
// CALCULA VALOR DA EXPRESSÃO POSFIXA
// -------------------------------
float getValorPosFixa(char *StrPosFixa) {

    StackF s;
    s.top = -1;

    char expr[MAX];
    strcpy(expr, StrPosFixa);

    char *t = strtok(expr, " ");

    while (t != NULL) {

        if (isBinaryOperator(t)) {

            float b = popF(&s);
            float a = popF(&s);

            if (strcmp(t, "+") == 0) pushF(&s, a + b);
            else if (strcmp(t, "-") == 0) pushF(&s, a - b);
            else if (strcmp(t, "*") == 0) pushF(&s, a * b);
            else if (strcmp(t, "/") == 0) pushF(&s, a / b);
            else if (strcmp(t, "^") == 0) pushF(&s, pow(a, b));

        } else if (isFunction(t)) {

            float v = popF(&s);

            if (strcmp(t, "sin") == 0 || strcmp(t, "sen") == 0) pushF(&s, sin(v));
            else if (strcmp(t, "cos") == 0) pushF(&s, cos(v));
            else if (strcmp(t, "tan") == 0 || strcmp(t, "tg") == 0) pushF(&s, tan(v));
            else if (strcmp(t, "log") == 0) pushF(&s, log(v));   // ► ADICIONADO (log natural)

        } else {
            pushF(&s, atof(t));
        }

        t = strtok(NULL, " ");
    }

    return popF(&s);
}
