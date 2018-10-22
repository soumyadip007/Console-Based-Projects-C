#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Resturant_management_system{
	int in;
	int out;
	int table;
	int *token;
}resturant;
FILE *l;
resturant* createsystem(int cap)
{
	resturant *createsystem;
	createsystem=(resturant*)malloc(sizeof(resturant));
	createsystem->in=-1;
	createsystem->out=0;
	createsystem->table=cap;
	createsystem->token=(int*)malloc((createsystem->table)*sizeof(int));
	return(createsystem);
}

int systemisFull(resturant *system)
{
	if(system->in==system->table-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void book(resturant *system,int user)
{
	if(!systemisFull(system))
	{
		system->in++;
		system->token[system->in]=user;
	}
	else
	{
		printf("\n\t\tNo table is availavle\n\t\tPlease wait for a while\n");
	}
}
int systemisEmpty(resturant *system)
{
	if(system->in==-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
int finished(resturant *system)
{
	int item;
	if(!systemisEmpty(system))
	{
		item=system->token[system->out];
		system->out++;
		
		if(system->out>system->in)
		{
			
			system->out=0;
			system->in=-1;
		}
		return(item);
	}
	else
	{
		return(-1);
	}
}
int display_tables(resturant *system)
{
	int i;
	if(!systemisEmpty(system))
	{
		printf("\n\t\tToken present in the tables:-");
		for(i=system->out;i<=system->in;i++)
		{
			printf(" %d\t",system->token[i]);
		}
		printf("\n\n");
	}
	else
	{
			printf("\n\t\tResturant is compleately empty.\n\t\tPlease book some seats\n");
	} 
}

void save(resturant *system)
{
	resturant *save;
		l=fopen("Project.txt","w");
		if(!systemisEmpty(system)) 
	{
		for(int i=system->out;i<=system->in;i++)
		{
			fprintf(l," %d\t",system->token[i]);
		}
		printf("\n\t\t[*All tokens are saved successfully]\n");
	}
	else
	{
		printf("\n\t\tResturant is compleately empty.\n\t\tNo token available to save\n");
	}
		fclose(l);
	//	printf("\n\t\t[*Tokens in file saved successfully]\n");
}

void add(resturant *system)
{
	resturant *save;
		l=fopen("Project.txt","a");
		if(!systemisEmpty(system)) 
	{
		for(int i=system->out;i<=system->in;i++)
		{
			fprintf(l," %d\t",system->token[i]);
		}
		printf("\n\t\t[*All tokens are added & saved successfully]\n");
	}
	else
	{
		printf("\n\t\tResturant is compleately empty.\n\t\tNo token available to save\n");
	}
		fclose(l);
	//	printf("\n\t\t[*Tokens in file saved successfully]\n");
}


void read(resturant *system)
{
	int data,back;
	l=fopen("Project.txt","r");
    printf("\n\t\t[*File opened]\n");
	printf("\n\t\tTokens saved in file :- ");
    fseek(l,0,SEEK_SET);
    while(fscanf(l,"%d",&data)!=EOF)
    {
    printf("%d\t",data);
    }
    printf("\n\n\t\t[*File closed]\n");
	fclose(l);
}


int menu()
{
	int take;
	printf("\n1:Book a seat\n");
	printf("\n2:Dinner finished\n");
	printf("\n3:View tables\n");
	printf("\n4:Save tokens in file\n");
	printf("\n5:Add & Save tokens in file\n");
	printf("\n6:Tokens saved in file\n");
	printf("\n0:Exit\n\n");
	printf("\n\t\tEnter your choice:- ");
	scanf("%d",&take);
	return take;
}

int main()
{
int item,cap,i;
resturant *system;
printf("\nEnter number of tables:- ");
scanf("%d",&cap);
system=createsystem(cap); 
while(1)
{
	switch(menu()) 
	{
		case 1:
			if(!systemisFull(system))
			{
				int user;
				printf("\n\t\tEnter the token no.:- ");
				scanf("%d",&user);
				book(system,user);
			}
			else
			{
				printf("\n\t\tAll tables are full.\n\t\tPlease wail for a while\n");
			}
			break;
		case 2:
			item=finished(system);
			if(item==-1)
			{
			printf("\n\t\tResturant is compleately empty.\n\t\tPlease book some seats\n");
			break;
			}
			else
			{
				printf("\n\t\tToken no. %d has compleated his meal.\n",item);
			}
			if(system->out>0)
			{
			system->out=0;
			for(i=system->out;i<system->in;i++)
			{
				system->token[i]=system->token[i+1];
			}
			system->in--;
			}
			if(system->in==-1)
			{
				printf("\n\t\tResturant is compleately empty.\n\t\tPlease book some seats\n");
			}
			else
			{
				int y=system->in;
				y++;
					printf("\n\t\tNo. of availavle seats:- %d",y);
			}
			break;
		case 3:
			display_tables(system);
			break;
		case 4:
			save(system);
			break;
		case 5:
			add(system);
			break;
		case 6:
			read(system);
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("\n\t\tENTER A CHOICE BETWEEN 1,2,3,4,5 & 6\n");
			break;
	}
}
return(0);
}
