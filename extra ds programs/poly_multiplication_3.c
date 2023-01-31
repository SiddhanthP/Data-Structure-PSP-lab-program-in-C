#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct
{
    int coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void mull(int, int, int, int, int *, int *);
void simplifyPoly(int *, int *);
int main()
{
    int startA, startB, finishA, finishB, x, y;
    int *startD, *finishD;
    startD = &x;
    finishD = &y;
    int cf, i, degree1, degree2;
    
    printf("Enter the degree of polynomial 'A'\n");
    scanf("%d", &degree1);
    startA = avail;
    for (; degree1 >= 0; degree1--)
    {
        printf("Enter the coefficient of %dth term of polynomial 'A'\n", degree1);
        scanf("%d", &cf);
        if (cf != 0)
        {
            terms[avail].coef = cf;
            terms[avail++].expon = degree1;
        }
    }
    finishA = avail - 1;
    printf(" Polynomial A = \n");
    for (i = startA; i < finishA; i++)
    printf("%dx^%d + ", terms[i].coef, terms[i].expon);
    printf("%dx^%d = 0\n", terms[i].coef, terms[i].expon);
    
   
    printf("Enter the degree of polynomial 'B'\n");
    scanf("%d", &degree2);
    startB = avail;
    for (; degree2 >= 0; degree2--)
    {
        printf("Enter the coefficient of %dth term of polynomial 'B'\n", degree2);
        scanf("%d", &cf);
        if (cf)
        {
            terms[avail].coef = cf;
            terms[avail++].expon = degree2;
        }
    }
    finishB = avail - 1;
    printf(" Polynomial B = \n");
    for (i = startB; i < finishB; i++)
    printf("%dx^%d + ", terms[i].coef, terms[i].expon);
    printf("%dx^%d = 0\n", terms[i].coef, terms[i].expon);
    
    mull(startA, finishA, startB, finishB, startD, finishD);
    printf("Product of poly A X poly B =  \n");
    for (i = *startD; i < *finishD; i++)
    printf("%dx^%d + ", terms[i].coef, terms[i].expon);
    printf("%dx^%d = 0\n", terms[i].coef, terms[i].expon);

    return 0;
}
void mull(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    *startD = avail;
    for (int i = startA; i <= finishA; i++)
    {
        for (int j = startB; j <= finishB; j++)
        {
            terms[avail].coef = terms[i].coef * terms[j].coef;
            terms[avail++].expon = terms[i].expon + terms[j].expon;
        }
    }
    *finishD = avail - 1;
    simplifyPoly(startD, finishD);
}
void simplifyPoly(int *startD, int *finishD)
{
    for (int i = *startD; i <= *finishD; i++)
        for (int j = i + 1; j <= *finishD; j++)
            if (terms[i].expon == terms[j].expon)
            {
                terms[i].coef = terms[i].coef + terms[j].coef;
                for (int k = j; k <= *finishD; k++)
                    terms[k] = terms[k + 1];
                *finishD = *finishD - 1;
            }
}