#include<bits/stdc++.h>

using namespace std;

int partition(int arr[],int low,int high)
{
    int random = low + rand() % (high - low);
    swap(arr[random], arr[low]);
    int pivot = arr[low];
    int i=low+1;
    int j=high-1;
    while(i<j)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
            int temp=arr[j];
            arr[j]=pivot;
            arr[low]=temp;
    return j;


}


void Quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
    int p = partition(arr,low,high);

    Quicksort(arr,low,p);
    Quicksort(arr,p+1,high);
    }

}
int main()
{
    int arr[10]={5,7,9,3,1,2,6,8,4};
    Quicksort(arr,0,9);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i];
    }

}