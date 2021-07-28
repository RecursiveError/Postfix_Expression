/*
Programa: cal_fix.c
Autor: RecursiveError

lib para calcular expressões postfix
*/
#include "stack.h"
#include "cal_fix.h"
#include <stdlib.h>

//funções para realizar pequenas operações uteis
int is_numeric(char c);
int is_operator(char c);
int calculate(char op, int num1, int num2);


int calculate_postfix(char* postfix){
    struct stack* top = NULL;
    size_t i = 0;
    while(postfix[i] != '\0'){
        if(is_numeric(postfix[i])){
            int num = 0;
            while(is_numeric(postfix[i])){
                num *= 10;
                num += (postfix[i] - '0');
                i++; 
            }
            i--;
            push(num, &top);
        }else if(is_operator(postfix[i])){
            int num2 = pop(&top);
            int num1 = pop(&top);
            int result = calculate(postfix[i], num1, num2);
            push(result, &top);
        }
        i++;
    }
    return pop(&top);
}


//funções para realizar pequenas operações uteis

//retona se o char é um numero ou não
int is_numeric(char c){
    return (c >= '0' && c<= '9');
}

//retorna se o char é um operador
//AVISO: apenas + - * / são operadores validos
int is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
} 

int calculate(char op, int num1, int num2){
    if(op == '+')return num1 + num2;
    else if(op == '-')return num1 - num2;
    else if(op == '*')return num1 * num2;
    else if(op == '/')return num1 / num2;
    return 0;
}