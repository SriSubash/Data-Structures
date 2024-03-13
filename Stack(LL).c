#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
        char data;
        struct node *next;
};
typedef struct node *stack;
void push(char x,stack top);
char pop(stack top);
int isempty(stack top);
void display(stack top);
void reverse(char a[],stack top);
int balance(stack top);
void checkempty(stack top);
int main()
{
        stack top;
        top=(stack)malloc(sizeof(struct node));
        top->next=NULL;
	char exp[50],x;
	int ch,b;
	do
	{
		printf("1->PUSH.\n2->POP.\n3->DISPLAY.\n4->BALANCE THE EQUATION.\n5->REVERSE THE EQUATION.\n6->ISEMPTY.\n7->EXIT.\n\n");
		printf("Enter your Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the Character:\n");
				scanf("%c",&x);
				scanf("%c",&x);
				push(x,top);
				break;
			case 2: if(!isempty(top))
					printf("The Popped Element is %c.\n",pop(top));
				else
					printf("Stack Underflow.\n");
				break;
			case 4: b=balance(top);
				break;
			case 3: display(top);
				break;
			case 5: printf("Enter the Expression:\n");
				scanf("%s",exp);
				reverse(exp,top);
				break;
			case 6: checkempty(top);
				break;
			case 7: break;
			default:printf("Invalid Choice.\n");
				break;
		}
	}while(ch!=7);
	return 0;
}
void display(stack top)
{
	stack t=top;
	if(!isempty(top))
	{
		printf("The Elements are :\n");
		while(t->next!=NULL)
		{
			t=t->next;
			printf("%c\n",t->data);
		}
	}
	else
	{
		printf("The Stack is Empty.\n");
	}
}
void reverse(char a[],stack top)
{
	int len=strlen(a),i=0;
	if(isempty(top))
	{
		while(i<len)
		{
			push(a[i],top);
			i++;
		}
		printf("The Expression in Reverse Order:\n");
		for(i=0;i<len;i++)
			printf("%c",pop(top));
		printf("\n");
	}
	else
	{
		printf("The Stack is not Empty.\n");
	}
}
int balance(stack top)
{
if(isempty(top))
{
	char input[50],temp,check;
	int i=0,len;
        printf("Enter the Expression:\n");
        scanf("%s",input);
        len=strlen(input);
        while(i<len)
        {
                if(input[i]=='{'||input[i]=='('||input[i]=='[')
                {
                        push(input[i],top);
                }
		else if(input[i]=='}')
		{
			temp='{';
			check=pop(top);
		}
		else if(input[i]==')')
                {
                        temp='(';
			check=pop(top);
                }
		else if(input[i]==']')
                {
                        temp='[';
			check=pop(top);
		}
		if(check==temp)
		{
			i++;
		}
		else
		{	
			printf("EXPRESSION IS UNBALANCED.\n");
			return 1;
		}
        }
        if(isempty(top))
        {
                printf("EXPERSSION IS BALANCED.\n");
        }
	if(!isempty(top))
        {
                printf("EXPERSSION IS UNBALANCED.\n");
        }
}
else
{
	printf("The Stack is not Empty.\n");
}
}
void push(char x,stack top)
{	
        stack temp;
        temp=(stack)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        temp->next=top->next;
        top->next=temp;
}
char pop(stack top)
{
        stack k;
	char check;
        k=(stack)malloc(sizeof(struct node));
	if(top->next!=NULL)
	{
        	k=top->next;
		check=k->data;
        	top->next=top->next->next;
        	free(k);
		return check;
        }
}
int isempty(stack top)
{
	if(top->next==NULL)
		return 1;
	else
		return 0;
}
void checkempty(stack top)
{
	if(top->next==NULL)
		printf("The Stack is Empty.\n");
	else
		printf("The Stack is not Empty.\n");
}

