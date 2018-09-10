//
//  stack.h
//  Homework 5
//
//  Created by Sergey Kuznetsov on 10/09/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#ifndef stack_h
#define stack_h


#endif /* stack_h */

#include <stdio.h>
//#include <malloc.h>

#include <stdlib.h>

#define T int
// Опишем структуру узла списка
struct TNode
{
    T value;
    struct TNode *next;
};
typedef struct TNode Node;
struct Stack
{
    Node *head;
    int size;
    int maxSize;
};
struct Stack Stack;
void push(T value)
{
    if (Stack.size >= Stack.maxSize) {
        printf("Error stack size");
        return;
    }
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

int pop(T* value) {
    if (Stack.size == 0)
    {
        // printf("Stack is empty");
        return 0;
    }
    // Временный указатель
    Node* next = NULL;
    // Значение "наверху" списка
    //T value;
    *value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    Stack.size--;
    return 1;
}
void PrintStack()
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}
