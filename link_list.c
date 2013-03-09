#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void insert(int value);
void delete(int value);
void show(void);

struct node
{
int value;
int pos;
struct node* next;
};

struct node *head=NULL;
int x=0;


int main()
{
int sel=0;
while(1)
{
printf("Please select any one of the option\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Show\n");
printf("4. Exit\n");

scanf("%d", &sel);

if(sel==1)
{
int val=0;
printf("\nInsert the value you want to insert\n");
scanf("%d",&val);
printf("%d will be inserted at the end of the list\n", val);
insert(val);
}

else if (sel==2)
{
int val=0;
printf("\nInsert the value you want to remove\n");
scanf("%d", &val);
printf("The value to be removed from the list is %d\n", val);
delete(val);
}

else if (sel ==3)
{
printf("\nThe link list is \n");
show();
}

else if (sel==4)
break;

else 
printf("\nInvalid input \n");
}
}

void insert(int num)
{

	struct node *n = malloc(sizeof(struct node));
	n->value=num;
	n->pos = x;
	n->next=NULL;
if(x==0)
{
head=n;
}
else
{

struct node *temp = head;

while (temp->next !=NULL)
{
temp = temp->next;
}

temp->next=n;
}

x++;

}


void delete(int num)
{
struct node* temp=head;
struct node* prev=head;
if(temp == NULL)
printf("List Empty\n");
else
{
while(temp != NULL)
{
 	if(temp->value == num)
	{
		if (temp==head)
		{
		head=temp->next;
		}
		else
		prev->next=temp->next;
		
		free(temp);	
		break;
	}
	else
	{	
		prev=temp;
		temp=temp->next;	
		
	}
}
if(temp == NULL)
printf("%d is not in the list. Sorry.. can't delete what doesn't exists \n",num);


}

}

void show()
{
struct node *temp = head;
if(head == NULL)
printf("The list is empty\n");
while(temp != NULL)
{
printf("----  %d  ---- ", temp->value);
temp=temp->next;
}
printf("\n\n");

}


