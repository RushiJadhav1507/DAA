// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
#include<vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#define SIZE 10000
using namespace std;
using namespace std::chrono;

void Linear(vector<int> a,long long key)
{
	auto start2 = high_resolution_clock::now();
	int flag=0;
	for(long long i=0;i<SIZE;i++)
	{
		if(a[i]==key)
		{
			cout<<"\nElement Found at Location:\t"<<(i+1)<<endl;
			flag++;
			break;
		}
	}
	if(flag==0)
	{
	cout<<"Element Not Found"<<endl;
	}
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken By Linear Search: "
	<< duration2.count() << " microseconds" << endl;

}

void Binary(vector<int> a,long long key)
{
	auto start1 = high_resolution_clock::now();
	long long mid=0;
	long long first=0;
	long long last=SIZE;
	mid=(first+last)/2;
	while((a[mid]!=key)&&(first<last))
	{
		if(a[mid]>key)
		{
		last=mid-1;
		}
		else
		{
		first=mid+1;
		}
		mid=(first+last)/2;
	}
	if(a[mid]==key)
	{
	cout<<"\n\nElement found at location:\t"<<mid+1;
	}
	else
	{
	cout<<"Element Not Found\n";
	}
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken By Binary Search: "
	<< duration1.count() << " microseconds" << endl;

}



long long getRandom(long long x, long long y)
{
    srand(time(NULL));
    return (x + rand() % (y-x+1));
}
void ModifiedBinary(vector<int> a,long long key)
{
	auto start3 = high_resolution_clock::now();
	long long mid=0;
	long long first=0;
	long long last=SIZE;
	mid=getRandom(first,last);
	while((a[mid]!=key)&&(first<last))
	{
		if(a[mid]>key)
		{
		last=mid-1;
		}
		else
		{
		first=mid+1;
		}
		mid=(first+last)/2;
	}
	if(a[mid]==key)
	{
	cout<<"\n\nElement found at location:\t"<<mid+1;
	}
	else
	{
	cout<<"Element Not Found\n";
	}
	auto stop3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(stop3 - start3);
	cout << "\nTime taken By Modified Binary Search: "
	<< duration3.count() << " microseconds" << endl;

}


int main()
{

	vector<int> value(SIZE);
	
	auto n = []() -> int { return rand() % 700000; };
			
	generate(value.begin(), value.end(), n);
	long long key=0;
	sort(value.begin(), value.end());
	for(long long i=0;i<SIZE;i++)
	{
		cout<<value[i]<<"\t";
	}
	cout<<"\nEnter the Element to Search\t";
	cin>>key;

	Binary(value,key);
	Linear(value,key);
	ModifiedBinary(value, key);
  
}



