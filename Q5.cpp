
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[30];
	char ptr[30];
	cout<<"enter a string = "<<endl;
	cin.getline(str,30);
	cout<<str;
	strcpy(ptr,str);
	cout<<"\nprintig copied string = "<<ptr;
	int length;
	length = strlen(str)-1;
	cout<<"\nlength of string is = "<<length;
	int i=0;
	int j=length;
	char str2[30];
	while(str[j]>=0)
	{
		str2[i]=str[j];
		i++;
		j--;
	}
	cout<<"\nprinting reverse string = "<<str2;
	strrev(str2);
	cout<<"\nprinting string of reverse function = "<<str2;
	int a,b;
	cout<<"\nenter a = ";
	cin>>a;
	cout<<"\nenter b = ";
	cin>>b;
	cout<<"\n a = "<<a<<"   b = "<<b;
;
}
