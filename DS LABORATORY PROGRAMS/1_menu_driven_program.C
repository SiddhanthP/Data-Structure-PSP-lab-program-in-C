/*/ Design, Develop and Implement a menu driven Program in C for the following Array
operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations */

#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_pos();
void del_pos();
int
n,a[150],count=0;
int main()
{
int ch;
while(1)
{
printf("\nARRAY OPERATIONS- MENU\n");
printf("1. CREATE AN ARRAY\n");
printf("2. DISPLAY ARRAY ELEMENTS\n");
printf("3. INSERT AN ELEMENT AT A POSITION\n");
printf("4. DELETE AN ELEMENT FROM A POSTION\n");
printf("5. EXIT\n");
printf("ENTER YOUR CHOICE\n");
scanf("%d",&ch);
switch(ch)
{
case 1: if(count==0||n==0)
create();
else
printf("ARRAY ALREADY CREATED\n");
break;
case 2: if(count==0||n==0)
printf("array not created, create the array \n");
else
display();
break;
case 3: if(count==0||n==0)
printf("array not created, create the array \n");
else
insert_pos();
break;
case 4: if(count==0||n==0)
printf("array not created,create array \n");
else
del_pos();
break;
case 5: return(0);
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
count++;
}
void display()
{
int i;
printf("the array elements are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
void insert_pos()
{
int i,pos,item;
printf("enter the position and value of the item to be inserted in the array\n");
scanf("%d%d",&pos,&item);
if(pos<0||pos>n+1)
{
printf("invalid position\n");
}
else
{
pos--;
for(i=n-1;i>=pos;i--)
a[i+1]=a[i];
a[pos]=item;
n++;
}
}
void del_pos()
{
int i,pos,val;
printf("enter the position of the element to be deleted\n");
scanf("%d",&pos);
if(pos<0||pos>n)
{
printf("invalid position\n");
}
else
{
val=a[--pos];
for(i=pos;i<n-1;i++)
a[i]=a[i+1];
n--;
printf("the element deleted is %d\n",val);
}
}