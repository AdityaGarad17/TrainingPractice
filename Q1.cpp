#include<iostream>
using namespace std;

int main()
{
	int n,fsum,csum=0;
	cout<<"enter number = ";
	cin>>n;
	
	fsum = n*(n+1)/2;
	cout<<"\nfsum = "<<fsum;
	
	for(int i=1;i<=n;i++)
	{
		csum = csum + i;
	}
	cout<<"\ncsum = "<<csum;
	
	return 0;
}
