#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string s;
	cout<<"\nEnter a string(s) = ";
	getline(cin,s);
	string::iterator it;
	int cnt1=0,cnt2=0;
	for(it=s.begin();it<=s.end();it++)
	{
		if(*it=='a' || *it=='e' || *it=='i' || *it=='o' || *it=='u')
		{
			cnt1++;
		}
		if(*it==' ')
		{
			cnt2++;
		}
	}
	cout<<"\nNumber of vowels = "<<cnt1<<"  And Number of words = "<<cnt2+1;
	
	char str[30];
	cout<<"\nEnter a string (str) = ";
	cin.getline(str,30);
	int cnt3=0,cnt4=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
		{
			cnt3++;
		}
		if(str[i]==' ')
		{
			cnt4++;
		}
	}
	cout<<"\nNumber of vowels in str = "<<cnt3<<" And Number of words = "<<cnt4+1;
	
}
