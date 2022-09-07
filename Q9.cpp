#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
	string s1;
	cout<<"Enter string (s1) = ";
	getline(cin,s1);
	string::iterator bt;
	for(bt=s1.begin();bt<s1.end();bt++)
	{
		*bt = *bt-32;
	}
	cout<<"\nyour string (s1) = "<<s1;
	
	char str[30];
	cout<<"\nEnter string(str) = ";
	cin.getline(str,30);
	int len;
	len = strlen(str);
	char ch;
	for(int i=0;str[i]!='\0';i++)
	{
	
		if(str[i]>='a' && str[i]<='z')
		{
			str[i] = str[i]-32;
		}
	}
	cout<<"\nyour string (str) = "<<str;
}
