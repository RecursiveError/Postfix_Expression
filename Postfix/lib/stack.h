/*
Programa stack.c
Autor: RecursiveError

uma simples implementação de stack somente para uso neste projeto
*/

#ifndef STACK_H
#define STACK_H

struct stack{
    int data;
    struct stack* prev;
};

//funções para manipular a stack
void push(int x, struct stack** top);
int pop(struct stack** top);
void full_delete(struct stack** top);
#endif