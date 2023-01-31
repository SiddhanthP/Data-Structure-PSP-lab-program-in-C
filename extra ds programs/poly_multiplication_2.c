#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void init(int p[]);
void read(int p[]);
void print(int p[]);
void multiply(int p1[], int p2[], int p3[]);

void main()
{
    int p1[MAX], p2[MAX], p3[MAX];
    int ch;
    while (1)
    {
        printf("\n1:create 1st polynomial\n");
        printf("2:create 2nd polynomial\n");
        printf("3:Multiply polynomials\n");
        printf("4:Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            read(p1);
            break;
        case 2:
            read(p2);
            break;
        case 3:
            multiply(p1, p2, p3);
            printf("\n1st polynomial= ");
            print(p1);
            printf("\n2nd polynomial=");
            print(p2);
            printf("\nProduct = ");
            print(p3);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}

void read(int p[])
{
    int n, i, power, coeff;
    init(p);
    printf("Enter number of terms:\n");
    scanf("%d", &n);
    /* read n terms */
    for (i = 0; i < n; i++)
    {
        printf("enter a term(power,coeff)\n");
        scanf("%d %d", &power, &coeff);
        p[power] = coeff;
    }
}
void print(int p[])
{
    int i;
    for (i = 0; i < MAX; i++)
        if (p[i] != 0)
            printf("%dX^%d ", p[i], i);
}

void multiply(int p1[], int p2[], int p3[])
{
    int i, j;
    init(p3);
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            p3[i + j] = p3[i + j] + p1[i] * p2[j];
}
void init(int p[])
{
    int i;
    for (i = 0; i < MAX; i++)
        p[i] = 0;
}