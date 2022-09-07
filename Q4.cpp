#include<iostream>
using namespace std;

int main()
{
	int * p;
	p = new int[5];
	
/*	int i;
	for(i=0;i<=4;i++)
	{
		cin>>*(p+i);
	}
	for(i=0;i<=4;i++)
	{
		cout<<*(p+i)<<endl;
	}
	delete []p;*/
	p=new int[5];
	cout<<"scan arrY FOR SEON WEMORY = ";
	for(int i=0;i<=4;i++)
	{
		cin>>*(p+i);
	}
	for(int i=0;i<=4;i++)
	{
		cout<<*(p+i)<<endl;
	}
	delete ;
	for(int i=0;i<=4;i++)
	{
		cout<<*(p+i)<<endl;
	}
}
