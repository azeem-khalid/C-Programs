#include<cstring>
#include<iomanip>
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<deque>
#include<set>
using namespace std;
int main()
{
	int sum=0;
	int month;
	cout<<"Enter How many month you do saving : "<<endl;
	cin>>month;
	int Array[month][month];
	cout<<"Enter the amount you saved : "<<endl;
	for(int i=0;i<month;i++)
	{
		cout<<"Month:  "<<i+1<<"  ";
		for(int j=0;j<1;j++)
		{
			cin>>Array[i][j];
		}
	}
	
	for(int i=0;i<month;i++)
	{
		for(int j=0;j<1;j++)
		{
			sum=sum+Array[i][j];
		}
	}
	system("cls");
	cout<<"Month\tAmount Saved "<<endl;
	for(int i=0;i<month;i++)
	{
		for(int j=0;j<1;j++)
		{
			cout<<i+1<<"\t"<<Array[i][j]<<endl;
		}
	}
	cout<<"Total Saving : "<<sum<<endl;
	
	
}
