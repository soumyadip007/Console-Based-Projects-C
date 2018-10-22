#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
	}node;

typedef struct Arrayfinite
{
	int top;
	int capacity;
	int *array;
}Structfinite;

char get[100];
node *start=NULL;
FILE *l;

node* createnode()
{
	node *n;
	n=(node*)malloc(sizeof(node));
	return(n);
}

void insert_infinite()
{
	node *temp;
	temp=createnode();
	printf("\n\t\tEnter a data:- ");
	scanf("%d",&temp->data);
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
		{
			t=t->next;
		}
	t->next=temp;
	}
}

void deleteatany()
{
	node *back,*k,*link;
	int pos,count=1;
	printf("\n\t\tEnter which data you want to delete[*Enter the position no. of the data] :- ");
	scanf("%d",&pos);
	if(pos<=0 && start==NULL)
	{
			printf("\n\t\tThere is no data in position no. %d to delete\n\nEnter a valid position",&pos);	
	}
	if(count<pos && start==NULL)
	{
			printf("\n\t\tThere is no data in position no. %d to delete\n\nEnter a valid position",&pos);
	}
	if(pos==1 && start==NULL)
	{
			printf("\n\t\tThere is no data in position no. %d to delete\n\nEnter a valid position",&pos);	
	}
	k=start;
	if(k!=NULL)
	{
		while(count<pos && k->next!=NULL)
		{
			back=k;
			k=k->next;
			count++;
		}
		if(pos==1)
		{
			start=start->next;
			free(k);
			printf("\n\t\tData deleted succesfully\n");
		}
		else if(pos==0)
		{
			printf("\n\t\tThere is no data in position no. %d to delete\n\n\t\tEnter a valid position(position must be > 0)",pos);	
		}
		else if(count<pos)
		{
			printf("\n\t\tThere is no data in position no. %d to delete\n\nEnter a valid position",pos);
			}
		
		else if(pos<0)
		{
			printf("\n\t\tThere is no data in position no. %d to delete\n\nEnter a valid position",pos);
		}
		else
		{
			link=k->next;
			free(k);
			back->next=link;
			printf("\n\t\tData deleted succesfully\n");
		}
	}	
}

bool viewlist_delete()
{
	node *view;
	int count=0;
	if(start==NULL)
	{
		printf("\n\t\tThere is no data for delete\n\t\tPlease enter some data\n");
		return true;
	}
	else
	{
		printf("\n\t\tThe data you have entered:- ");
		view=start;
		while(view!=NULL)
		{
			printf("%d\t",view->data);
			view=view->next;
			count++;
		}
		printf("\n\n\t\t[*Data-count :- %d]\n",count);
		return false;
	}	
}


bool view_infinite()
{
	node *view;
	int count=0;
	if(start==NULL)
	{
		printf("\n\t\tThere is no data present in file file\n\t\tPlease enter some data\n");
		return true;
	}
	else
	{
		printf("\n\t\tThe data you have entered:- ");
		view=start;
		while(view!=NULL)
		{
			printf("%d\t",view->data);
			view=view->next;
			count++;
		}
		printf("\n\n\t\t[*Data-count :- %d]\n",count);
		return false;
	}	
}

int delete_menu1()
{
	int ch;
	printf("\n\n1: Perform this task again\n");
	printf("\n0: back to menu\n");
	printf("\n\t\tEnter your choice :- ");
	scanf("%d",&ch);
	return ch;
}

bool delete_infinite()
{
	if(!viewlist_delete())
	{
		deleteatany();
			while(1)
			{
				switch(delete_menu1())
					{
						case 1:
							if(!viewlist_delete())
							{
								deleteatany();
							}
							else
							{
								return false;
							}
							break;
						case 0:
							return false;
						default:
							("\n\t\tEnter a valide choice");
							break;
						}
			}
	}
	else
	{
		return false;
	}
}


