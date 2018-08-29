//
//  main.c
//  Homework 1
//
//  Created by Sergey Kuznetsov on 25/08/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "solutions.h"

void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();
void menu();

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 4:
                solution4();
                break;
            case 5:
                solution5();
                break;
            case 6:
                solution6();
                break;
            case 7:
                solution7();
                break;
            case 8:
                solution8();
                break;
            case 9:
                solution9();
                break;
            case 10:
                solution10();
                break;
            case 0:
                printf("Bye-bye\n");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    
    return 0;
}

void menu()
{
    for (int i=1; i<=10; i++)
    {
        printf("%d - task%d\n", i, i);
    }
    
    printf("0 - exit\n");
}
