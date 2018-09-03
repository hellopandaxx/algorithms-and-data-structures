//
//  main.c
//  Homework 3
//
//  Created by Sergey Kuznetsov on 31/08/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ArrSize 20

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void fillArray(int N, int *a)
{
    for(int i = 0; i < N; i++)
        a[i] = rand()%100;
}

void copyArray(int *a, int *b, int n)
{
    for(int i=0; i<n; i++)
        b[i]=a[i];
}

void baseBubbleSort(int *a, int n, int *comparCount, int *swapCount)
{
    *swapCount = 0;
    *comparCount = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
        {
            (*comparCount)++;
            if (a[j] > a[j + 1])
            {
                (*swapCount)++;
                swap(&a[j], &a[j + 1]);
            }
        }
}

void modifiedBubbleSort(int *a, int n, int *comparCount, int *swapCount)
{
    *swapCount = 0;
    *comparCount = 0;
    for(int i = 0; i < n; i++)
        // From 0 to n - i - 1. This reduces amount of comparisions in 2 times.
        for(int j = 0; j < n - i - 1; j++)
        {
            (*comparCount)++;
            if (a[j] > a[j + 1])
            {
                (*swapCount)++;
                swap(&a[j], &a[j + 1]);
            }
        }
}

void shakeSort(int *a, int n, int *comparCount, int *swapCount)
{
    *swapCount = 0;
    *comparCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            for(int j = i/2; j < n-1-(i/2); j++)
            {
                (*comparCount)++;
                if (a[j] > a[j + 1])
                {
                    (*swapCount)++;
                    swap(&a[j], &a[j + 1]);
                }
            }
        }
        else
        {
            for (int q = n-1-(i/2); q>(i/2)+1; q--)
            {
                (*comparCount)++;
                if(a[q] < a[q-1])
                {
                    (*swapCount)++;
                    swap(&a[q], &a[q-1]);
                }
            }
        }
    }
}

int RLinearSearch(int *array, int length, int value)
{
    if(length<=0)
    {
        return -1;
    }
    
    if(*(array) == value)
    {
        return 0;
    }
    
    int result = RLinearSearch(++array, --length, value);
    
    return result<0 ? result : ++result;
}

int main(int argc, char *argv[]) {
    // 1. Modefied bubble sort.
    int N = ArrSize;
    int baseArray[N];
    fillArray(N, baseArray);
    
    int a[N], b[N];
    // Array for base Bubble sort testing.
    copyArray(baseArray, a, N);
    // Array for modified Bubble sort testing.
    copyArray(baseArray, b, N);
    
    puts("Array A before sort:");
    print(N, a);
    
    int comparCount, swapCount;
    baseBubbleSort(a, N, &comparCount, &swapCount);
    puts("Array A after base bubble sort:");
    print(N, a);
    
    printf("Length: %d\n", N);
    printf("Comparisions: %d\n", comparCount);
    printf("Swaps: %d\n", swapCount);
    
    printf("\n");
    puts("Array B before sort:");
    print(N, b);

    modifiedBubbleSort(b, N, &comparCount, &swapCount);
    puts("Array B after modified bubble sort:");
    print(N, a);
    
    printf("Length: %d\n", N);
    printf("Comparisions: %d\n", comparCount);
    printf("Swaps: %d\n", swapCount);
    
    // 2. Shake sort.
    puts("\nShake sort:");
    int c[N];
    copyArray(baseArray, c, N);
    shakeSort(c, N, &comparCount, &swapCount);
    print(N, c);
    printf("Comparisions: %d\n", comparCount);
    printf("Swaps: %d\n", swapCount);
    
    // 3. Recurrent linear search.
    puts("\nRecurrent linear search.");
    puts("The array:");
    int d[N];
    copyArray(baseArray, d, N);
    print(N, d);
    
    int value;
    puts("Input value for search:");
    scanf("%d", &value);
    
    int result = RLinearSearch(d, N, value);
    result<0? puts("No match.") : printf("The value %d is under index %d\n", value, result);

    return 0;
}
