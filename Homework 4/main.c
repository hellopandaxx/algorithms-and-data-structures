//
//  main.c
//  Homework 4
//
//  Created by Sergey Kuznetsov on 06/09/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#define N 5
#define M 5

#include <stdio.h>
#include <math.h>

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

void task1()
{
    printf("Map is %dx%d\n", N, M);
    
    int Map[N][N] =
    {
        {1, 1, 1, 1, 1 , 1, 1, 1},
        {1, 0, 1, 0, 1 , 1, 1, 1},
        {1, 0, 1, 1, 1 , 1, 1, 1},
        {1, 1, 1, 1, 1 , 1, 1, 1},
        {1, 1, 1, 1, 1 , 1, 1, 1},
        {1, 1, 1, 1, 1 , 1, 1, 1},
        {1, 1, 1, 1, 1 , 1, 1, 1},
        {1, 1, 1, 1, 1 , 1, 1, 1},
    };
    
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
}

// ============ Task 2 ==============

int board[N][M];

const int HorseMoves = 8;

int horseMoves[8][2] =
{
    {-2,-1},
    {-2,1},
    {-1,2},
    {1,2},
    {2,1},
    {2,-1},
    {1,-2},
    {-1,-2}
};

void applyHorseMove(int*x, int*y, int moveNumber)
{
    *x+=horseMoves[moveNumber][0];
    *y+=horseMoves[moveNumber][1];
}

int checkCoords(int x, int y)
{
    if(board[x][y]!=0)
        return 0;
    
    if(x<0||x>=N)
        return 0;
    
    if(y<0||y>=M)
        return 0;
    
    return 1;
}

int SearchSolution(int n, int x, int y)
{
    board[x][y] = n;
    
    if (n == N * M) return 1;
    
    for(int i = 0; i<HorseMoves; i++)
    {
        int nextN = x;
        int nextM = y;
        applyHorseMove(&nextN, &nextM, i);
        
        if(!checkCoords(nextN, nextM))
        {
            continue;
        }
        
        if (SearchSolution(n+1, nextN, nextM))
        {
            return 1;
        }
        
        board[nextN][nextM] = 0;
    }
    
    return 0;
}

void task2()
{
    Zero(N, M, board);
    SearchSolution(1, 0, 0);
    printf("\n\n");
    Print2(N, M, board);
}

int main(int argc, const char * argv[]) {
    
    task1();
    
    task2();
    
    return 0;
}
