#ifndef STACK_FUN_IMPL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_function.h"

typedef struct stack
{
    int capacity;
    int top;
    Node **pin;
} St;

St *create_stack(int capacity)
{
    St *stack = (St *)malloc(sizeof(St));

    stack->capacity = capacity;

    stack->top = -1;

    stack->pin = (Node **)malloc(stack->capacity * sizeof(Node *));

    return stack;
}

bool isEmpty(St *stack)
{
    return (stack->top == -1);
}

bool isFull(St *stack)
{
    return stack->top - 1 == stack->capacity;
}

void push(St *stack, Node *ak)
{
    if (isFull(stack))
    {
        printf("stack is full\n");
        return;
    }
    else
    {
        stack->pin[++stack->top] = ak;
    }
}

Node *pop(St *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is empty\n");
    }

    return stack->pin[stack->top--];
}

Node *peek(St *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is empty\n");

        return NULL;
    }
    return stack->pin[stack->top];
}

#endif