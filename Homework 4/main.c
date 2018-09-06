//
//  main.c
//  Homework 4
//
//  Created by Sergey Kuznetsov on 06/09/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#define N 4
#define M 4

#include <stdio.h>

void Print2(int n, int m, int a[N][M])
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void Zero(int n, int m, int a[N][M])
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            a[i][j] = 0;
}

int main(int argc, const char * argv[]) {
    printf("Map is %dx%d\n", N, M);
    
    int Map[N][N] =
    {
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1}};
    
    /*
    puts("Enter Map:");
    puts("(1 for opened, 0 for closed)");
    for(int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            int n;
            printf("[%d:%d]: ", i, j);
            scanf("%d", &n);
            Map[i][j] = n;
        }
    }
     */
    
    puts("The map:");
    Print2(N, M, Map);
    
    int A[N][M];
    Zero(N, M, A);
    
    int i, j;
    for(j = 0; j < M; j++)
    {
        if(Map[0][j])
        {
            A[0][j] = 1;
        }
        else
        {
            break;
        }
    }
    
    for(i = 1; i < N; i++)
    {
        if(Map[i][0])
            A[i][0] = 1;
        else
            break;
    }
    
    for (int i =1; i<N; i++) {
        for (int j = 1; j<M; j++) {
            A[i][j] = Map[i][j] ? A[i][j-1] + A[i-1][j] : 0;
        }
    }
    
    puts("The result:");
    Print2(N, M, A);
    
    return 0;
}
