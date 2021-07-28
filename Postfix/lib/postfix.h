/*
Programa: postfix.c
Autor: RecursiveError

lib para transforma expreções infix em postfix usando stacks
*/
#ifndef POSTFIX_H
#define POSTFIX_H
#include<stdlib.h>

char* infix_to_postfix(char* infix, size_t len);
#endif