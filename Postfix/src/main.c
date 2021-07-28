/*
Programa de teste para as lib "postfix" e "cal_fix"

IMPORTANTE
Esse programa é uma implementação simples, não contem: 
tratamento de erros
operações com raiz e potenciação
operações implicitas a(b) ou ab == a*b
*/

#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
#include "cal_fix.h"



int main(){

    char text[] = "12 + 20 * 12 - (35 - 40)";//expressão infix aleatoria para teste
    size_t len = (sizeof(text)/sizeof(char));
    char *postfix = (char*)malloc(len);

    postfix = infix_to_postfix(text,len);

    if(postfix != NULL){
        printf("%d\n", calculate_postfix(postfix));
    }else printf("erro na converção\n");

    return 0;
}