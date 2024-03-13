#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *queue;
queue enqueue(queue rear,int x);
queue dequeue(queue rear,queue front);
int isempty(queue front);
void display(queue rear,queue front);
void greatest(queue front);
void oddeven(queue front);
int main()
{
	queue rear,front;
	front=(queue)malloc(sizeof(struct node));
	front->next=NULL;
	rear=front;
	int x,ch;
	do
	{
		printf("1->ENQUEUE.\n");
		printf("2->DEQUEUE.\n");
		printf("3->DISPLAY.\n");
		printf("4->GREATEST.\n");
		printf("5->GREATEST OF PLACES.\n");
		printf("6->EXIT.\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the Element:\n");
				scanf("%d",&x);
				rear=enqueue(rear,x);
				break;
			case 2:rear=dequeue(rear,front);
				break;
			case 3:display(rear,front);
				break;
			case 4:greatest(front);
				break;
			case 5:oddeven(front);
				break;
			case 6:break;
			default:printf("Invalid Choice.\n");
				break;
		}
	}while(ch!=6);
	return 0;
}
queue enqueue(queue rear,int x)
{	
	queue temp;
	temp=(queue)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;
	return rear;
}
queue dequeue(queue rear,queue front)
{
	queue k;
	k=(queue)malloc(sizeof(struct node));
	if(!isempty(front))
	{
		k=front->next;
		front->next=front->next->next;
		if(front->next==NULL)
			rear=front;
		printf("Popped element:%d\n",k->data);
		free(k);
	}
	else
	{
		printf("QUEUE UNDERFLOW.\n");
	}
	return rear;
}
int isempty(queue front)
{
	if(front->next==NULL)
		return 1;
	else
		return 0;
}
void display(queue rear,queue front)
{
	queue t;
	t=front;
	if(isempty(front))
	{
		printf("QUEUE IS EMPTY.\n");
	}
	else
	{
		printf("The Elements are:\n");
		while(t->next!=NULL)
		{
			t=t->next;
			printf("%d\n",t->data);
		}
	}

}
void greatest(queue front)
{
	int temp;
	if(front->next==NULL)
		printf("Queue is Empty.\n");
	while(front->next!=NULL)
	{
		if(front->data<front->next->data)
			temp=front->next->data;
		front=front->next;
	}
	printf("The Largest Element is: %d\n",temp);
}
void oddeven(queue front)
{
	int pos=0;
	int odd=0,even=0;
	if(front->next!=NULL)
	{
		while(front->next!=NULL)
		{
			front=front->next;
			pos++;
			if(pos%2!=0)
				odd=odd+front->data;
			else
				even=even+front->data;
		}
		if(odd>even)
			printf("The Sum of digits in odd Places is Greater %d\n",odd);
		else
			printf("The Sum of digits in odd Places is Greater %d\n",even);	
	}
}

