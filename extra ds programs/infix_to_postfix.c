#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX_STACK_SIZE 100 // maxium stack size
#define ERROR_CODE 'E'
typedef struct
{
    char ch;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;
void push(element);
element pop(void);
void StackFull(void);
element StackEmpty(void);
int priority(element);
main()
{
    char infix[100];
    char postfix[100];
    char *e;
    int pos = 0;
    char temp;
    printf("\n");
    printf("Enter the Infix Expression\n");
    scanf("%s", infix);
    printf("\n");
    e = infix;
    element item;
    while (*e != '\0')
    {
        if (isalnum(*e))
            postfix[pos++] = *e;
        else if (*e == '(')
        {
            item.ch = *e;
            push(item);
        }
        else if (*e == ')')
        {
            while (1)
            {
                item = pop();
                if (item.ch == ERROR_CODE)
                {
                    printf("UNDERFLOW\n");
                    exit(0);
                }
                if (item.ch != '(')
                    postfix[pos++] = item.ch;
                else
                    break;
            }
        }

        else if (top == -1)
        {
            item.ch = *e;
            push(item);
        }
        else
        {
            item.ch = *e;
            while (priority(item) <= priority(stack[top]))
            {
                item = pop();
                postfix[pos++] = item.ch;
                item.ch = *e;
            }
            push(item);
        }
        e++;
    }
    while (top != -1)
    {
        item = pop();
        postfix[pos++] = item.ch;
    }
    postfix[pos] = '\0';
    printf("Postfix Expression is %s\n", postfix);
    printf("\n");
}

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1)
        StackFull();
    else
        stack[++top] = item;
}
element pop()
{
    if (top == -1)
        return StackEmpty();
    return stack[top--];
}
void StackFull()
{
    printf("OVERFLOW: Stack is Full, Cannot add elements\n");
}
element StackEmpty()
{
    printf("UNDERFLOW:Stack is Empty\n");
    element item;
    item.ch = ERROR_CODE;
    return item;
}
int priority(element item)
{

    if (item.ch == '(')
        return 0;
    if ((item.ch == '+') || (item.ch == '-'))
        return 1;
    if ((item.ch == '*') || (item.ch == '/'))
        return 2;
}