bool sort_infinite()
{
	node *head,*prev,*h,*min;
	int temp;
	head=start;
	if(head!=NULL)
	{
		prev=head;
		h=prev->next;
		while(prev->next!=NULL && prev!= NULL)
		{
			min=prev;
			h=prev->next;
			while(h!=NULL )
			{
			 	if(h->data<min->data)
			 	min=h;
			 	
			h=h->next;
			}
			temp=prev->data;
			prev->data=min->data;
			min->data=temp;
			
			prev=prev->next;
			}
			start=head;
			printf("\n\t\tAll data has been rearranged succesfully\n");
			return false;
		}
		else
		{
			printf("\n\t\tThere is no data to perform rearrange task\n");
			return true;
		}
}

void insertatSortedorder_infinite()  
{
	node *temp,*prev;
	
	temp=createnode();
	int value1;
	printf("\n\t\tEnter a value:- ");
	scanf("%d",&temp->data);
	value1=temp->data;
	temp->next=NULL;
	if(start!=NULL)
	{
	if(value1 < start->data)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		node *t;
		prev=start;
		t=start->next;
		while(t!=NULL && value1>t->data)
		{
		prev=t;
		t=t->next;
		}
		if(t==NULL)
		{
			prev->next=temp;
			printf("\n\t\tData has been inserted as it's priority manner.");
			
		}
		else
		{
			temp->next=t;
			prev->next=temp;
			printf("\n\t\tData has been inserted as it's priority manner.");
		}
	}	
	}
	if(start==NULL)
	{
		start=temp;
			printf("\n\t\tData has been inserted as it's priority manner.");
	}
}


bool rearrange_menu()
{
	char choice;
	printf("\n\nIf you want to enter data as their prorities enter 'y'\n\nelse press any button :- ");
	scanf("%s",&choice);
	if(choice=='y')
	{
		return false;
	}
	else
	{
		system("cls");
		return true;
	}
}

int rearrange_menu1()
{
	int ch;
	printf("\n\n1: Perform this task again\n");
	printf("\n0: back to menu\n");
	printf("\n\t\tEnter your choice :- ");
	scanf("%d",&ch);
	return ch;
}

bool rearrange_infinite()
{
	if(!sort_infinite())
	{
		if(!rearrange_menu())
		{
			insertatSortedorder_infinite();
			while(1)
			{
				switch (rearrange_menu1())
				{
					case 1:
						insertatSortedorder_infinite();
						break;
					case 0:
						system("cls");
						return false;
					default:
						printf("\n\t\tEnter a valide choice\n");
						break;
				}
			}
		}
		else
		{
			return false;
		}
		}
	else
	{
		return false;
	}
}

void search_infinite()
{
	node *search;
	search=start;
	int item,pos=1,flag=0;
	if(start==NULL)
	{
		printf("\n\t\tFile is empty.\n\t\tPlease enter some data\n\n");
	}
	else
	{
	printf("\n\t\tEnter the item to be searched:- ");
	scanf("%d",&item);
	while(search!=NULL)
	{
		if(search->data==item)
		{
			flag=1;
			printf("\n\t\tSearched item (%d) is found at position %d\n",item,pos);
			pos++;
			search=search->next;
		}
		else
		{
			pos++;
			search=search->next;
		}
	}
	if(flag==0)
	{
		printf("\n\t\tSearched item (%d) is not found in the File\n",item);
	}
}
}


bool save_infinite1()
{
	node *save;
	save=start;
	if(start==NULL)
	{
		printf("\n\t\tFile is empty[*Enter some data to save the file]\n");
	}
	else
	{
		l=fopen("Project_file.txt","w");
		while(save!=NULL)
		{
			fprintf(l,"%d\t",save->data);
			save=save->next;
		}
		fclose(l);
		printf("\n\t\t[*File saved succesfully]\n");
		return false;
	}
}

bool add_infinite()
{
	node *save;
	save=start;
	if(start==NULL)
	{
		printf("\n\t\tFile is empty[*Enter some data to save the file]\n");
	}
	else
	{
		l=fopen("Project_file.txt","a");
		while(save!=NULL)
		{
			fprintf(l,"%d\t",save->data);
			save=save->next;
		}
		fclose(l);
		printf("\n\t\t[*File added and saved succesfully]\n");
		return false;
	}
}

