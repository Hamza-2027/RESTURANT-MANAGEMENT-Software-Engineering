#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct node *next;

};

struct node *headc = NULL,*newnode,*tailc = NULL;
struct node *heada = NULL,*taila = NULL;
struct node *head_s;

void adminmenu()
{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t1. Place Your Order\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t2. View Your Ordered Item's\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete An Item From Order\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Final Bill\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t5. Back To Main Menu\n";
	cout<<"\n\t\t\t\t\t\t\t\t Enter Your Choice-------->\n";
}

void customermenu()
{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t1. Place Your Order\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t2. View Your Ordered Item's\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete An Item From Order\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Final Bill\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t5. Back To Main Menu\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t     Enter Your Choice------>\n";
}

struct node* createadmin(struct node *head,int data, char foodname[25],float price)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = data;
	newnode->price = price;
	newnode->quantity = 0;
	strcpy(newnode->foodname, foodname);
	newnode->next = NULL;
	
	struct node *temp = head;
	
	if(temp==NULL)
        head = taila = newnode;
    else
	{
		while(temp->next!=NULL)
		temp=temp->next;
		
		temp->next=newnode;
        taila = newnode;
    }
	
	return heada;
}

struct node* createcustomer(struct node *head,int data,int quantity)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	struct node *temp1 = heada;
	int flag = 0;
	while(temp1!=NULL)
	{
		if(temp1->data==data)
		{
		flag = 1;
		break;	
		}
		temp1 = temp1->next;
	}
	
	if(flag==1)
	{
		newnode->data = data;
	    newnode->price = quantity*(temp1->price);
	    newnode->quantity = quantity;
	    strcpy(newnode->foodname,temp1->foodname);
	    newnode->next =NULL;
	
	 struct node *temp = head;
	
 	 if(temp==NULL)
        head = tailc = newnode;
     else
	   {
		 while(temp->next!=NULL)
		 temp=temp->next;
		
		 temp->next=newnode;
         tailc = newnode;
        }
    }
    else
    {
    	cout<<"\n\t\t\t\t\t\t This Items Is Not Present In The Menu!\n";
	}
	return headc;
}

void displayList(struct node *head)
{
	struct node *temp1 = head;
	if(temp1==NULL)
	{
		cout<<"\n\t\t\t\t\t\t\t\tList Is Empty!!\n\n";
	}
	else
	{
		cout<<"\n";
		while(temp1!=NULL)
		{
			if(temp1->quantity==0)
			  cout<<"\t\t\t\t\t\t\t%d\t%s\t\t%0.2f\n",temp1->data,temp1->foodname,temp1->price;
			  else
			  {
			  	cout<<"\t\t\t\t\t\t\t%d\t%s\t\t%d\t\t%o.2f\n",temp1->data,temp1->foodname,temp1->quantity,temp1->price;
			  }
			  
			  temp1 = temp1->next;
		}
	cout<<"\n";	
	}
}

struct node* totalsale(int data,int quantity)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	int flag = 0;
	
	struct node *temp1 = heada;
	while(temp1->data!=data)
	{
		temp1 = temp1->next;
	}
	
	    newnode->data = data;
	    newnode->price = quantity*(temp1->price);
	    newnode->quantity = quantity;
	    strcpy(newnode->foodname,temp1->foodname);
	    newnode->next =NULL;
	
	 struct node *temp = head_s;
	
 	 if(temp==NULL)
        head_s = tailc = newnode;
     else
	   {
		 while(temp->next!=NULL)
		 {
		 	if(temp->data==data)
		 	{
		 		flag = 1;
		 		break;
			 }
			 temp=temp->next;
		 }
		 
		 if(flag==1)
		 {
		 	temp->quantity += newnode-> quantity;
		 	temp->price += newnode-> price;
		 }
		 else
		 {
		 	temp->next=newnode;
		 }
		
        }
        
        return head_s;
}

void calculatesale()
{
	struct node *temp = headc;
	while(temp!=NULL)
	{
		head_s = totalsale(temp->data, temp->quantity);
		temp=temp->next;
	}
}

struct node* delete(int data,struct node *head, struct node* tail)
{
	if(head==NULL)
	{
		cout<<"\n\t\t\t\t\t\t\tList Is Empty";
	}
	else
	{
		struct node* temp;
		if(data==head->data)
		{
			temp = tail;
			tail->next = NULL;
			free(temp);
		}
		else
		{
			temp = head;
			struct node* temp1=temp;
			while(data!=temp->data)
			{
				temp1=temp;
				temp = temp->next;
			}
			temp1->next = temp->next;
			free(temp);
		}
    }
    return head;
}

