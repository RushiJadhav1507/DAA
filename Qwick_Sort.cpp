#include <iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;
// Swap two elements - Utility function  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partition the array 
        int pivot = partition(arr, low, high); 
   
        //sort the sub arrays independently 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void displayArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"\t"; 
      
} 
   
int main() 
{ 
    int n=1000,arr[n];
    int choice=0;
    for(int i=0; i<n; i++)          //array of random numbers
    {
            arr[i]= rand()%130000+ 1;
    } 
    cout<<"Input array"<<endl;
    displayArray(arr,n);
    cout<<endl;

    //Clock Started
    auto start1 = high_resolution_clock::now();
    quickSort(arr, 0, n-1); 
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast < nanoseconds > (stop1 - start1);  //clock stop
    cout << "\n\nTime taken By Qwick Sort: " << (duration1.count()) << " nanoseconds" << endl;
    cout<<"Array sorted with quick sort"<<endl; 
    displayArray(arr,n); 
    return 0; 
}