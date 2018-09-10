//
//  main.c
//  Homework 5
//
//  Created by Sergey Kuznetsov on 10/09/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#include "stack.h"

void binPrint()
{
    int x;
    while (pop(&x)) {
        printf("%d", x);
    }
    printf("\n");
}

void convertToBinRecur(long n)
{
    push(n%2);
    
    n /= 2;
    
    if(n == 0)
    {
        return;
    }
    
    convertToBinRecur(n);
}

int main(int argc, const char** argv) {
    Stack.maxSize = 100;
    
    // Solution 1.
    long x = 1000;
    
    convertToBinRecur(x);
    binPrint();
    
    // Solution 2.
    
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define T char

typedef struct Node {
    T data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

void push(List* lst, T value) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) return;
    temp->data = value;
    temp->next = lst->head;
    temp->prev = NULL;
    
    if (lst->head == NULL)
        lst->tail = temp;
    else
        lst->head->prev = temp;
    
    lst->size++;
    lst->head = temp;
}

T popStack(List* lst) {
    if (lst->size == 0)
        return-1;
    
    Node* tmp = lst->head;
    T value = tmp->data;
    lst->head = lst->head->next;
    if (lst->size > 1)
        lst->head->prev = NULL;
    else
        lst->tail = NULL;
    free(tmp);
    lst->size--;
    return value;
}


int main(int argc, const char** argv) {
    
    List st;
    st.size = 0;
    st.head = NULL;
    st.tail = NULL;
    push(&st, 'a');
    push(&st, 'b');
    push(&st, 'c');
    push(&st, 'd');
    push(&st, 'e');
    push(&st, 'f');
    while (st.size > 0) {
        printf("%c ", popStack(&st));
    }
    
    // Stack st;
    // init(&st);
    // push(&st, 'a');
    // push(&st, 'b');
    // push(&st, 'c');
    // push(&st, 'd');
    // push(&st, 'e');
    // push(&st, 'f');
    // push(&st, 'g');
    // while (st.size > 0)
    //     printf("%c ", pop(&st));
    
    // push('a');
    // push('b');
    // push('c');
    // push('d');
    // push('e');
    // push('f');
    // while(indx != -1)
    //     printf("%c", pop());
    
    return 0;
}
*/
