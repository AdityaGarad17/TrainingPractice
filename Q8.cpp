#include<iostream>
using namespace std;
#include<string>
#include<string.h>

int main()
{
	string s1;
	cout<<"Enter a string = ";
	getline(cin,s1);
	string::iterator it;
	int count=0;
	for(it=s1.begin();it<=s1.end();it++)
	{
		count++;
	}
	cout<<"\ncount = "<<count;
	
	char str1[30];
	cout<<"\nEnter a string 2 = ";
	cin.getline(str1,30);
	int i,count2=0;
	for(i=0;str1[i]!='\0';i++)
	{
		count2++;
	}
	cout<<"\ncount2 = "<<count2;
	string s2;
	int len1,len2;
	int count3=0,count4=0;
	cout<<"\nEnter a string 3 = ";
	getline(cin,s2);
	len1=s2.length();
	cout<<"\nLength of 3rd string = "<<len1<<" and capacity of string is = "<<s2.capacity();
	
	char str2[30];
	cout<<"\nEnter a string 4 = ";
	cin.getline(str2,30);
	len2=strlen(str2);
	cout<<"\nLength of 4th string = "<<len2;
	
	char str3[30];
	strcpy(str3,str2);
	string s3;
	s3 = s2;
	s3.append(" from Chhatrapati Sambhajinagar.");
	
	cout<<"\ncopied 5th string(str3) = "<<str3<<"\ncopied 6th string(s3) = "<<s3;
	
}
