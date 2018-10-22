#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Project_student{
	char name[100];
	int roll;
	char sec[100];
	char dep[100];
	int year;
	struct Project_student *next;
	}node;
	
FILE *l;
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
	printf("\n\t\tEnter the name:- ");
	scanf("%s",temp->name);
	printf("\n\t\tEnter the roll:- ");
	scanf("%d",&value1);
	temp->roll=value1;
	printf("\n\t\tEnter the sec:- ");
	scanf("%s",temp->sec);
	printf("\n\t\tEnter the depertment:- ");
	scanf("%s",temp->dep),
	printf("\n\t\tEnter year of admission:- ");
	scanf("%d",&temp->year),
	//scanf("%d",&temp->roll);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else if(start!=NULL && value1 < start->roll)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		node *t;
		prev=start;
		t=start->next;
		while(t!=NULL && value1>t->roll)
		{
		prev=t;
		t=t->next;
		}
		if(t==NULL)
		{
			prev->next=temp;
		}
		else
		{
			temp->next=t;
			prev->next=temp;
		}
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
	printf("\n\t\t[*Information of Student no. %d]",count);
	printf("\n\t\tName :- ");
	printf("%s",view->name);
	printf("\n\t\tRoll :- ");
	printf("%d",view->roll);
	//view->roll=value1;
	printf("\n\t\tSec:- ");
	printf("%s",view->sec);
	printf("\n\t\tDepertment:- ");
	printf("%s",view->dep),
	printf("\n\t\tYear of admission:- ");
	printf("%d\n\n\n",view->year),
	count++;
	view=view->next;
		}
		count--;
		printf("\n\n\t\t%d students r in the batch of 1st year.\n",count);
	}
}

void save()
{
	node *save;
	save=start;
	if(start==NULL)
	{
		printf("\n\t\tNo data is saved yet\n");
	}
	else
	{
		l=fopen("Project.txt","w");
		while(save!=NULL)
		{
		fprintf(l,"%s\n",save->name);
		fprintf(l,"%d\n",save->roll);
		fprintf(l,"%s\n",save->sec);
		fprintf(l,"%s\n",save->dep);
		fprintf(l,"%d\n",save->year);
			save=save->next;
		}
		fclose(l);
		printf("\n\t\t[*Data saved successfully]\n");
	}
}

void add()
{
	node *save;
	save=start;
	if(start==NULL)
	{
		printf("\n\t\tLinklist is empty[*Enter some data to save the linklist]\n");
	}
	else
	{
		l=fopen("Project.txt","a");
		while(save!=NULL)
		{
		fprintf(l,"%s\n",save->name);
		fprintf(l,"%d\n",save->roll);
		fprintf(l,"%s\n",save->sec);
		fprintf(l,"%s\n",save->dep);
		fprintf(l,"%d\n",save->year);
		save=save->next;
		}
		fclose(l);
		printf("\n\t\t[*Data added and saved successfully]\n");
	}
}

bool read()
{
	int roll,year,back;
	node *save;
	save=start;
	char name[100],sec[100],dep[100];
	l=fopen("Project.txt","r");
    printf("\n\t\t[*File opened]\n");
	printf("\n\t\tData in Project.txt file :- ");
    fseek(l,0,SEEK_SET);
    while(fscanf(l,"%s\n",name)!=EOF)
    {
    	printf("\n\n\n\t\tName :- ");
    	printf("%s",name);
    	printf("\n\t\tRoll :- ");
		fscanf(l,"%d",&roll);
		printf("%d",roll);
		printf("\n\t\tSection :- ");
		fscanf(l,"%s",sec);
		printf("%s",sec);
		printf("\n\t\tDepartment :- ");
		fscanf(l,"%s",dep);
		printf("%s",dep);
		printf("\n\t\tYear of admission :- ");
		fscanf(l,"%d",&year);
		printf("%d",year);
    }
    printf("\n\n\t\t[*File closed]\n");
	fclose(l);
	printf("\n\t\t[*Enter 0] to back to main menu :-");
	while(1)
	{
		scanf("%d",&back);
		if(back==0)
		{
			return false;
		}
		else
		{
		printf("\n\t\t[*Enter 0] to back to main menu :-");
		}

	}
}
int menu()
{
	int choice;
	printf("\n1: Insert the data\n");
	printf("\n2: View List\n");
	printf("\n3: Save\n");
	printf("\n4: Add and save\n");
	printf("\n5: Read file\n");
	printf("\n0: Exit\n");
	printf("\n\t\tENTER YOUR CHOICE:- ");
	scanf("%d",&choice);
	return(choice);
}
int main()
{
	while(1)
	{
		switch(menu())
		{
			case 1:
				insert();
				break;
			case 2:
				printf("\n\t\tData you have entered:-\n ");
				viewlist();
				break;
			case 3:
				save();
				break;
			case 4:
				add();
				break;
			case 5:
				read();
				system("cls");
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("\nENTER YOUR CHOICE BETWEEN 1 & 2\n");
		}
	}
	return(0);
}
