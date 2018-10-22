
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[100];
    char meaning[1000] ;
    char syno[1000] ;
    struct node *next ;
}node;
FILE *l;
node *start=NULL;
node* createnode()
{
	node *n;
	n=(node*)malloc(sizeof(node));
	return(n);
}

bool search(node *temp) 
{ 
    node *t=start;
    while (t!=NULL) 
    { 
        if (strcmpi(t->word,temp->word)==0) 
            return true; 
        t = t->next; 
    } 
    return false; 
} 



void insert()
{
	node *temp,*prev;
	char value[100];
	temp=createnode();
	int value1;
	printf("\n\t\tEnter the Word:- ");
	fflush (stdin) ;
	gets(temp->word);
	if(search(temp)==0)
	{
		strcpy(value,temp->word);
		printf("\n\t\tEnter the Synonym:- ");
		gets(temp->syno);
		fflush (stdin) ;
		printf("\n\t\tEnter the Meaning:- ");
		gets(temp->meaning);
		temp->next=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else if(start!=NULL && strcmpi(value,start->word)<0)
		{
			temp->next=start;
			start=temp;
		}
		else
		{
			node *t;
			prev=start;
			t=start->next;
			while(t!=NULL && strcmpi(value,start->word)>0)
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
	else
		printf("\nWord already exists\n");

}
void search() 
{ 
    node *t=start;
    char value1[100];
    printf("\n\t\tEnter the Word to be searched:- ");
	fflush (stdin) ;
	gets(value1);
	int flag=0;
    while (t!=NULL) 
    { 
        if (strcmpi(t->word,value1)==0) 
        {
        	printf("\n\t\tWord->");
			puts(t->word);
			printf("\t\tSynonym->");
			puts(t->syno);
			printf("\t\tMeaning->");
			puts(t->meaning);
			printf("\n\n");
        	flag=1;
        	break;
		}
        t = t->next; 
    } 
    if(flag==0)
    	printf("\n\t\tWord is'nt present in the list");
} 


void display()
{
	node *t=start;
	while(t!=NULL)
	{
		printf("\n\t\tWord->");
		puts(t->word);
		printf("\t\tSynonym->");
		puts(t->syno);
		printf("\t\tMeaning->");
		puts(t->meaning);
		t=t->next;
		printf("\n\n");
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
		l=fopen("Dictionary.txt","a");
		while(save!=NULL)
		{
		fprintf(l,"\n%s",save->word);
		fprintf(l,"\t%s",save->syno);
		fprintf(l,"\t%s",save->meaning);
		save=save->next;
		}
		fclose(l);
		printf("\n\t\t[*Data added and saved successfully]\n");
	}
}



void del()
{
	node *save;
	save=start;
	if(start==NULL)
	{
		printf("\n\t\tLinklist is empty[*Enter some data to save the linklist]\n");
	}
	else
	{
		l=fopen("Dictionary.txt","w");
		fclose(l);
		printf("\n\t\t[*Filedeleted successfully]\n");
	}
}


int main( )
{
    while (true)
    {
    	int ch;
        printf("\n***Dictionary Management System***\n" ) ;
        printf("\n1.Add Word.\n") ;
        printf("\n2.Search\n") ;
        printf("\n3.Show Dictionary.\n") ;
        printf("\n4.Save in file(Dictionary.txt)\n") ;
		printf("\n5.Delete file(Dictionary.txt)\n") ;
         printf("\n0.Close Dictionary.\n" ) ;
        printf("\n\t\tEnter your Choice ") ;
        scanf ( "%d", &ch ) ;

        switch (ch)
        {
            case 1 :
            	insert();
            	break;
            case 2 :
            	search();
            	break;
            case 3:
            	display();
            	break;
            case 4:
            	add();
            	break;
            case 5:
            	del();
            	break;
           
            case 0:
            	return 0;
            }
        }
}
