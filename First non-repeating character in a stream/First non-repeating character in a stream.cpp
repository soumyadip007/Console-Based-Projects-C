#include <stdio.h> 
#include <stdlib.h> 
#define MAX_CHAR 1000 
struct node 
{ 
    char a; 
    struct node *next, *prev; 
};
void appendNode(struct node **head_ref, struct node **tail_ref, char x);
void removeNode(struct node **head_ref, struct node **tail_ref,struct node *temp) ; 
void findFirstNonRepeating(); 


int choice()
{
	int ch;
	printf("\n1:Get first recurring chacter\n");
	printf("\n2:Clear screen\n");
	printf("\n0:Exit\n");
	printf("\nEnter your choice :- ");
	scanf("%d",&ch);
}
int main()
{ 
	while(true)
	{
		switch(choice())
		{
			case 1:
					findFirstNonRepeating();
					break;
			case 2:
					system("cls");
					break;
			case 0:
				return 0;
   			default:
   					printf("\nEnter a valid choice\n");
		}
	}
    
} 


void appendNode(struct node **head_ref, struct node **tail_ref, 
                char x) 
{ 
    struct node *temp = new node; 
    temp->a = x; 
    temp->prev = temp->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
        *head_ref = *tail_ref = temp; 
        return; 
    } 
    (*tail_ref)->next = temp; 
    temp->prev = *tail_ref; 
    *tail_ref = temp; 
} 
void removeNode(struct node **head_ref, struct node **tail_ref, 
                struct node *temp) 
{ 
    if (*head_ref == NULL) 
        return; 
  
    if (*head_ref == temp) 
        *head_ref = (*head_ref)->next; 
    if (*tail_ref == temp) 
        *tail_ref = (*tail_ref)->prev; 
    if (temp->next != NULL) 
        temp->next->prev = temp->prev; 
    if (temp->prev != NULL) 
        temp->prev->next = temp->next; 
  
    free(temp); 
} 
  
void findFirstNonRepeating() 
{ 
    struct node *inDLL[MAX_CHAR]; 
    
    bool repeated[MAX_CHAR]; 
  
    struct node *head = NULL, *tail = NULL; 
    for (int i = 0; i < MAX_CHAR; i++) 
    { 
        inDLL[i] = NULL; 
        repeated[i] = false; 
    } 
  
    char stream[1000] ;
    printf("\n\t\tEnter the string:- ");
   scanf("%s",stream);
    fflush(stdin);
    for (int i = 0; stream[i]; i++) 
    { 
        char x = stream[i]; 
        printf("\n\t\tReading %c from stream \n",x); 
  
        if (!repeated[x]) 
        { 
            if (inDLL[x] == NULL) 
            { 
                appendNode(&head, &tail, stream[i]); 
                inDLL[x] = tail; 
            } 
            else            { 
                removeNode(&head, &tail, inDLL[x]); 
                inDLL[x] = NULL; 
                repeated[x] = true; 
            } 
        } 
  
        if (head != NULL) 
            printf("\n\t\tFirst non-repeating character so far is %c\n",head->a); 
    } 
} 
