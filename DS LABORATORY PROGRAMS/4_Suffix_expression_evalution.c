#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100 // maxium stack size
#define ERROR_CODE 'E'
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
int main()
{
   int num;
   char postfix[100];
   char *e;
   element item1, item2, item3, item;
   char temp;
   printf("\n");
   printf("Enter the Postfix Expression\n");
   scanf("%s", postfix);
   printf("\n");
   e = postfix;

   while (*e != '\0')
   {
      if (isdigit(*e))
      {
         num = *e - 48;
         item.key = num;
         push(item);
      }
      else
      {
         item1 = pop();
         item2 = pop();
         switch (*e)
         {
         case '+':
            item3.key = item2.key + item1.key;
            break;
         case '-':
            item3.key = item2.key - item1.key;
            break;
         case '*':
            item3.key = item2.key * item1.key;
            break;
         case '/':
            item3.key = item2.key / item1.key;
            break;
         }
         push(item3);
      }
      e++;
   }
   item = pop();
   printf("\n The result of postfix Expression %s = %d\n", postfix, item.key);
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
   item.key = ERROR_CODE;
   return item;
}
