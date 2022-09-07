#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[30];
	cout<<"\nEnter a string = ";
	cin.getline(str,30);
	char ptr[30];
	int len;
	len = strlen(str)-1;
	int i=0,j=len;
	while(str[j]>=0)
	{
		ptr[i]=str[j];
		i++;
		j--;
	}
	cout<<"\nReversed string = "<<ptr;
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=ptr[i])
		{
			cout<<"\nNot Palindrome ";
			return 0;
		}
	}
	cout<<"\nPalindrome.";
	
}
