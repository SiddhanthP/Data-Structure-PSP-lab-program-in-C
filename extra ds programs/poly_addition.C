// Polynomial Addition

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100 // size of terms array
typedef struct
{
    int coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

void padd(int, int, int, int, int *, int *);
void attach(int, int);
int COMPARE(int, int);

main()
{
    int startA, startB, finishA, finishB, x = 0, y = 0;
    int *startD;
    int *finishD;
    int degree1, degree2, i;
    int cf;

    finishD = &x;
    startD = &y;

    // Reading Polynomial A
    printf("Enter the degree of a Polynomial-A\n");
    scanf("%d", &degree1);
    startA = avail;

    for (; degree1 >= 0; degree1--)
    {
        printf("Enter the coffcient for %dth term of Polynomial-A\n", degree1);
        scanf("%d", &cf);
        if (cf)
        {
            terms[avail].coef = cf;
            terms[avail++].expon = degree1;
        }
    }

    finishA = avail - 1;

    printf("----Polynomial-A----\n");
    i = startA;
    for (; i < finishA; i++)
        printf(" %dX^%d +", terms[i].coef, terms[i].expon);
    printf(" %dX^%d  = 0\n", terms[i].coef, terms[i].expon);

    // Reading Polynomial B
    printf("\n \n");
    printf("Enter the degree of a Polynomial-B\n");
    scanf("%d", &degree2);

    startB = avail;

    for (; degree2 >= 0; degree2--)
    {
        printf("Enter the coffcient for %dth term of Polynomial-B\n", degree2);
        scanf("%d", &cf);
        if (cf)
        {
            terms[avail].coef = cf;
            terms[avail++].expon = degree2;
        }
    }

    finishB = avail - 1;

    printf("----Polynomial-B----\n");
    i = startB;
    for (; i < finishB; i++)
    printf(" %dX^%d +", terms[i].coef, terms[i].expon);
    printf(" %dX^%d  = 0\n", terms[i].coef, terms[i].expon);

    printf(" \n \n");

    padd(startA, finishA, startB, finishB, startD, finishD);

    printf("----Polynomial-D----\n");
    for (; *startD < *finishD; (*startD)++)
        printf(" %dX^%d +", terms[*startD].coef, terms[*startD].expon);
    printf(" %dX^%d  = 0\n", terms[*startD].coef, terms[*startD].expon);
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    int *fD;
    //*finishD1 =0;
    // Add A(x) & B(x) to obtain D(x)
    printf("hello\n");
    int coeffcient;
    *startD = avail;
    printf(" startD = %d\n", *startD);

    while (startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon, terms[startB].expon))
        {
        case -1: // a expon < b expon
            attach(terms[startB].coef, terms[startB].expon);
            startB++;

        case 0: // Equal exponents
            coeffcient = terms[startA].coef + terms[startB].coef;
            printf(" case 0\n");
            if (coeffcient)
                attach(coeffcient, terms[startA].expon);
            startA++;
            startB++;
            break;
        case 1: // a expon > b expon
            attach(terms[startA].coef, terms[startA].expon);
            startA++;
        }

    // Add in remaining terms of A(x)
    for (; startA <= finishA; startA++)
    {
        attach(terms[startA].coef, terms[startA].expon);
        printf("remain\n");
    }

    // Add in remaining terms of B(x)
    for (; startB <= finishB; startB++)
    {
        attach(terms[startB].coef, terms[startB].expon);
        printf("remain\n");
    }
    printf("Avail =%d\n", avail);
    *finishD = avail - 1;
    printf(" hello1\n");
}

void attach(int coeffcient, int exponent)
{ // Add a new term to he polynmial
    if (avail >= MAX_TERMS)
    {
        printf("Too many terms he polynmial \n");
        exit(0);
    }
    printf("attach %d\n", avail);
    terms[avail].coef = coeffcient;
    terms[avail++].expon = exponent;
    printf("attach %d\n", avail);
}

int COMPARE(int x, int y)
{
    if (x < y)
        return (-1);
    else if (x == y)
        return (0);
    else
        return (1);
}