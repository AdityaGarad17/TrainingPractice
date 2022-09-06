#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node*next;
		
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int a)
		{
			data = a;
			next = NULL;
		}
};
class CLL
{
	Node * front;
	Node * rear;
	
	public:
		CLL()
		{
			front = NULL;
			rear = NULL;
		}
		void create()
		{
			int n;
			int i;
			cout<<"\nEnter how many nodes you want to create = ";
			cin>>n;
			cout<<"\nEnter first Node = ";
			int x;
			cin>>x;
			front = new Node(x);
			Node*p = front;
			for(i=1;i<=n-1;i++)
			{
				cout<<"\nEnter next data = ";
				cin>>x;
				p->next = new Node(x);
				p=p->next;
			
			}
			p->next = front;
			rear = p;
		}
		void show()
		{
			Node * p = front;
			do
			{
				cout<<"   "<<p->data;
				p=p->next;
			}while(p!=front);
		}
		int search(int x)
		{
			Node*p=front;
			do
			{
				if(p->data == x)
				{
					return 1;
				}
				p=p->next;
			}while(p!=front);
			return 0;
		}
		int count()
		{
			int cnt=0;
			Node*p=front;
			do
			{
				cnt++;
				p=p->next;
			}while(p!=front);
			return cnt;
		}
		void addatbeg(int x)
		{
			Node * p;
			p=new Node(x);
			if(front==NULL)
			{
				front=rear=p;
				p->next = p;
			}
			else
			{
				p->next = front;
				front = p;
				rear->next = front;
			}
		}
		void addatend(int x)
		{
			Node * p;
			p=new Node(x);
			if(front==NULL)
			{
				front=rear=p;
				p->next=p;
			}
			else
			{
				p->next=front;
				rear->next=p;
				rear = p;
			}
		}
		void addbypos(int x,int pos)
		{
			Node *p,*q;
			int n;
			n = count();
			if(pos<0 || pos>n+1)
			{
				cout<<"\nInvalid position";
				return;
			}
			if(pos == 1)
			{
				addatbeg(x);
			}
			else
			{
				q=new Node(x);
				p=front;
				int i;
				for( i =1;i<pos-1;i++)
				{
					p=p->next;
				}
				q->next = p->next;
				p->next =q;
				if(p==rear)
				{
					rear=q;
					
				}
			}
		}
		void delatbeg()
		{
			if(front==NULL)
			{
				cout<<"\nList empty";
				return;
			}
			if(front->next==rear)
			{
				delete front;
				front=rear=NULL;
			}
			else
			{
				Node*p;
				p=front;
				front = front->next;
				rear->next= front;
				delete p;
			}
		}
		void delatend()
		{
			if(front==NULL)
			{
				cout<<"\nlist empty";
				return;
			}
			if(front->next == NULL)
			{
				delete front;
				front=rear=NULL;
			}
			else
			{
				Node * p,*q;
				p=front;
				do
				{
					q=p;
					p=p->next;
				}while(p->next!=front);
				q->next=front;
				rear = q;
				delete p;	
			}
		}
		void delbypos(int pos)
		{
			Node *p,*q;
			int n=count();
			if(pos<0 || pos>n)
			{
				cout<<"\nInvalid position";
				return;
			}
			if(pos==1)
			{
				addatbeg(pos);
			}
			else
			{
				p=front;
				for(int i=1;i<=pos-1;i++)
				{
					q=p;
					p=p->next;
				}
				q->next = p->next;
				delete p;
				if(p==rear);
				{
					rear = q;
				}
			}
		}
		void makeempty()
		{
			Node*p=front;
			Node*q;
			do
			{
				q=p;
				p=p->next;
				delete q;
			}while(p!=front);
			front=rear=NULL;
		}
		
};

int main()
{
	CLL Obj;
	Obj.create();
	cout<<"\nPrinting list = ";
	Obj.show();
	cout<<"\nEnter number you want search = ";
	int x;
	cin>>x;
	int ans;
	ans = Obj.search(x);
	if(ans==1)
	{
		cout<<"\nData found";
	}
	else
	{
		cout<<"\nData not found";
	}
	ans=Obj.count();
	cout<<"\nTotal number of nodes = "<<ans;
	cout<<"\nEnter data to add at beginning = ";
	cin>>x;
	Obj.addatbeg(x);
	cout<<"\ndata after add at beginning = ";
	Obj.show();
	cout<<"\nEnter data to add at end = ";
	cin>>x;
	Obj.addatend(x);
	cout<<"\nlist after add at end = ";
	Obj.show();
	int pos;
	cout<<"\nEnter data and position you want to add = ";
	cin>>x;
	cin>>pos;
	Obj.addbypos(x,pos);
	cout<<"\nPosition after add by position = ";
	Obj.show();
	Obj.delatbeg();
	cout<<"\nData at delete at begin= ";
	Obj.show();
	Obj.delatend();
	cout<<"\nDaata after delete at end = ";
	Obj.show();
	cout<<"\nEnter position to delete data = ";
	cin>>x;
	Obj.delbypos(x);
	cout<<"\nData after delete by position = ";
	Obj.show();
	Obj.makeempty();
}