int save_infinite_menu()
{
	int ch;
	printf("\n1: Save this file\n");
	printf("\n2: Overwrite & save this file\n");
	printf("\n3: Add & save this file\n");
	printf("\n0: back to main menu\n");
	printf("\nEnter your choice :- ");
	scanf("%d",&ch);
	return ch;
}

bool save_infinite()
{
	if(start==NULL)
	{
		return false;
	}
	else
	{
	while(1)
	{
		switch(save_infinite_menu())
		{
			case 1:
				save_infinite1();
				return false;
				break;
			case 2:
				save_infinite1();
				return false;
				break;
			case 3:
				add_infinite();
				return false;
				break;
			case 0:
				return false;
				break;
			default:
				printf("\nENTER YOUR CHOICE BETWEEN 1,2,3 & 4\n");
				break;
		}
	}
}
}

		//Finite
		
Structfinite* createfinite(int cap) 
{
	Structfinite *createfinite; 
	createfinite=(Structfinite*)malloc(sizeof(Structfinite)); 
	createfinite->capacity=cap;
	createfinite->top=-1;
	createfinite->array=(int*)malloc((createfinite->capacity)*sizeof(int)); 
	return(createfinite);
}

bool finiteisFull(Structfinite *finite)
{
	if(finite->top==finite->capacity-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insert_finite(Structfinite *finite,int item)
{
	if(!finiteisFull(finite)) //function call
	{
		finite->top++;
		finite->array[finite->top]=item;
	}
}

bool finiteisEmpty(Structfinite *finite)
{
	if(finite->top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool viewlist_delete_finite(Structfinite *finite)
{
	int count=0,i;
	if(finite->top!=-1)
	{
		printf("\n\t\tThe data you have entered:- ");
		for(i=0;i<=finite->top;i++)
		{
			printf(" %d\t",finite->array[i]);
			count++;
		}
		printf("\n\n\t\t[*Data-count :- %d]\n",count);
		return false;
	}
	else
	{
		printf("\n\t\tThere is no data to perform this task.\n\t\tPlease enter some data.\n");
		return true;
	}	
	
}
	

void deleteany_position(Structfinite *finite)
{
	int pos,i,count=0;
	printf("\n\t\tEnter which data you want to delete[*Enter the position no. of the data] :- ");
	scanf("%d",&pos);
	if(pos>0 && pos<finite->top)
	{
	for(i=pos-1;i<finite->top;i++)
	{
		finite->array[i]=finite->array[i+1];
	}
	finite->top--;
	printf("\n\t\tData deleted succesfully\n");
	}
	else
	{
		printf("\n\t\tThere is no data in position no. %d to delete\n\t\tEnter a valid position\n",pos);
	}
}

bool delete_finite(Structfinite *finite)
{
	if(!viewlist_delete_finite(finite))
	{
		deleteany_position(finite);
	}
	else
	{
		return false;
	}
}


bool sort_finite(Structfinite *finite)
{
	if(!finiteisEmpty(finite)) //function call
	{
	int i,j,temp,min;
	for(i=0;i<finite->top;i++)
	{
		min=i;
		for(j=i+1;j<=finite->top;j++)
		{
			if(finite->array[min]>finite->array[j])
			min=j;
		}
		temp=finite->array[i];
		finite->array[i]=finite->array[min];
		finite->array[min]=temp;
	}
			printf("\n\t\tAll data has been rearranged succesfully\n");
			return false;
		}
		else
		{
			printf("\n\t\tThere is no data to perform rearrange task\n");
			return true;
		}
}

void search_finite(Structfinite *finite)
{
	if(finite->top!=-1)
	{
		int search,i,flag=0;
		printf("\n\t\tEnter the item to be searched:- ");
		scanf("%d",&search);
		for(i=0;i<=finite->top;i++)
		{
			if(finite->array[i]==search)
			{
				flag=1;
				printf("\n\t\tSearched item (%d) is found at position %d\n",search,i+1);
			}
	}
	if(flag==0)
	{
		printf("\nSearched item is not present is array\n");
	}
		
		/*low=0,up=finite->top;
		while(low<=up)
		{
			mid=(low+up)/2;
			if(item==finite->array[mid])
			{
				printf("\n\t\tSearched item (%d) is found at position %d\n",item,mid);
				break;
			}
			else if(item>finite->array[mid])
			{
				low=mid+1;
			}
			else 
			{
				up=mid-1;
			}*/
		
}
}

bool view_finite(Structfinite *finite)
{
	int count=0,i;
	if(!finiteisEmpty)
	{
		printf("\n\t\tThere is no data present in the file\n\t\tPlease enter some data\n");
		return true;
	}
	else
	{
		printf("\n\t\tThe data you have entered:- ");
		for(i=0;i<=finite->top;i++)
		{
			printf(" %d\t",finite->array[i]);
		}
		printf("\n\n\t\t[*Data-count :- %d]\n",count);
		return false;
	}	
}

bool save_finite1(Structfinite *finite)
{
	int i;
		l=fopen("Project_file.txt","a");
		for(i=0;i<=finite->top;i++)
		{
			fprintf(l," %d\t",finite->array[i]);
		}
		fclose(l);
		printf("\n\t\t[*File saved succesfully]\n");
		return false;
}

bool add_finite(Structfinite *finite)
{
	int i;
		l=fopen("Project_file.txt","a");
		for(i=0;i<=finite->top;i++)
		{
			fprintf(l," %d\t",finite->array[i]);
		}
		fclose(l);
		printf("\n\t\t[*File added and saved succesfully]\n");
		return false;
}

int save_finite_menu()
{
	int ch;
	printf("\n1: Save this file\n");
	printf("\n2: Overwrite & save this file\n");
	printf("\n3: Add & save this file\n");
	printf("\n0: back to main menu\n");
	printf("\nEnter your choice :- ");
	scanf("%d",&ch);
	return ch;
}

bool save_finite(Structfinite *finite)
{
	if(finite->top==-1)
	{
		return false;
	}
	else
	{
	while(1)
	{
		switch(save_finite_menu())
		{
			case 1:
				save_finite1(finite);
				return false;
				break;
			case 2:
				save_finite1(finite);
				return false;
				break;
			case 3:
				add_finite(finite);
				return false;
				break;
			case 0:
				return false;
				break;
			default:
				printf("\nENTER YOUR CHOICE BETWEEN 1,2,3 & 4\n");
				break;
		}
	}
}
}	

bool read()
{
	register int data,back;
	l=fopen("Project_file.txt","r");
    printf("\n\t\t[*File opened]\n");
	printf("\n\t\tData in Project_file.txt file :- ");
    fseek(l,0,SEEK_SET);
    while(fscanf(l,"%d",&data)!=EOF)
    {
    printf("%d\t",data);
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

int main_menu()
{
	int choice=0;
	printf("\n\t|*|*MAIN-MENU*|*|\n");
	printf("\n1: Work on infinite number of data\n");
	printf("\n2: Work on finite number of data\n");
	printf("\n3: Read file\n");
	printf("\n0: Exit\n");
	printf("\n\t\tENTER YOUR CHOICE:- ");
	scanf("%d",&choice);
	return(choice);
}

int infinite_data_finite()
{
	int choice=0;


	printf("\n1: Enter data\n");
	printf("\n2: Delete data\n");
	printf("\n3: Re-arrange all data as their priorities\n");
	printf("\n4: Search data\n");
	printf("\n5: View file\n");
	printf("\n0: Back to main menu\n");
	printf("\n\t\tENTER YOUR CHOICE:- ");
	scanf("%d",&choice);
	return(choice);
}

bool infinite()
{
	int check=0;
	printf("\n\t\t|*|MENU|*|\n");
	while(1)
	{
		switch(infinite_data_finite())
		{
			case 1:
				insert_infinite();
				break;
			case 2:
				delete_infinite();
				system("cls");
				break;	
			case 3:
				rearrange_infinite();
				break;
			case 4:
				search_infinite();
				break;
			case 5:
				view_infinite();
				break;
			case 0:
				system("cls");
				if(!save_infinite())
				{
					start=NULL;
					return false;
				}
			default:
				printf("\n\t\tEnter a choice between 1,2,3,4,5");
		}
	}
}

bool finite()
{
int item,cap;
Structfinite *finite;
printf("\n\nEnter the size of your file:- ");
scanf("%d",&cap);
finite=createfinite(cap);
printf("\n\t\t|*|MENU|*|\n");
while(1)
{
	switch(infinite_data_finite()) 
	{
		case 1:
			if(!finiteisFull(finite))
			{	
				printf("\n\t\tEnter a data:- ");
				scanf("%d",&item);
				insert_finite(finite,item);
			}
			else
			{
				printf("\n\t\tYour file is full\n");	
			}
			break;
		case 2:
			delete_finite(finite);
			break;
		case 3:
				sort_finite(finite);
				break;
			case 4:
				search_finite(finite);
				break;
			case 5:
				view_finite(finite);
				break;
			case 0:
				system("cls");
				if(!save_finite(finite))
				{
					return false;
				}
			default:
				printf("\n\t\tEnter a choice between 1,2,3,4,5");
				
		}
	}
}


int project_main()
{
	int check=1;
	while(1)
	{
	
	switch(main_menu())
	{
		case 1:
			system("cls");
			printf("\n\t|**Welcome to infinite number's workplace**|\n");
			check=infinite();
			if(!check)
			{
				system("cls");
				project_main();		
			}
			break;
		case 2:
			system("cls");
			printf("\n\t|**Welcome to finite number's workplace**|\n");
			check=finite();
			if(!check)
			{
				system("cls");
				project_main();		
			}
			break;
		case 3:
			check=read();
			if(!check)
			{
				system("cls");
				project_main();		
			}
			break;
		case 0:
				printf("\n\t\tGood-bye %s.\n\t\tWill see you soon.\n\t\tHave a nice day.",get);
				exit(0);
			break;
		default:
			printf("\n\t\tENTER YOUR CHOICE BETWEEN 1,2,3 & 0\n");
			break;
	}
	}
}
int count=0,limit=3;
bool password()
{
	int key;
	if(count<3)
	{
		printf("\n\t\tEnter the password:- ");
		scanf("%d",&key);
	if(key==1234|| key==9999)
	{
		return false;
	}
	else 
	{
		limit--;
		printf("\n\t\tThe password you entered is incorrect.");
		if(limit==1)
		{
		printf("\n\t\tYou have %d login attempt remaining.\n",limit);
		}
		else if(limit==2)
		{
		printf("\n\t\tYou have %d login attempts remaining.\n",limit);
		}
		count++;
		password();
	}
	}
	else
	{
		return true;
	}
}

int security()
{
	char user[11][100]={"Soumyadip","Soumyadip chowdhury","Snehanjan"};
	register int access=0;
	int key;
	printf("\n\n\n\n\n\t\tPlease enter the username to access this project:- ");
	gets(get);
	for(int i=0;i<11;i++)
	{
	if(strcmpi(get,user[i])==0)
	{
		access=1;
	}
	}
if(access==1)
{
	if(!password())
	{
		system("cls");
		printf("\nHello %s,you are logged in.\n",get);
		project_main();	
	}
	else
	{
		
	printf("\n\n\t\tWe are sorry %s,you have crossed your attempt limit.\n\t\tPlease enter a valid password next time.\n\t\tThank you.\n\n",get);
	exit(0);
		
	}
	int access=0;
}
else
{
	printf("\n\t\tDear %s,you are not allowed to access this project.\n\t\tPlease enter a valid username next time.\n\t\tThank you.\n\n",get);
}
}


int main()
{
	security();
	return(0);
}
