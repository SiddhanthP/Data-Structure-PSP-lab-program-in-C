/*Desisn, develop and Implement a menu driven program in C for the follwoing operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
  a.Push an element on to Stack
  b.Pop an element from Stack
  c.Demonstrate Overflow and UnderFlow situations on Stack
  d. Display the status of the Stack
  e. Exit*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 4 // maxium stack size
#define ERROR_CODE 999

typedef struct
{
  int key;
} element;

element stack[MAX_STACK_SIZE];

int top = -1;

void push(element);
element pop(void);
void StackFull(void);
element StackEmpty(void);
void Display(void);

main()
{
  int ch;
  element item;

  while (1)
  {
    printf("\n");
    printf("enter the choice\n");
    printf("PUSH:1\nPOP:2\nDisplay:3\nExit:4\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
      printf("Enter the element  to be insert\n");
      scanf("%d", &item.key);
      push(item);
    }
    else if (ch == 2)
    {
      item = pop();
      if (item.key != ERROR_CODE)
        printf(" poout element from the stack is %d", item.key);
    }
    else if (ch == 3)
      Display();
    else if (ch == 4)
      exit(0);
    else
      printf("Enter valid choice\n");
  }
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
  else
  return stack[top--];
}

void StackFull()
{
  printf("OVERFLOW: Stack is Full, Cannot add elements\n");
}

element StackEmpty()
{
  element item;
  item.key = ERROR_CODE;
  printf("UNDERFLOW:Stack is Empty\n");
  return item;
}

void Display()
{
  int i;
  if (top != -1)
  {
    printf("Status of the Stack: stack elements are\n");
    for(i = top; i >= 0; i--)
      printf("%d\n", stack[i].key);
  }
  else
    printf("EMPTY STACK\n");
}
