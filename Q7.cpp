#include<iostream>
using namespace std;
void upadjustment(int * heap,int i)
{
	while(i/2>0)
	{
		if(heap[i]>heap[i/2])
		{
			swap(heap[i],heap[i/2]);
			i=i/2;
		}
		else
		{
			break;
		}
	}
}

void printarray(int * heap)
{
	for(int i=1;i<=heap[0];i++)
	{
		cout<<heap[i]<<"   ";
	}
}
int main()
{
	int n;
	int * heap;
	cout<<"Enter number elements = ";
	cin>>n;
	heap = new int[n+1];
	heap[0] = 0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cout<<"\nEnter element = ";
		cin>>x;
		heap[i]=x;
		heap[0]++;
		upadjustment(heap,i);
	}
	printarray(heap);
	
}

