#include<stdio.h>
#include<conio.h>
#define MAX 20

int find_length();
int add_first(int item);
int add_last(int item);
int add_pos(int item,int pos);
int remove_last();
int remove_first();
int remove_item(int item);
void update_item(int item,int pos);
void display();

int array[MAX],end=-1;
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
					update_item(temp,val);
					break;
			case  9:display();
			
		}
	}
}
int find_length()
{
	int temp=end;
	temp=temp+1;
	return (temp);
}
int add_first(int item)
{
	int  i;
	for(i=end;i>=0;i--)
	{
		array[i+1]=array[i];
	}
	end=end+1;
	array[0]=item;
	return 1;
}
int add_last(int item)
{
	end=end+1;
	array[end]=item;
	return 1;
}
int add_pos(int item,int pos)
{
	if(pos>end)
	{
		return 0;	
	}
		
	else 
	{
		int i;
		for(i=end;i>=pos-1;i--)
		{
			array[i+1]=array[i];
		}
		return 1;
	}
}
int remove_last()
{
	int temp=array[end];
	end=end-1;
	return temp;
}
int remove_first()
{
	int i;
	int temp=array[0];
	for(i=0;i<end;i++)
	{
		array[i]=array[i+1];
	}
	end=end-1;
	return temp;
}
int remove_item(int item)
{
	int i;
	for(i=0;i<=end;i++)
	{
		if(array[i]==item)
			break;
	}
	if(i==end)
		return 0;
	int temp=array[i];
	for(i;i<end;i++)
	{
		array[i]=array[i+1];
	}
	return temp;
	end=end-1;
}
void update_item(int item,int pos)
{
	array[pos-1]=item;
}
void display()
{
	int i;
	printf("\nArray contents are: ");
	for(i=0;i<=end;i++)
		printf(" %d ",array[i]);
}
