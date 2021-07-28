/*
Programa stack.c
Autor: RecursiveError

uma simples implementação de stack somente para uso neste projeto
*/

#include"stack.h"
#include<stdlib.h>

int pop(struct stack** top){
    if(top == NULL) return -1;
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    int result = (*top)->data;
    temp = *top;
    *top = (*top)->prev;
    free(temp);
    return result;
}


void push(int x, struct stack** top){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = x;
    temp->prev = *top;
    *top = temp; 
}

//limpa toda stack
void full_delete(struct stack** top){
    while(*top != NULL){
        pop(top);
    }
}
