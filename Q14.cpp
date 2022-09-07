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
			
		}
};
int main()
{
	SLL obj;
	obj.craete();
}
