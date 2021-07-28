/*
Programa: postfix.c
Autor: RecursiveError

lib para transforma expressões infix em postfix usando stacks
*/

#include "postfix.h"
#include "stack.h"
#include <stdlib.h>

//funções para verificar a sintaxe das expressões
char is_pair(char open, char close);
int check_balence(char* string);

//funções para realizar pequenas operações uteis
int operator(char op);
int higher_precedence(char op1, char op2);
int operator_weight(char op);

//trasforma infix em postfix
//recebe um ponterio char e o numero de elementos
//retorna NULL em caso de erro
//retona um ponteiro char do mesmo tamanho de infix em caso de sucesso 
char* infix_to_postfix(char* infix, size_t size){
    if(!check_balence(infix))return NULL;
    struct stack* top = NULL;
    char* postfix = (char*) malloc(size);
    size_t i = 0;
    size_t c = 0; 
    while(infix[i] != '\0'){
        if(operator(infix[i])){
            while((top != NULL) && top->data != '(' && higher_precedence(top->data, infix[i])){
                postfix[c] = pop(&top);
                c++;
            }push(infix[i], &top);
        }
        else if(infix[i] == ' '){
            postfix[c] = infix[i];
            c++;
        }
        else if(infix[i] == '('){
            push(infix[i], &top);
        }
        else if(infix[i] == ')'){
            while((top != NULL) && (top->data != '(')){
                postfix[c] = pop(&top);
                c++;
            }pop(&top);
        }
        else{
            postfix[c] = infix[i];
            c++;
        }
        i++;
    }
    while(top != NULL){
        postfix[c] = pop(&top);
        c++;
    }
    return postfix;
}
//funções para realizar pequenas operações uteis

//retorna true caso a entada seja um operador
//AVISO: apenas + - * / são operadores validos
int operator(char op){
    return op == '+' || op == '-' || op == '*' || op == '/';
}

//retorna o peso do oprador
//EX: multiplicação e divisão devem ser calculados primeiro logo tem um "peso" maior
int operator_weight(char op){
    if((op == '+') || (op == '-'))return 1;
    if((op == '*') || (op == '/'))return 2;
    return -1;
}

//retorna true caso o primeiro argumento tenha maior procedencia que o segundo
//caso contrario retorna falso
int higher_precedence(char op1, char op2){
    int w_op1 = operator_weight(op1);
    int w_op2 = operator_weight(op2);
    return w_op1 >= w_op2 ? 1 : 0;
}

//funções para verificar a sintaxe das expressões

//retorna true caso os arqumentos sejam simbolos par (abertura e fechamento)
char is_pair(char open, char close){
    if((open == '(') && (close == ')')) return 1;
    else if((open == '[') && (close == ']')) return 1;
    else if((open == '{') && (close == '}')) return 1;
    return 0;
}

//checa se a quantidade de chaves esta correta
int check_balence(char* string){
    struct stack* top = NULL;
    size_t i = 0;
    while(string[i] != '\0'){
        switch(string[i]){
            case '(':
            case '[':
            case '{':
                push(string[i], &top);
            break;
            case ')':
            case ']':
            case '}':
            if(top == NULL || !is_pair(top->data, string[i])){
                full_delete(&top);
                return 0;
            }
            pop(&top);
            break;
        }
        i++;
    }
    int result = top==NULL ? 1 : 0;
    full_delete(&top);
    return result;
}


