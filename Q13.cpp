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
class SLL
{
	Node * front;
	Node * rear;
	public:
		
		SLL()
		{
			front = NULL;
			rear = NULL;
		}
		
		void create()
		{
			int n,x;
			cout<<"\nEnter how many nodes you want to create = ";
			cin>>n;
			Node * p;
			cout<<"\nEnter first Node = ";
			cin>>x;
			front = new Node(x);
			p = front;
			for(int i=1;i<=n-1;i++)
			{
				cout<<"\nEnter next data = ";
				cin>>x;
				p->next = new Node(x);
				p = p->next;
			}
			p->next = front;
			rear = p;
			cout<<"\nList Created.";
		}
		
		void show()
		{
			Node * p = front;
			do
			{
				cout<<p->data<<"  ";
				p = p->next;
			}while(p!=front);
		}
		int search(int ele)
		{
			Node * p = front;
			do
			{
				if(p->data == ele)
				{
					return 1;
				}
				p=p->next;
			}while(p!=front);
			return 0;
		}
		
		int count()
		{
			Node * p =front;
			int cnt = 0;
			do
			{
				cnt++;
				p=p->next;
			}while(p!=front);
			return cnt;
		}
		
		void addatbeg(int x)
		{
			Node *p;
			p = new Node(x);
			if(front == NULL)
			{
				front=rear=p;
				p->next = front;
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
			Node * p,*q;
			q = new Node(x);
			if(front== NULL)
			{
				front=rear=q;
				q->next = front;
			}
			else
			{
				p = front;
				while(p->next!=front)
				{
					p=p->next;
				}
				q->next = p->next;
				p->next = q;
				rear = q;
			}
		}
		
		void addbypos(int x,int pos)
		{
			Node *p,*q;
			q=new Node(x);
			int n = count();
			if(pos<1 || pos >n+1)
			{
				cout<<"\nInalid position";
				return;
			}
			if(pos==1)
			{
				addatbeg(x);
			}
			else
			{
				int i;
				p=front;
				for(i=1;i<pos-1;i++)
				{
					p=p->next;
				}
				q->next=p->next;
				p->next  = q;
				if(p==rear)
				{
					rear = q;
				}
			}
		}
		
		void asort()
		{
			Node *i,*j;
			i=front;
			do
			{
				for(j=i->next;j!=front;j=j->next)
				{
					if(i->data > j->data)
					{
						int temp;
						temp =i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
				i = i->next;
			}while(i!=front);
		}
		
		void dsort()
		{
			Node*i,*j;
			i = front;
			do
			{
				for(j=i->next;j!=front;j=j->next)
				{
					if(i->data < j->data)
					{
						int temp;
						temp = i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
				i = i->next;
			}while(i!=front);
		}
		
		void delatbeg()
		{
			Node *p;
			if(front == NULL)
			{
				cout<<"\nEmpty list";
			}
			else
			{
				p=front;
				front = front->next;
				rear->next = front;
				delete p;
			}
		}
		
		void delatend()
		{
			Node *p,*q;
			if(front == NULL)
			{
				cout<<"\nList Empty";
			}
			else
			{
				p=front;
				while(p->next!=front)
				{
					q=p;
					p=p->next;
				}
				delete p;
				q->next=front;
				rear = q;
			}
		}
		
		void delbypos(int pos)
		{
			Node *p,*q;
			int n = count();
			if(pos<1 || pos>n)
			{
				cout<<"\nInvalid position";
				return;
			}
			if(pos==1)
			{
				delatbeg();
			}
			else
			{
				p = front;
				for(int i=1;i<=pos-1;i++)
				{
					q=p;
					p=p->next;
				}
				q->next = p->next;
				p->next = NULL; //make p->next NULL is not compulsory.
				delete p;
				if(p==rear)
				{
					rear=q;
				}
			
			}
		}
};
int main()
{
	SLL obj;
	obj.create();
	
	cout<<"\nShowing your list =  ";
	obj.show();
	
	int ele;
	cout<<"\nEnter Data you want search = ";
	cin>>ele;
	int res;
	res = obj.search(ele);
	if(res == 1)
	{
		cout<<"\nData found.";
	}
	else
	{
		cout<<"\nData not found.";
	}
	
	res = obj.count();
	cout<<"\n Total number of elements are = "<<res;
	
	cout<<"\nEnter element to add begin = ";
	int x;
	cin>>x;
	obj.addatbeg(x);
	cout<<"\nShowing data after add at begin = ";
	obj.show();
	
	cout<<"\nEnter data to at end = ";
	cin>>x;
	obj.addatend(x);
	cout<<"\nShowing data after add at end =";
	obj.show();
	
	cout<<"\nEnter position to add data = ";
	int pos;
	cin>>pos;
	cout<<"\nEnter data to add at position ";
	cin>>x;
	obj.addbypos(x,pos);
	cout<<"\nShowing data after add at position = ";
	obj.show();
	
	obj.asort();
	cout<<"\nShowing data in ascending order =  ";
	obj.show();
	
	obj.dsort();
	cout<<"\nShowing data in decending order = ";
	obj.show();
	
	obj.delatbeg();
	cout<<"\nShowing data after delete at begin = ";
	obj.show();
	
	obj.delatend();
	cout<<"\nShowing data after delete at end = ";
	obj.show();
	
	cout<<"\nEnter a position to delete data = ";
	cin>>pos;
	obj.delbypos(pos);
	cout<<"\nShowing data after delete by position = ";
	obj.show();
}
