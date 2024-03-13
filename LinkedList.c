#include<stdio.h>
#include<stdlib.h>
int ipos=1;
struct node
{
        int empid;
        char name[20];
        char desig[20];
        char dept[20];
        int exp;
        int salary;
        struct node *next;
};
typedef struct node *list;
void insert(list head);
void delete(list head);
int issearch(int empid,list head);
void search(int empid,list head);
void retrieve(list head);
void display(list head);
void locate(list head);
void isempty(list head);
void modify(list head);
void count(list head);
void oddprint(list head);
int main()
{
        list head;
        int i,ch,n,pos=1;
        head=(list)malloc(sizeof(struct node));
	head->next=NULL;
        /*printf("Enter the No of Entries:\n");
	scanf("%d",&n);
        for(i=0;i<n;i++)
	{
		list temp,t;
		t=head;
		temp=(list)malloc(sizeof(struct node));
		printf("Enter Employee ID:\n");
        	scanf("%d",&temp->empid);
	        printf("Enter the Name of the Empolyee:\n");
        	scanf("%s",temp->name);
        	printf("Enter the Empolyee Department:\n");
        	scanf("%s",temp->dept);
        	printf("Enter the Employee Designation:\n");
        	scanf("%s",temp->desig);
        	printf("Enter Empolyee Experience:\n");
        	scanf("%d",&temp->exp);
        	printf("Enter the Empolyee Salary:\n");
        	scanf("%d",&temp->salary);
		temp->next=NULL;
		for(i=0;i<pos-1;i++)
		{
                	t=t->next;
		}
		if(t!=NULL)
		{
			while(t->next!=NULL)
			{
				t=t->next;
			}
			temp->next=t->next;
			t->next=temp;
			pos++;
		}
	}*/
        do
        {
		printf("**************************\n\n");
		printf("LINKED LIST IMPLEMENTATION\n\n");
		printf("**************************\n\n");
                printf("1.Insert.\n2.Delete.\n3.Search.\n4.Modify.\n5.Retrieve.\n6.Display.\n7.Locate.\n8.Isempty.\n9.Count.\n10.Oddprint.\n11.Exit.\n\n");
		printf("**************************\n\n");
		printf("Enter your Choice:\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:insert(head);break;
                        case 2:delete(head);break;
                        case 3: printf("Enter Empolyee ID to Search:\n");
				int id;
				scanf("%d",&id);
				search(id,head);break;
                        case 4:modify(head);break;
                        case 5:retrieve(head);break;
                        case 6:display(head);break;
                        case 7:locate(head);break;
                        case 8:isempty(head);break;
                        case 9:count(head);break;
			case 10:oddprint(head);break;
			case 11:break;
                        default:printf("Invalid Input\n");break;
                }
        }while(ch!=11);
        return 0;
}
void insert(list head)
{
	printf("EMPLOYEE DETAILS INSERTION\n\n");
	list t,temp;
	int pos,i;
	printf("Enter the Position to enter:\n");
	scanf("%d",&pos);
	if(pos<=ipos)
	{
	        temp=(list)malloc(sizeof(struct node));
	        printf("Enter Employee ID:\n");
	        scanf("%d",&temp->empid);
       		printf("Enter the Name of the Empolyee:\n");
		scanf("%s",temp->name);
		printf("Enter the Empolyee Department:\n");
		scanf("%s",temp->dept);
		printf("Enter the Employee Designation:\n");
		scanf("%s",temp->desig);
		printf("Enter Empolyee Experience:\n");
		scanf("%d",&temp->exp);
		printf("Enter the Empolyee Salary:\n");
		scanf("%d",&temp->salary);
		temp->next=NULL;
		t=head;
		for(i=0;i<pos-1;i++)
			t=t->next;
		if(t!=NULL)
		{
			temp->next=t->next;
			t->next=temp;
		}
		ipos++;
	}
	else
	{
		printf("Enter a valid Position.\n\n");
	}
}
void delete(list head)
{
	printf("EMPLOYEE DETAILS DELETION\n\n");
	list t=head,k;
	int empid,i;
	printf("Enter the Employee ID to Delete:\n");
	scanf("%d",&empid);
	k=(list)malloc(sizeof(struct node));
	i=issearch(empid,head);
	if(i==1)
	{
		while(t->next!=NULL)
		{
			if(t->next->empid!=empid)
				t=t->next;
			else
				break;
		}
		k=t->next;
		t->next=t->next->next;
		free(k);
		printf("Employee Details is Deleted.\n\n");
	}
	else
	{
		printf("Employee Details not Found.\n\n");
	}

}
int issearch(int empid,list head)
{
	list t=head;	
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->empid==empid)
			return 1;
	}
}
void search(int empid,list head)
{
	printf("EMPLOYEE DETAILS SEARCHING\n\n");
	list t=head;
	int i=0;
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->empid==empid)
		{
			i=1;
			break;
		}
	}
	if(i==1)
	{
		printf("Employee ID: %d\n",t->empid);
                printf("Employee Name: %s\n",t->name);
                printf("Employee Department: %s\n",t->dept);
                printf("Employee Designation: %s\n",t->desig);
                printf("Employee Experience: %d\n",t->exp);
                printf("Employee Salary: %d\n\n",t->salary);
	}
	else
	{
		printf("Employee Details not Found.\n\n");
	}
}
void retrieve(list head)
{
	printf("EMPLOYEE DETAILS RETRIEVING\n\n");
	list t=head;
	int i,pos;
	printf("Enter the Position:\n");
	scanf("%d",&pos);
	if(pos<=ipos)
	{
		for(i=0;i<pos;i++)
		{
			if(t->next!=NULL)
				t=t->next;
		}
		printf("The Employee Record in the Position %d is:\n",pos);
		printf("Employee ID: %d\n",t->empid);
		printf("Employee Name: %s\n",t->name);
		printf("Employee Department: %s\n",t->dept);
		printf("Employee Designation: %s\n",t->desig);
		printf("Employee Experience: %d\n",t->exp);
		printf("Employee Salary: %d\n\n",t->salary);
	}
	else
	{
		printf("Enter a valid Position.\n\n");
	}
}
void display(list head)
{
	printf("EMPLOYEE DETAILS DISPLAYING\n\n");
	list t=head;
	int i=1;
	while(t->next!=NULL)
	{
		t=t->next;
		printf("DETAILS OF EMPLOYEE NUMBER %d :\n\n",i);
		printf("Employee ID: %d\n",t->empid);
		printf("Employee Name: %s\n",t->name);
		printf("Employee Department: %s\n",t->dept);
		printf("Employee Designation: %s\n",t->desig);
		printf("Employee Experience: %d\n",t->exp);
		printf("Employee Salary: %d\n\n",t->salary);
		i++;
	}
	if(head->next==NULL)
		printf("No Records Found.\n\n");
}
void locate(list head)
{
	printf("EMPLOYEE DETAIL LOCATING\n\n");
	list t=head;
	int key,pos=0,i=0;
	printf("Enter the Employee ID to Locate:\n");
	scanf("%d",&key);
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->empid==key)
		{
			i=1;
			break;
		}
		else
		{
			pos++;
		}
	}
	if(i==1)
		printf("The Employee Detail is found in the Position %d .\n\n",pos+1);
	else
		printf("Can't Locate Employee Details.\n\n");
}
void isempty(list head)
{
	printf("LIST EMPTINESS CHECKING\n\n");
	if(head->next==NULL)
		printf("List is Empty.\n\n");
	else	
		printf("List is not Empty.\n\n");
}
void modify(list head)
{
	printf("EMPLOYEE DETAIL MODIFICATION\n\n");
	list t=head;
	int id,i;
	printf("Enter the Employee ID to be Modified:\n");
	scanf("%d",&id);
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->empid==id)
		{
			i=1;
			break;
		}
		
	}
	if(i==1)
	{
		printf("Enter New Employee ID:\n");
                scanf("%d",&t->empid);
                printf("Enter New Name of the Empolyee:\n");
                scanf("%s",t->name);
                printf("Enter New Empolyee Department:\n");
                scanf("%s",t->dept);
                printf("Enter New Employee Designation:\n");
                scanf("%s",t->desig);
                printf("Enter New Empolyee Experience:\n");
                scanf("%d",&t->exp);
                printf("Enter New Empolyee Salary:\n");
                scanf("%d",&t->salary);
                printf("Data Modified Successfully:\n\n");
	}
	else
	{
		printf("Enter a Existing Employee ID.\n\n");
	}
	
}
void count(list head)
{
	list t=head;
	int c=0;
	printf("ENTRIES COUNT.\n\n");
	while(t->next!=NULL)
	{
		c++;
		t=t->next;
	}
	printf("No of Entries: %d \n",c);
}
void oddprint(list head)
{
	list t=head;
	int pos=1;
	printf("ODD ENTRIES DISPLAY:\n\n");
	while(t->next!=NULL)
	{
		t=t->next;
		if(pos%2!=0)
		{
		        printf("DETAILS OF EMPLOYEE NUMBER %d :\n\n",pos);
                	printf("Employee ID: %d\n",t->empid);
                	printf("Employee Name: %s\n",t->name);
                	printf("Employee Department: %s\n",t->dept);
                	printf("Employee Designation: %s\n",t->desig);
                	printf("Employee Experience: %d\n",t->exp);
                	printf("Employee Salary: %d\n\n",t->salary);
		}
		pos++;
	}
	if(head->next==NULL)
		printf("No Records Found.\n");
}

