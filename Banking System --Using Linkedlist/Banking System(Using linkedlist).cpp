#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Bank{
	char name[100];
	int adhar;
	char profession[100];
	char address[1000];
	int balance;
	int fix;
	int ac;
	struct Bank *next;
	}node;

node *start=NULL;


node* createnode()
{
	node *n;
	n=(node*)malloc(sizeof(node));
	return(n);
}


void insert()
{
	node *temp,*prev;
	temp=createnode();
	int value1;
	char ch[100];
	printf("\n\t\tEnter the name:- ");
	scanf("%s",temp->name);
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				printf("\n\t\tId already exists");
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}

	if(flag==0)
	{	
		temp->adhar=value1;
		fflush(stdin);
		printf("\n\t\tEnter the profession:- ");
		scanf("%s",temp->profession);
		fflush(stdin);
		printf("\n\t\tEnter the address:- ");
		scanf("%s",temp->address);
		fflush(stdin);
		printf("\n\t\t1000 diposited in this account\n ");
		temp->balance=1000;
		printf("\n\t\tEnter the fix diposit:- ");
		scanf("%d",&temp->fix);
		if(temp->fix<0)
		{
			temp->fix=0;
		}
		int acc=rand()%989785;
		printf("\n\t\tUnique bank ac id. is %d\n",acc);
		temp->ac=acc;
		temp->next=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			node *t;
			t=start;
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;
	}
	}
}



void widraw()
{
	int value1;
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}
	
	if(flag==1)
	{
		node *t=search;
		int limit;
		printf("\n\t\tEnter the amount");
		scanf("%d",&limit);
		if(limit>0 && limit<t->balance)
		{
			t->balance-=limit;
			printf("\n\t\t%d debited from account no. %d\n",limit,t->ac);
			printf("\n\t\tYour current balance is %d\n",t->balance);
		}
		else
			printf("\n\t\tEnter a valid limit\n");
			
	}
	else
	{
		printf("\nNo id. exists\n");
	}
}



void deposit()
{
	int value1;
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}
	
	if(flag=1)
	{
		node *t=search;
		int limit;
		printf("\n\t\tEnter the amount");
		scanf("%d",&limit);
		if(limit>0)
		{
			t->balance+=limit;
			printf("\n\t\t%d credited in account no %d\n",limit,t->ac);
			printf("\n\t\tYour current balance is %d\n",t->balance);
		}
		else
			printf("\n\t\tEnter a valid limit\n");
			
	}
	else
	{
		printf("\nNo id. exists\n");
		
	}
}

void fix()
{
		int value1;
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}
	
	if(flag=1)
	{
		node *t=search;
		int limit;
		printf("\n\t\tEnter the amount:- ");
		scanf("%d",&limit);
		if(limit>0)
		{
			t->fix+=limit;
			printf("\n\t\t%d deposited in account no %d\n",limit,t->ac);
		}
		else
			printf("\n\t\tEnter a valid limit\n");
	}
	else
	{
		printf("\nNo id. exists\n");
		
	}
	
}


void viewlist()
{
	node *view;
	int count=1;
	if(start==NULL)
	{
		printf("\n\t\tList is empty.\n");
	}
	else
	{
		view=start;
		while(view!=NULL)
		{
		printf("\n\t\t[*Information of Client no. %d]",count);
		printf("\n\t\tName :- ");
		printf("%s",view->name);
		printf("\n\t\tAdhar No. :- ");
		printf("%d",view->adhar);
		printf("\n\t\tAccount number:- ");
		printf("%d",view->ac);
		printf("\n\t\tProfession:- ");
		printf("%s",view->profession);
		printf("\n\t\tAddress:- ");
		printf("%s",view->address),
		printf("\n\t\tBalace:- ");
		printf("%d",view->balance),
		printf("\n\t\tFixed Diposit:- ");
		printf("%d\n\n",view->fix);
		count++;
		view=view->next;
		}
		count--;
		printf("\n\n\t\tNo of accounts = %d\n",count);
	}
}


void view()
{
	int value1;
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				printf("\n\t\tId already exists");
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}
	
	if(flag=1)
	{
		node *view=search;
		printf("\n\t\tName :- ");
		printf("%s",view->name);
		printf("\n\t\tAdhar No. :- ");
		printf("%d",view->adhar);
		printf("\n\t\tAccount number:- ");
		printf("%d",view->ac);
		//view->roll=value1;
		printf("\n\t\tProfession:- ");
		printf("%s",view->profession);
		printf("\n\t\tAddress:- ");
		printf("%s",view->address),
		printf("\n\t\tBalace:- ");
		printf("%d",view->balance),
		printf("\n\t\tFixed Diposit:- ");
		printf("%d\n\n",view->fix);
	}
	else
	{
		printf("\nNo account exists\n");
	}
}


void close()
{
	
	int value1;
	printf("\n\t\tEnter the Adahar no.:- ");
	scanf("%d",&value1);
	
	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		printf("\nNo account exists.\n");
	}
	else if(start->adhar==value1)
	{
		node *t;
		t=start;
		if(start->next==NULL)
			start=NULL;
		else
			start=start->next;
		free(t);
		printf("\n\t\tAccount deleted\n");
	}
	else
	{
		node *prev,*t;
		t=start->next;
		while(t!=NULL && t->adhar!=value1)
		{
			prev=t;
			t=t->next;
		}
		if(t->next==NULL)
		{
			printf("\n\t\tNo account exists\n");
		
		}
		else
		{
			node *link;
			link=t->next;
	
			if(t->next==NULL)
			{
				prev->next=NULL;
			}
			else
			{
				prev->next=link;
			}
			free(t);
			printf("\n\t\tAccount deleted\n");
		}
		
	}
	
}

int menu()
{
	int choice;
	printf("\n1: Register an account\n");
	printf("\n2: Withdraw money\n");
	printf("\n3: Deposit money\n");
	printf("\n4: Fixed Diposit\n");
	printf("\n5: Close account\n");
	printf("\n6: Get statements (account)\n");
	printf("\n7: View All account\n");
	printf("\n0: Close application\n");
	printf("\n\t\tENTER YOUR CHOICE:- ");
	scanf("%d",&choice);
	return(choice);
}
int main()
{
	printf("\n|*****************->Banking System<-*****************|\n\n");
	while(1)
	{
		switch(menu())
		{
			case 1:
				insert();
				break;
			case 2:
				widraw();
				break;
			case 3:
				deposit();
				break;
			case 4:
				fix();
				break;
			case 5:
				close();
				break;
			case 6:
				view();
				break;
			case 7:
				viewlist();
				break;
			case 0:
				printf("\n\t\tProject by Soumyadip");
				exit(1);
				
				break;
			default:
				printf("\nENTER A VALID CHOICE");
		}
	}
	return(0);
}
