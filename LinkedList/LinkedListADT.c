#include<stdio.h>
#include<conio.h>
struct node
{
	int info;
	struct node * link; 
};
struct node * start=NULL;
struct node*createNode()
{
	struct node* n;
	n=(struct node *)malloc(sizeof(struct node));
	return (n);
}
int add_last(int val)
{
	struct node * temp,*t;
	temp=createNode();
	
	temp->info=val;
	temp->link=NULL;
	
	if(start==NULL)
		start=temp;
	else
	{
		t=start;
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
	}
	return 1;
}
int add_first(int val)
{
	struct node * temp;
	temp=createNode();
	temp->info=val;
	temp->link=start;
	
	start=temp;
	return 1;
}
int add_pos(int val,int pos)
{
	struct node *ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
		if(count==(pos-2))
			break;
		count++;
		ptr=ptr->link;
	}
	
	struct node * temp;
	temp=createNode();
	temp->info=val;
	
	temp->link=ptr->link;
	ptr->link=temp;
	
	return 1;
	
}
void display()
{
	printf("\n The list is : ");
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
}
int find_length()
{
	struct node* ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	return count;
}
int remove_last()
{
	struct node * next=start,*prev=start;
	while(next->link!=NULL)
	{
		prev=next;
		next=next->link;
	}
	prev->link=NULL;
	int val=next->info;
	free(next);
	return val;
}
int remove_first()
{
	int val=start->info;
	struct node * ptr=start;
	start=start->link;
	free(ptr);
	return val;	
}
int remove_item(int val)
{
	struct node * next=start,*prev=start;
	while(next->info!=val &&  next->link!=NULL)
	{
		prev=next;
		next=next->link;
	}
	if(next->link==NULL && next->info!=val)
		return 0;
	prev->link=next->link;
	free(next);
	return 1;
}
int update_item(int newval,int oldval)
{
	struct node * next=start;
	while(next->info!=oldval &&  next->link!=NULL)
	{
		next=next->link;
	}
	if(next->link==NULL && next->info!=oldval)
		return 0;
	next->info=newval;
	return 1;
}
void reverse()
{
	struct node * prev,*current,*next;
	prev=NULL;
	current=start;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		
		prev=current;
		current=next;		
	}
	start=prev;
}
//VVI
void printReverse(struct node * ptr)
{
	if(ptr==NULL)
		return;		
	printReverse(ptr->link);
	printf(" %d ",ptr->info);
}
main()
{		
	int ch=1,temp,val,res;
	while(ch!=0)
	{
		printf("\n\n*******WELCOME******");
		printf("\nWhat you like to do ?");
		printf("\n1: Check the size ");
		printf("\n2: Insert at Last ");
		printf("\n3: Insert at begining");
		printf("\n4: Insert at given position");
		printf("\n5: Remove from Last ");
		printf("\n6: Remove from begining");
		printf("\n7: Remove given value");
		printf("\n8: Update value ");
		printf("\n9: Display list");
		printf("\n10: Reverse the list");
		printf("\n11: Print the list in reverse order without actual list reversal");
		printf("\n0: Exit");
		printf("\n\n Choose an option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Length of list is  : %d ",find_length());
					
					break;
			case 2:printf("\n Enter the item to add : ");
					scanf("%d",&temp);
					res=add_last(temp);
					if(res==1)
						printf("Item added Successfully");
					else
						printf("Something went wrong! try again...");
					break;
			case 3:printf("\n Enter the item to add : ");
					scanf("%d",&temp);
					res=add_first(temp);
					if(res==1)
						printf("Item added Successfully");
					else
						printf("Something went wrong! try again...");
					break;
			case 4:printf("\n Enter the item to add : ");
					scanf("%d",&temp);
					printf("\n Enter the position to insert ");
					scanf("%d",&val);
					res=add_pos(temp,val);
					if(res==1)
						printf("Item added Successfully");
					else
						printf("Invalid position");
					break;					
			case 5:printf("\nValue %d removed ",remove_last());
					break;
			case 6:printf("\nValue %d removed ",remove_first());
					break;
			case 7:printf("\nEnter the item value to delete : ");
					scanf("%d",&temp);
					int res=remove_item(temp);
					if(res!=0)
						printf("\nItem %d removed ",temp);
					else
						printf("Item %d not found",temp);
					break;
			case 8:printf("\nEnter the new value :  ");
					scanf("%d",&temp);
					printf("\nEnter the old value : ");
					scanf("%d",&val);
					res=update_item(temp,val);
					if(res!=0)
						printf("\nValue updated");
					else
						printf("Item %d not found",val);
					break;
			case  9:display();
					break;
					
			case 10: reverse();
					printf("\nReversed successfully");
					break;
					
			case 11:printf("\nThe reverse of list is: ");
					printReverse(start);
				
			default:printf("\nINVALID CHOICE");
					
			
		}
	}
}
