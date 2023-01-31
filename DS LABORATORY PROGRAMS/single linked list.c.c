# include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*new,*head,*tail;

int i,n=0;
void Display (void);
void Insert (void); 
void Delete (void);
void search (int x);
int sort (void);

int main()
{
int ch;
int value;
do
{
new = (struct node*) malloc(sizeof(struct node));
printf ("Enter the value:");
scanf ("%d",&value);
new->data = value ;
new->next = NULL ;
if(head == NULL)
{
head=new;
tail=new;
}
else
{
tail -> next=new;
tail=new;
}
n = n+1; 
printf("Enter 1 to Continue, 2 to exit\n");
scanf ("%d",&ch);
}while (ch==1);
while (1)
{
printf("Enter the choice\n 1 - Insert\n 2 - Delete\n 3 - Display\n 4 - Search\n 5 - Sort\n 6 - exit\n");
scanf("%d",&ch);

if (ch==1)
Insert();
else if (ch==2)
Delete();
else if (ch==3)
Display();
else if (ch==4)
{
printf("Enter element to be searched \n");
scanf("%d",&value);
search(value);
}
else if (ch==5)
sort();
else if(ch==6)
exit(0);
else
printf("Enter appropriate choice\n");
}
return 0;
}

void Display (void)
{
struct node *temp = head;
while (temp != NULL )
{
printf ("%d\t", temp->data);
temp = temp->next;
}
printf ("\n");
}

void Insert (void)
{
int pos,value;
printf("Enter the element to be insested:\n");
scanf("%d",&value);
printf("Enter the position to be insexted:\n");
scanf("%d", &pos);
if(pos==0)
{
new = (struct node*) malloc(sizeof (struct node));
new -> data = value;
new -> next = head;
head = new ;
}
else if ( pos==n)
{
new -> data = value ;
tail -> next = new;
new -> next = NULL;
tail = new ;
}
else
{
struct node *temp=head;
for (int i=0; i<pos-1; i++)
temp = temp->next;
new = (struct node*)malloc(sizeof(struct node)); 
new -> data = value;
new -> next = temp -> next;
temp -> next = new;
}
n=n+1;
}

void Delete (void)
{
int pos;
printf("Enter the position for Deletion \n");
scanf("%d",&pos);
struct node *temp=head;
if(pos==0)
{
head = head->next;
temp->next=NULL;
}
else if (pos == n-1)
{
while (temp->next !=tail)
temp = temp->next;
temp -> next = NULL;
tail = temp;
}
else
{
for (i=0 ; i<pos-1 ; i++)
temp = temp -> next;
temp->next = temp->next->next;
}
    n=n-1;
}

void search (int x )
{
int flag =0,pos;
struct node *p = head;
while (p != NULL)
{
if (p->data=x)
{
flag = 1;
break;
}
p=p->next;
}
if (flag == 1)
printf("Element found at %d\n",pos);
else
printf("Element Not found \n");
}

int sort(void)
{
    int temp;
    struct node *t1,*t2;
    for(t1=head;t1->next!=NULL; t1=t1->next)
    {
        for(t2=head;t2->next!=NULL;t2=t2->next)
        {
            if(t2->data > t2->next->data)
        {
            temp=t2->data;
            t2->data=t2->next->data;
            t2->next->data=temp;
        }
    }
}
}

