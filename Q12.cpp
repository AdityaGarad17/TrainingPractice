#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;

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
	Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		int search(int fd);
		int count();
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int x,int pos);
		void delatbeg();
		void delatend();
		void delbypos(int x);
		
};
int main()
{
	SLL obj;
	obj.create();
	cout<<"\nList Created.";
	cout<<"\nShowing your List =  ";
	obj.show();
	cout<<"\nEnter data you want to search = ";
	int fd;
	cin>>fd;
	int res;
	res = obj.search(fd);
	if(res == 1)
	{
		cout<<"\nData found";
	}
	else
	{
		cout<<"\nData Not Found";
	}
	res = obj.count();
	cout<<"\nTotal number of nodes are = "<<res;
	cout<<"\nEnter data to add at begin = ";
	int x;
	cin>>x;
	obj.addatbeg(x);
	cout<<"\nShowing data after add at begin = ";
	obj.show();
	cout<<"\nEnter data to add at end = ";
	cin>>x;
	obj.addatend(x);
	cout<<"\nShowing data after add at end = ";
	obj.show();
	int pos;
	cout<<"\nEnter postion to add data = ";
	cin>>pos;
	cout<<"\nEnter data to add on position = ";
	cin>>x;
	obj.addbypos(x,pos);
	cout<<"\nShowing data after add at position = ";
	obj.show();
	obj.delatbeg();
	cout<<"\nShowing data after delete at begin = ";
	obj.show();
	obj.delatend();
	cout<<"\nShowing data after delete at end = ";
	obj.show();
	cout<<"\nEnter position to delete by postion = ";
	cin>>pos;
	obj.delbypos(pos);
	cout<<"\nShowing data after delete at end = ";
	obj.show();
}
void SLL::create()
{
	Node * p;
	int n,x;
	cout<<"\nEnter how many nodes you want create = ";
	cin>>n;
	cout<<"\nEnter data for fist Node = ";
	cin>>x;
	head = new Node(x);
	p=head;
	int i;
	for( i=1;i<=n-1;i++)
	{
		cout<<"\nEnter next data = ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
}
void SLL::show()
{
	Node*p;
	p = head;
	while(p!=NULL)
	{
		cout<<p->data<<"  ";
		p = p->next;
	}
}
int SLL::search(int fd)
{
	Node * p;
	p = head;
	while(p!=NULL)
	{
		if(p->data == fd)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}
int SLL::count()
{
	Node * p;
	p=head;
	int cnt = 0;
	while(p!=NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void SLL::addatbeg(int x)
{
	Node * p = new Node(x);
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}
void SLL::addatend(int x)
{
	Node * p,*q;
	q= new Node(x);
	if(head == NULL)
	{
		head = q;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = q;
	}
}
void SLL::addbypos(int x,int pos)
{
	Node * p,*q;
	q = new Node(x);
	p=head;
	int n= count();
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid position ";
		return;
	}
	if(pos == 1)
	{
		addatbeg(x);
	}
	else
	{
		int i;
		for(i=1;i<pos -1;i++)
		{
			p=p->next;
		}
		q->next = p->next;
		p->next = q;
	}
}
void SLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nList Empty.";
	}
	else
	{
		Node * p;
		p= head;
		head = head->next;
		delete p;
	}
}
void SLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\nList is empty ";
	}
	else
	{
		Node * p =head;
		Node * q;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		delete p;
		q->next=NULL;	
	}
}
void SLL::delbypos(int pos)
{
	Node *p;
	p=head;
	int n;
	n=count();
	if(pos<1 ||pos>n)
	{
		cout<<"\nInvalid position for deleting data";
		return;
	}
	if(pos==1)
	{
		delatbeg();
	}
	else
	{
		Node*q;
		int i;
		for(i=1;i<=pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next = p->next;
		p->next = NULL;
		delete p;
		
	}
}
