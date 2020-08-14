#include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front=NULL;
struct node * rear=NULL;
void insert(int val)
{
	
	struct node * temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	if(rear==NULL)
	{
		rear=temp;
		front=temp;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
	}
	

}
void display()
{
	struct node * ptr=front;
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
}
int removeNode()
{
	struct node * ptr=front;
	int temp=front->data;
	front=front->next;
	free(ptr);
	return temp;
}
int main()
{
	int ch=1,val;
	while(ch!=0)
	{
		printf("\n*************WELCOME TO STACK HOME**************");
		printf("\n1: INSERT ");
		printf("\n2: REMOVE");
		printf("\n3: Display Queue");
		printf("\n0: EXIT");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter an element value to push: ");
				scanf("%d",&val);
				insert(val);
				printf("\n\aInserted Successfully\n");
				break;
			case 2:printf("\nRemoved value is %d \n",removeNode());
				break;
			case 3: printf("\nThe queue state is : ");
					display();
					break;
			default:printf("\nINVALID CHOICE");
		}
	}
	
		
}

