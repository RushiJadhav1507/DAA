#include<bits/stdc++.h>

using namespace std;


int binarySearch(int a[],int key,int n)
{
	int low=0;
	int high=n-1;
	int mid;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
			return mid;

		else if(a[mid]<high)
			low=mid+1;
		else
			high=mid-1;
	}

	return 1;
}

int main()
{
    int index,a[1000],key,n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the key: ";
    cin>>key;
    index=binarySearch(a,key,n);
    cout<<"index is: "<<index+1;
    return 0;
}