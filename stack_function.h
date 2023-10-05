#ifndef STACK_FUN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_function_impl.h"

St *create_stack(int capacity);
bool isEmpty(St *stack);
bool isFull(St *stack);
void push(St *stack, Node *ak);
Node *pop(St *stack);
Node *peek(St *stack);

#endif