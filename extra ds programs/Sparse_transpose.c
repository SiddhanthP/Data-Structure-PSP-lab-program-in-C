#include <stdio.h>
#include <stdlib.h>
#define MAX_TERM 101
typedef struct
{
    int col;
    int row;
    int value;
} terms;
void transpose(terms[], terms[]);
terms a[MAX_TERM];
terms b[MAX_TERM];
int currentA = 1;
int main()
{
    int ele, m, n, r, c;
    printf("\nEnter the number of rows\n");
    scanf("%d", &r);
    printf("Enter the number of coloumns:\n");
    scanf("%d", &c);
    printf("Enter the number of non zero elements:\n");
    scanf("%d", &n);
    m = r * c;
    if (n < (m - n))
    {
        printf("It is sparse matrix !");
        a[0].row = r;
        a[0].col = c;
    }
    else
    {
        printf("\n It is not a sparse matrix,cannot add elements");
        return 0;
    }
    printf("Enter the elements:\n");
    for (int i = 1; i <= a[0].row; i++)
    {
        for (int j = 1; j <= a[0].col; j++)
        {
            scanf("%d", &ele);
            if (ele)
            {
                a[currentA].row = i - 1;
                a[currentA].col = j - 1;
                a[currentA++].value = ele;
                a[0].value++;
            }
        }
    }
    printf("\nThe sparse matrix entered is :\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < currentA; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    transpose(a, b);
    printf("\nThe sparse matrix after transpose is :\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < currentA; i++)
        printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
    return 0;
}
void transpose(terms a[], terms b[])
{
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;
    if (n > 0)
    {
        currentb = 1;
        for (i = 0; i < a[0].col; i++)
            for (j = 1; j <= n; j++)
                if (a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}