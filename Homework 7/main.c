//
//  main.c
//  Homework 7
//
//  Created by Sergey Kuznetsov on 16/09/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#include <stdio.h>


//typedef struct Vertex {
//    char label;
//    int flag;
//    struct Stack* children;
//
//    struct Vertex* prev;
//    struct Vertex* next;
//} Vertex;
//
//typedef struct Stack {
//    Vertex* head;
//    int size;
//} Stack;

void widthTravers(Vertex* start, int vertexCount)
{
    if(start->flag == 1)
    {
        return;
    }
    
    puts(&(start->label));
    
    Queue q; // TODO.
    
    q.add(start->children);
    
    while (q.length  > 0) {
        Vertex v = q.getNextElem();
        if(v.flag==0)
        {
            puts(&(v->label));
            
            for (int i=0; i<v->chldrenCount; i++) {
                if(v->children[i].flag==0)
                {
                    q.add(v->children[i])
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    // Solution 1.
    // widthTravers
    
    return 0;
}
