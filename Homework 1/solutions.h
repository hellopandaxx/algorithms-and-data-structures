//
//  solutions.h
//  Homework 1
//
//  Created by Sergey Kuznetsov on 26/08/2018.
//  Copyright © 2018 Sergey Kuznetsov. All rights reserved.
//

#ifndef solutions_h
#define solutions_h


#endif /* solutions_h */

// ==================== Solution 1 ====================
// Body index.
void solution1()
{
    printf("Solution 1\n");
    
    int weight, height;
    printf("Enter your weight in kg:\n");
    scanf("%d", &weight);
    
    if(weight<=0)
    {
        printf("Weight should be greater then zero kg.");
        return;
    }
    
    printf("Enter your height in sm:\n");
    scanf("%d", &height);
    
    if(height<=0)
    {
        printf("Height should be greater then zero sm.");
        return;
    }
    
    double heightInMeters = height / 100.0;
    
    double bodyIndex = weight / (heightInMeters * heightInMeters);
    
    printf("The body index is: %0.2f\n", bodyIndex);
}

// ==================== Solution 2 ====================
// Swap values.
void solution2()
{
    printf("Solution 2\n");
    
    int a, b;
    printf("Enter a:\n");
    scanf("%d", &a);
    
    printf("Enter b:\n");
    scanf("%d", &b);
    
    printf("Swap values using the third value:\n");
    int c = a;
    a = b;
    b = c;
    
    printf("a = %d, b = %d\n", a, b);
    
    printf("Swap values back without the third value:\n");
    a = a^b;
    b = b^a;
    a = a^b;
    printf("a = %d, b = %d\n", a, b);
}

// ==================== Solution 3 ====================
// Quadratic equation.
void solution3()
{
    printf("Solution 3\n");
    
    float a,b,c;
    printf("Enter the coefficients of the quadratic equation:\n");
    printf("a=");
    scanf("%f", &a);
    printf("b=");
    scanf("%f", &b);
    printf("c=");
    scanf("%f", &c);
    
    float d = b*b - 4*a*c;
    
    if(d<0)
    {
        printf("There are no roots of equation.\n");
        return;
    }
    
    float x1, x2;
    if(d>0)
    {
        x1 = (-b-sqrt(d))/(2*a);
        x2 = (-b+sqrt(d))/(2*a);
        printf("X1 = %f\nX2 = %f\n", x1, x2);
    }
    else
    {
        x1 =(-b)/(2*a);
        printf("X = %f\n", x1);
    }
}

// ==================== Solution 4 ====================
// Seasons of year.
void solution4()
{
    printf("Solution 4\n");
    
    int m;
    printf("Enter month's number:");
    scanf("%d", &m);
    
    if( m<1 || m> 12)
    {
        printf("The number of a month should be between 1 and 12");
        return;
    }
    
    m%=12;
    m/=3;
    
    switch (m) {
        case 0:
            printf("Winter.\n");
            break;
        case 1:
            printf("Spring.\n");
            break;
        case 2:
            printf("Summer.\n");
            break;
        case 3:
            printf("Fall.\n");
            break;
    }
}

// ==================== Solution 5 ====================
// N years.
void solution5()
{
    printf("Solution 5\n");
    
    printf("Enter age:");
    
    int age;
    scanf("%d", &age);
    
    if(age<1 || age>150)
    {
        printf("Age should be between 1 and 150 year");
    }
    
    char* litheral="";
    
    if(age % 10 == 1 && (age % 100 != 11))
        litheral = "Год";
    else if ((age % 10 >= 2 && age % 10 < 5) &&
             !(age % 100 >= 12 && age % 100 < 15))
        litheral = "Года";
    else
        litheral = "Лет";
    
    printf("%d %s\n5", age, litheral);
}

// ==================== Solution 6 ====================
// Chees desk sells color.
void solution6()
{
    printf("Solution 6\n");
    
    int x1, x2, y1, y2;
    printf("Enter X1:");
    scanf("%d", &x1);
    
    printf("Enter Y1:");
    scanf("%d", &y1);
    
    printf("Enter X2:");
    scanf("%d", &x2);
    
    printf("Enter Y2:");
    scanf("%d", &y2);
    
    int a = (x1%2 == x2%2);
    int b = (y1%2 == y2%2);
    
    // The remainder of dividing by two should be the same for the same color.
    int result = a^b;
    
    if(result == 1)
    {
        printf("Not the same color.\n");
    }
    else
    {
        printf("The same color.\n");
    }
}

// ==================== Solution 7 ====================
// Quotient and remainder with + and - only.
void solution7()
{
    printf("Solution 7\n");
    
    int n, k;
    printf("Enter N:");
    scanf("%d", &n);
    
    printf("Enter K:");
    scanf("%d", &k);
    
    if(k==0)
    {
        printf("K can't be zero.");
        return;
    }
    
    if(n<0 || k<0)
    {
        printf("N and K should be positive numbers.");
        return;
    }
    
    int quotient = 0, remainder = 0;
    
    while(n != 0)
    {
        int a = n - k;
        if(a >= 0)
        {
            n = a;
            quotient++;
        }
        else
        {
            remainder = n;
            break;
        }
    }
    
    printf("The quotient is %d, the remainder is %d.\n", quotient, remainder);
}

// ==================== Solution 8 ====================
// Is there odd digit in the number.
void solution8()
{
    printf("Solution 8\n");
    
    int n;
    printf("Enter N:");
    scanf("%d", &n);
    
    while (n>0) {
        int x = n%10;
        if(x%2 != 0)
        {
            printf("True\n");
            return;
        }
        
        n/=10;
    }
    
    printf("False\n");
}

// ==================== Solution 9 ====================
// Random generator from 1 to 100.
const int A = 12;
const int B = 27;

const int InitValue = 1;
// The top of the sequence.
const int M = 100;

int rands[M];
int initialized = 0;
int counter = 0;

void solution9()
{
    printf("Solution 9\n");
    if(!initialized)
    {
        rands[0] = InitValue;
        
        for(int i = 1; i<M; i++)
        {
            rands[i] = (A*rands[i-1] + B) % M;
        }
        
        initialized = 1;
    }
    
    int result = rands[counter];
    counter++;
    counter%=M;
    
    printf("%d\n", result);
}

// ==================== Solution 10 ====================
// Automorphic numbers.

int getDigitsCount(int);
int getLastNDigitsNumber(int, int);

void solution10()
{
    printf("Solution 10\n");
    
    int n;
    printf("Enter N:");
    scanf("%d", &n);
    
    for (int i = 0; i<=n; i++) {
        int c = getDigitsCount(i);
        int i2 = i*i;
        
        if(i == getLastNDigitsNumber(i2, c))
        {
            printf("%d\n", i);
        }
    }
}

int getDigitsCount(int x)
{
    if(x<0)
    {
        x = -x;
    }
    
    int counter = 0;
    while (x>0) {
        x/=10;
        counter++;
    }
    return counter;
}

int getLastNDigitsNumber(int x, int n)
{
    int result = 0;
    for(int i = 0; i<n; i++)
    {
        result += (x%10 * pow(10,i));
        x/=10;
    }
    
    return result;
}
