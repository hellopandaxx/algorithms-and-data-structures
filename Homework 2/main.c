//
//  main.c
//  Homework 2
//
//  Created by Sergey Kuznetsov on 29/08/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#define ARR_SIZE 100

int bin[ARR_SIZE] = {0};
int size = 0;

void binPrint()
{
    int i;
    for(i = size - 1; i >= 0; i--)
        printf("%d", bin[i]);
    printf("\n");
}

void convertToBinRecur(long n)
{
    bin[size++] = n % 2;
    
    n /= 2;
    
    if(n == 0)
    {
        return;
    }
    
    convertToBinRecur(n);
}

int myPow(int a, int b)
{
    if(a == 0)
    {
        return a;
    }
    
    if(b == 0)
    {
        return 1;
    }
    
    if(b == 1)
    {
        return a;
    }
    
    return a * myPow(a, --b);
}

int myPow2(int a, int b)
{
    if(a == 0)
    {
        return a;
    }
    
    if(a == 1 || b == 0)
    {
        return 1;
    }
    
    if(b == 1)
    {
        return a;
    }
    
    if(b % 2)
    {
        return a * myPow2(a, --b);
    }
    else
    {
        return myPow2(a*a, b/2);
    }
}

int calcCommand(int x, int commandNumber)
{
    switch (commandNumber) {
        case 0:
            return ++x;
            case 1:
            return x*=2;
            
        default:
            return -1;
    }
}

int counter = 0;
const int CALC_COMMANDS_AMOUNT = 2;

bool checkResult(int a, int b)
{
    if(a == b)
    {
        counter++;
        return true;
    }
    
    return false;
}

void calc(int a, int b)
{
    for (int i = 0; i<CALC_COMMANDS_AMOUNT; i++) {
        int result = calcCommand(a, i);
        checkResult(a, b);
        if(a<b)
        {
            calc(result, b);
        }
    }
}

int main(int argc, char *argv[])
{
    // 1.
    long n = 1024;
    convertToBinRecur(n);
    printf("%ld in binary is ", n);
    binPrint();
 
    // 2.
    int x = 2;
    int p = 10;
   
    printf("%d pow %d = %d\n", x, p, myPow(x, p));

    // 2*.
    printf("%d pow %d = %d\n", x, p, myPow2(x, p));
    
    // 3.
    int a = 3;
    int b = 20;
    calc(a, b);
    printf("There are %d programms to make %d from %d\n", counter, b , a);
    
    return 0;
}






