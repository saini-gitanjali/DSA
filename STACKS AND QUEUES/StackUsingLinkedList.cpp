#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int info;
	struct node *next;
};
struct node* top;
int isempty()
{
	if(top==NULL)
	{
		//printf("\nEMPTY!!!");
		return 1;
	}
	else
    {

		//printf("\n not empty");
		return 0;
	}
}

void push(int n)        //working
{
    struct node *temp, *new_node;
	new_node=(struct node*)malloc(sizeof(struct node*));
	temp=top;
	//creating a new node
	new_node->info=n;
	new_node->next=NULL;
	if(!new_node)
		printf("memory error , new node can not be created");
	//if list is empty
	if(isempty())
	{
		top=new_node;
		top->next=NULL;
	}
	//when list is not empty
	else
	{
        new_node->next=top;
        top=new_node;
	}
}

void pop()
{
	struct node* temp, *prev;
	temp=top;
	if(isempty())
		printf("\n Underflow!!!");
	else
	{
		printf("top->info = %d deleted", top->info);
        temp=top;
        top=top->next;
        free(temp);
        return;
	}
}


void display()
{
	struct node *temp;
	temp=top;
	if(isempty())
	printf("underflow");
	else
	{
	    printf("n\printing stack items");
		while(temp)
		{

		    printf("\n %d->", temp->info);
            temp=temp->next;
		}
	}
}

void peek()//display element at top //working
{
	if(top==NULL)
	{
		printf("\n List empty");
	}
	else
	{
	printf(" %d",top->info);
	}
}
int main()
{
int ch=0, ch2=0, n;
do{
	printf("\n STACK FUNCTIONS");
	printf("\n 1. PUSH");
	printf("\n 2. POP");
	printf("\n 3. DISPLAY");
	printf("\n 4. peek");
	printf("\n 5. if stack is empty");
	printf("\n ENTER YOUR CHOICE!!!    ");
	scanf("%d", &ch);
	switch(ch)
	{
	    case 1: printf("Enter a term to push: ");
                scanf("%d",&n);
                push(n);
                break;
        case 2: pop();
                break;
		case 3: display();
				break;
        case 4: peek();
                break;
        case 5: if(isempty())
                    printf("\n STACK IS EMPTY");
                else
                    printf("\nSTACK NOT EMPTY");
                break;
	}
    printf("\nEnter 1 to continue...");
    scanf(" %d",&ch2);
}while(ch2==1);
return 0;
}
