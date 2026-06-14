#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 1000

/*--------------------------------------------------
  PILA
--------------------------------------------------*/

typedef struct {
    int data[MAX_STACK];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

/*--------------------------------------------------
  OPERADORES
--------------------------------------------------*/

int aplicar_operador(int a, int b, char op) {

    switch(op) {

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        default:
            return 0;
    }
}

/*--------------------------------------------------
  EVALUADOR POSTFIJO
--------------------------------------------------*/

int evaluar_posfijo(const char *expresion) {

    Stack pila;
    pila.top = -1;

    char copia[1000];
    strcpy(copia, expresion);

    char *token = strtok(copia, " ");

    while(token != NULL) {

        if(isdigit(token[0])) {

            push(&pila, atoi(token));

        } else {

            int b = pop(&pila);
            int a = pop(&pila);

            int resultado =
                aplicar_operador(a, b, token[0]);

            push(&pila, resultado);
        }

        token = strtok(NULL, " ");
    }

    return pop(&pila);
}



