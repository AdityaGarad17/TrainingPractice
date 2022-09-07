#include<iostream>
using namespace std;

int main()
{
	char str4[30],str5[30];
	cout<<"\nEnter another 2 string = ";
	cin.getline(str4,30);
	cin.getline(str5,30);
	cout<<endl<<strstr(str4,str5)<<endl;
}
