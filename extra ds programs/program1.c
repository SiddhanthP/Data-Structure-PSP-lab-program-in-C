#include<stdio.h>
void create();
void display();
 int n,a[50],count=0;
 int main()
{
int ch;
while(1)
{
printf("\nARRAY OPERATIONS- MENU\n");
printf("1. CREATE AN ARRAY\n");
printf("2. DISPLAY ARRAY ELEMENTS\n");
printf("3. EXIT\n");
printf("ENTER YOUR CHOICE\n");
scanf("%d",&ch);
switch(ch)
{
case 1: if(count==0)
create();
else
printf("ARRAY ALREADY CREATED\n");
break;
case 2: if(count==0)
printf("array not created, create the array \n");
else
display();
break;
case 3: return(0);
default: printf("invalid choice\n");
}
}
}
void create()
{
int i;
printf("enter the number of elements\n");
scanf("%d",&n);
printf("enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
count=1;
}
void display()
{
int i;
printf("the array elements are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}