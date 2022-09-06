#include<iostream>
using namespace std;
int main()
{
	int arr[8];
	cout<<"enter 8 integer = ";
	int i,j;
	for(i=0;i<=7;i++)
	{
		cin>>arr[i];
	}
	int temp;
	for(i=0;i<=7;i++)
	{
		for(j=i+1;j<=7;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(i=0;i<=7;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