int deleteadmin()
{
	cout<<"\n\t\t\t\t\tEnter Serial No. Of The Food Item Which Is To Be Deleted:";
	int num;
	cout<<"%d",&num;
	
	struct node* temp=heada;
	while(temp!=NULL)
	{
		if(temp->data == num)
		{
			heada = delete(num, heada, taila);
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

int deletecustomer()
{
	cout<<"\n\t\t\t\t\tEnter Serial No. Of The Food Item Which Is To Be Deleted:";
	int num;
	cout<<"%d",&num;
	
	struct node* temp=headc;
	while(temp!=NULL)
	{
		if(temp->data == num)
		{
			headc = delete(num, headc, tailc);
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

void displaybill()
{
	displayList(headc);
	struct node *temp =headc;
	float total_price = 0;
	while (temp!=NULL)
	{
	  total_price +=(temp->quantity)*(temp->price);
	  temp = temp->next;
	}
	
	cout<<"\t\t\t\t\t\t\tTotal Price: %0.2f\n,",total_price;
	
}

struct node* deleteList(struct node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		struct node* n, *temp=head;
		
		while(temp!=NULL)
		{
			n=temp->next;
			free(temp);
			temp=n;
		}
		head=NULL;
	}
	return head;
}

void admin()
{
  cout<<"\n\t\t\t\t\t  --------------------------------------------\n";
  cout<<"\t\t\t\t\t\t\t             ADMIN SECTION\n";
  cout<<"\n\t\t\t\t\t  --------------------------------------------\n";	
  while(1)
  {
  	adminmenu();
  	
  	int opt;
  	cin>>"%d",&opt;
  	
  	if(opt==5)
  	    break;
  	    
     switch (opt)
     {
     	case 1:
     		displayList(head_s);
     		break;
     	case 2:
		    cout<<"\n\t\t\t\t\t\t\tEnter Serial No. Of The Food Item:";
			int num,flag = 0;
			char name[50];
			float price;
			cin>>"%d",&num;
				
			struct node *temp = heada;
			
			while(temp!=NULL)
			{
				if(temp->data==num)
				{
					cout<<"\n\t\t\t\t\t\tFood Item With Given Number Already Exists!!\n\n";
					flag = 1;
					break;	
				}
				temp = temp->next;
			}	
			
			if(flag==1)
			    break;
			    
			cout<<"\t\t\t\t\t\t\tEnter Food Item Name: ";
			cin>>"%s",name;
			cout<<"\t\t\t\t\t\t\tEnter Price: ";
			cin>>"%f",price;
			heada = createadmin(heada, num, name, price);
			cout<<"\n\t\t\t\t\t\t\tNew Food Item Added To The List!!\n\n";
			break;
			
		case 3:
		if(deleteadmin())
		{
			cout<<"\n\t\t\t\t\t\t\t### Updated List Of Food Items Menu ###\n";
			displayList(heada);
		}
		else
		cout<<"\n\t\t\t\t\t\t\t\tFood Item With Given Serial No. Doesn't Exist!\n\n";
		break;
		
		case 4:
		cout<<"\n\t\t\t\t\t\t\t    ### order Menu ###\n ";
		displayList(heada);
		break;
		
		default:
		cout<<"\n\t\t\t\t\t\t\ Wrong Input !! Please Choose Valid Option\n";
		break;	    
	 }
  }
}

void customer
{
	int flag=0,j=1;
	char ch;
	cout<<"\n\t\t\t\t\t\t  ---------------------------------------------------\n";
	cout<<"\t\t\t\t\t\t\t\t            CUSTOMER SECTION";
	cout<<"\t\t\t\t\t\t\t  ---------------------------------------------------\n";
	while(1)
	  {
  	customermenu();
  	
  	int opt;
  	cin>>"%d",&opt;
  	
  	if(opt==5)
  	    break;
  	    
     switch (opt)
     {
     	case 1:
     		displayList(heada);
     		cout<<"\n\t\t\t\t\t\t\t\tEnter Number Corresponding To The Item You Want To Order: ";
     		int n;
     		cin>>"%d",&n;
     		cout<<"\t\t\t\t\t\t\tEnter Quantity: ";
     		int quantity;
     		cin>>"%d",&quantity;
     		headc = createcustomer(headc, n, quantity);
     		break;
     	case 2:
		 cout<<"\n\t\t\t\t\t\t\t\t   ### List Of Ordered Items ###\n  ";
		 displayList(headc);
		 break;
		case 3:
		 if(deletecustomer()) 
		 {
		 	cout<<"\n\t\t\t\t\t\t### Updated List Of Your Ordered Food Items ###\n ";
		 	displayList(headc);
		 }
		else
		cout<<"\n\t\t\t\t\t\t\t\tFood Item With Given Serial No. Doesn't Exist:\n";
		break;
		case 4:
			calculatetotsales();
			cout<<"\n\t\t\t\t\t\t\t\t\t   ### Final Bill ###\n";
			displaybll();
			headc = deleteList(headc);
			cout<<"\n\t\t\t\t\t\t\t\t\tPress Any Key To Return To Main Menu:\n\t\t\t\t\t\t";
			fflush(stdin);
			ch=fgetc(stdin);
			flag=1;
			break;
		default:
		cout<<"\n\t\t\t\t\t\t\t\tWrong Input !!! Please Choose Valid Option\n";
		break;			
	 }
	 if(flag==1)
	 break;

    }
}

void mainmenu()
{
	cout<<"\n                                         *****************************************************************************************\n";
	cout<<"                                                                WELCOME TO RESTAURANT MANAGEMENT SYSTEM\n";
	cout<<"                                         *****************************************************************************************\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t1. ADMIN SECTION--> \n";
	cout<<"\t\t\t\t\t\t\t\t2. CUSTOMER SECTION-->  \n";
	cout<<"\t\t\t\t\t\t\t\t3. EXIT-->  \n";
	cout<<"\t\t\t\t\t\t\t\t ENTER YOUR CHOICE-->  ";
	
}

int main()
{
	heada = createadmin(heada,1,"Hot And Sour Soup",100);
	heada = createadmin(heada,2,"Shawarma",200);
	heada = createadmin(heada,3,"Fried Rice",100);
	heada = createadmin(heada,4,"Burger",150);
	heada = createadmin(heada,5,"Briyani",100);
	
	while(1)
	{
		mainmenu();
		int choice;
		cin>>"%d",&choice;
		
		if(choice==3)
		{
			cout<<"\n\n\n\t\t\t\t\t\t\t\t***************Thank You!**************\n";
			break;
		}
		
	switch (choice)
	{
		case 1:
			admin();
			break;
		case 2:
		    customer();
		case 3:
		    break;	
		
		default:
		cout<<"\n\t\t\t\t\t\t\tWrong Input !! Please Choose Valid Option\n";
		break;		
		}	
	}
	return 0;
}
