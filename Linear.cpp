#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void linearSearch(int a[],int key,int n)
{
	int flag=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		    { 
		       flag=1;
		        break;
		    }
	}
	if(flag!=1)
		cout<<"Element is not found in the array";
	else
	    cout<<"element is found at "<<i+1;
}

int main()
{
    int n,a[1000],key;
    cout<<"Enter the size of array: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"enter the key: ";
    cin>>key;
    linearSearch(a,key,n);
    return 0;
}
