#include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
struct node *top=NULL;
void push(int val)
{
	struct node * temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=val;
	struct node * ptr=top;
	top=temp;
	temp->next=ptr;
}
void display()
{
	struct node * ptr=top;
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
}
int pop()
{
	struct node * ptr=top;
	int temp=top->data;
	top=top->next;
	free(ptr);
	return temp;
}
int peek()
{
	return top->data;
}
int main()
{
	int ch=1,val;
	while(ch!=0)
	{
		printf("\n*************WELCOME TO STACK HOME**************");
		printf("\n1: PUSH ");
		printf("\n2: POP");
		printf("\n3: PEEK");
		printf("\n4: Display Stack");
		printf("\n0: EXIT");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter an element value to push: ");
				scanf("%d",&val);
				push(val);
				printf("\n\aPushed Successfully\n");
				break;
			case 2:printf("\nPopped value is %d \n",pop());
				break;
			case 3: printf("\nPeeked value is %d \n",peek());
				break;
			case 4: printf("\nThe stack state is : ");
					display();
					break;
			default:printf("\nINVALID CHOICE");
		}
	}
	
		
}

