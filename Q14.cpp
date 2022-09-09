#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node * prev;
		Node * next;
		
		Node()
		{
			data = 0;
			prev=next=NULL;
		}
		Node(int x)
		{
			data = x;
			prev=next=NULL;
		}
};
class SLL
{
	Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create()
		{
			int n,x;
			cout<<"\nEnter how many nodes you want create = ";
			cin>>n;
			cout<<"\nEnter first data = ";
			cin>>x;
			head = new Node(x);
			Node * p=head;
			int i;
			for(i=1;i<=n-1;i++)
			{
				cout<<"\nEnter next data = ";
				cin>>x;
				p->next = new Node(x);
				p->next->prev=p;
				p=p->next;
			}
			cout<<"list created.";
		}
		
		void show()
		{
			Node * p=head;
			while(p!=NULL)
			{
				cout<<p->data<<"  ";
				p=p->next;
			}
		}
		
		int count()
		{
			int cnt=0;
			Node * p;
			p = head;
			while(p!=NULL)
			{
				cnt++;
				p= p->next;
			}
			return cnt;
		}
		
		void prevshow()
		{
			Node *p=head;
			while(p->next!=NULL)
			{
				p = p->next;
			}
			while(p!=NULL)
			{
				cout<<p->data<<"  ";
				p=p->prev;
			}
		}
		
		void addatbeg(int x)
		{
			Node * p =new Node(x);
			if(head == NULL)
			{
				head = p;
			}
			else
			{
				p->next = head;
				head = p;
				head->next->prev = p;
			}	
		}
		
		void addatend(int x)
		{
			Node *p,*q;
			q =new Node(x);
			if(head == NULL)
			{
				head = q;
			}
			else
			{
				p = head;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				q->next = p->next;
				p->next = q;
				q->prev = p;
			}
		}
		
		void addbypos(int x,int pos)
		{
			Node *p,*q;
			q=new Node(x);
			int n=count();
			if(pos<1 || pos>n+1)
			{
				cout<<"\nIvalid position.";
				return;
			}
			if(pos==1)
			{
				addatbeg(x);
			}
			else
			{
				p=head;
				for(int i=1;i<pos-1;i++)
				{
					p=p->next;
				}
				q->next = p->next;
				p->next =q;
				q->prev = p;
				if(q->next!=NULL)
				{
					q->next->prev = q;
				}
			}
		}
		
		void delatbeg()
		{
			Node*p;
			if(head == NULL)
			{
				cout<<"\nList empty";
				return;
			}
			else
			{
				if(head->next==NULL)
				{
					head=NULL;
					delete head;
					cout<<"\nData deleted.";
				}
				else
				{
					p=head;
					head=head->next;
					head->prev=NULL;
					delete p;
					cout<<"\nData deleted.";
				}
			}
		}
		
		void delatend()
		{
			Node*p,*q;
			if(head==NULL)
			{
				cout<<"\nList Empty.";
				return;
			}
			else
			{
				if(head->next==NULL)
				{
					head = NULL;
				}
				else
				{
					p=head;
					while(p->next!=NULL)
					{
						q=p;
						p=p->next;
					}
					q->next=NULL;
					delete p;
				}
			}
			cout<<"\nData Deleted";
		}
		
		void delbypos(int pos)
		{
			Node*p,*q;
			int n=count();
			if(pos<1 || pos>n)
			{
				cout<<"\nInvalid Position.";
				return;
			}
			if(pos==1)
			{
				delatbeg();
			}
			else
			{
				p=head;
				for(int i=1;i<=pos-1;i++)
				{
					q=p;
					p=p->next;
				}
				q->next = p->next;
				if(p->next!=NULL)
				{
					p->next->prev = q;
				}
				delete p;
			}
			
		}
	
};
int main()
{
	SLL obj;
	int choice;
	
	do
	{
		cout<<"\nPress :-";
		cout<<"\n1. Create List.";
		cout<<"\n2. Show Data.";
		cout<<"\n3. Count Nodes.";
		cout<<"\n4. Prev show.";
		cout<<"\n5. Add at begin.";
		cout<<"\n6. Add at end.";
		cout<<"\n7. Add by position.";
		cout<<"\n8. Delete at begin.";
		cout<<"\n9. Delete at end.";
		cout<<"\n10. Delete by position.";
		cout<<"\n11. To stop the execution of code.";
		cout<<"\nEnter your Choice = ";
	
		cin>>choice;
		switch(choice)
		{
			case 1:
				 obj.create();
				 break;
			 
			case 2:
				cout<<"\nShowing your data = ";
				obj.show();
				break;
				
			case 3:
				int res;
				res = obj.count();
				cout<<"\nTotal number of Node are= "<<res;
				break;
			
			case 4:
				cout<<"\nShowing data using previous Node = ";
				obj.prevshow();
				break;
			
			case 5:
				cout<<"\nEnter data to add at begin = ";
				int x;
				cin>>x;
				obj.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to add at end = ";
				cin>>x;
				obj.addatend(x);
				break;
				
			case 7:
				cout<<"\nEnter position to add a data = ";
				int pos;
				cin>>pos;
				cout<<"\nEnter data to add at position = ";
				cin>>x;
				obj.addbypos(x,pos);
				
			case 8:
				obj.delatbeg();
				break;
				
			case 9:
				obj.delatend();
				break;
				
			case 10:
				cout<<"\nEnter position to delete data = ";
				cin>>pos;
				obj.delbypos(pos);
				break;
				
		}
	}while(choice!=11);
	
	cout<<"code terminated";	
}
