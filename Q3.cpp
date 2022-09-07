#include<iostream>
using namespace std;

int main()
{
	int i,j,k,cnt=1;
	
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			cout<<cnt<<" ";
			cnt++;
		}
		cout<<endl;
		for( k=0;k<=1;k++)
		{
			cout<<cnt<<" ";
			cnt++;
		}
		cout<<endl;
	}
}
