#include<stdio.h>
void insert(int a[],int pos,int element);
void delete(int a[],int pos);
void search(int a[],int element);
void modify(int a[],int pos,int element);
void retrieve(int a[],int pos);
void display(int a[]);
int n;
int main()
{
	int i,a[50],pos,ch,element;
	printf("Enter the Number of Elements:\n");
	scanf("%d",&n);
	printf("Enter the Elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	do
	{
		printf("Basic Operations on Array.\n");
		printf("Press 1 for Insertion.\n");
		printf("press 2 for Deletion.\n");
		printf("Press 3 for Searching.\n");
		printf("Press 4 for Modification.\n");
		printf("Press 5 for Retrieving.\n");
		printf("Press 6 for Displaying.\n");
		printf("Press 7 for Exit.\n");
		printf("Enter your Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Element Insertion.\n");
				printf("Enter the Position to Insert:\n");
				scanf("%d",&pos);
				printf("Enter the Element to Insert:\n");
				scanf("%d",&element);
				insert(a,pos,element);
				display(a);
				break;
			case 2: printf("Element Deletion.\n");
                                printf("Enter the Position to Delete:\n");
                                scanf("%d",&pos);
                                delete(a,pos);
                                display(a);
                                break;
		        case 3: printf("Element Searching.\n");
                                printf("Enter the Element to Search:\n");
                                scanf("%d",&element);
                                search(a,element);
                                display(a);
                                break;
			case 4: printf("Element Modificatio.\n");
                                printf("Enter the Position to Modify:\n");
                                scanf("%d",&pos);
                                printf("Enter the Element to Modify:\n");
                                scanf("%d",&element);
                                modify(a,pos,element);
                                display(a);
                                break;
			case 5: printf("Element Retrieving.\n");
                                printf("Enter the Position to Retrieve:\n");
                                scanf("%d",&pos);
                                retrieve(a,pos);
                                display(a);
                                break;
			case 6: printf("Element Display.\n");
				display(a);
				break;
			case 7: break;
			default:printf("Invalid Input.\n");
				break;
		}
	}while(ch!=7);
return 0;
}
void insert(int a[],int pos,int element)
{
	if(pos<=n)
	{
		int i;
		n++;
		for(i=n-1;i>=pos;i--)
			a[i]=a[i-1];
		a[pos-1]=element;
		printf("Element Inserted Successfully.\n");
	}
	else
	{
		printf("Please Enter a valid Position.\n");
	}
}
void delete(int a[],int pos)
{
	if(pos<=n)
	{
		int i;
		for(i=pos-1;i<n;i++)
			a[i]=a[i+1];
		n--;
		printf("Element Deleted Successfully.\n");
	}
	else if(pos>n)
	{
		printf("Please Enter a valid Position.\n");
	}
	else
	{
		printf("All Elements are Deleted.\n");
	}
}
void search(int a[],int element)
{
	int i,flag;
	for(i=0;i<n;i++)
	{
		if(a[i]==element)
		{
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==1)
		printf("Element not Found.\n");
	else
		printf("Element is found at Position %d\n",i+1);
}
void modify(int a[],int pos,int element)
{
	if(pos<=n)
	{
		a[pos-1]=element;
		printf("Element in Position %d is modifed to %d\n",pos,element);
	}
	else
	{
		printf("Position is out of Index.\n");
	}
}
void retrieve(int a[],int pos)
{
	if(pos<=n)
		printf("The Element at postion %d is %d\n",pos,a[pos-1]);
	else
		printf("Element not Found or Position is Invalid.\n");
}
void display(int a[])
{
	if(n!=0)
	{
		printf("The Elements are:\n");
		int i;
		for(i=0;i<n;i++)
			printf("%d\n",a[i]);
	}
	else
	{
		printf("No Elements in the Array.\n");
	}
}

