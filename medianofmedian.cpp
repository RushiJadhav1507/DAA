#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
#include<chrono>
using namespace std::chrono;
using namespace std;
class Quicksort{
	public:
		int n;
		int A[];
		public:
		int kthSmallest(int A[], int l, int r, int k);
		void quickSort(int A[], int l, int h);
		void quickSort_normal(int A[], int l, int h);
		int findMedian(int A[], int n);
		void printArray(int A[], int size);
		int partition(int A[], int l, int r, int x);
		void swap(int *a, int *b);
};
void Quicksort:: quickSort(int A[], int l, int h)
{
	if (l < h)
	{
		int n = h-l+1;
		int med = kthSmallest(A, l, h, n/2);
		int p = partition(A, l, h, med);
		quickSort(A, l, p - 1);
		quickSort(A, p + 1, h);
 	}
}
void Quicksort:: quickSort_normal(int A[], int l, int h)
{
	if (l < h)
	{
		int n = h-l+1;
		int k= (sizeof(A)/2)+1;
		int med =A[k];
		int p = partition(A, l, h, med);
		quickSort_normal(A, l, p - 1);
		quickSort_normal(A, p + 1, h);
	}
}
int Quicksort:: findMedian(int A[], int n)
{
	sort(A, A+n); // Sort the array
	return A[n/2]; // Return middle element
}
int Quicksort:: kthSmallest(int A[], int l, int r, int k)
{ 
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1;
		int i;
		int median[(n+4)/5];
		for (i=0; i<n/5; i++)
		median[i] = findMedian(A+l+i*5, 5);
		if (i*5 < n)
		{
			median[i] = findMedian(A+l+i*5, n%5);
			i++;
		}
		int medOfMed = (i == 1)? median[i-1]:
		kthSmallest(median, 0, i-1, i/2);
		int pos = partition(A, l, r, medOfMed);
		if (pos-l == k-1)
			return A[pos];
		if (pos-l > k-1)
			return kthSmallest(A, l, pos-1, k);
		return kthSmallest(A, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}
void Quicksort:: swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
int Quicksort::partition(int A[], int l, int r, int x)
{
 int i;
 for (i=l; i<r; i++)
 if (A[i] == x)
 break;
 swap(&A[i], &A[r]);
 i = l;
 for (int j = l; j <= r - 1; j++)
 {
 if (A[j] <= x)
 {
 swap(&A[i], &A[j]);
 i++;
 }
 }
 swap(&A[i], &A[r]);
 return i;
}
void Quicksort::printArray(int A[], int size)
{
 int i;
 for (i=0; i < size; i++)
 cout << A[i] << " ";
 cout << endl;
}
int main()
{ 
 Quicksort qc;
 int n;
 cout<<"Enter the number of elements: "<<endl;
 cin>>n;
 int A[n];
 for(int i=0;i<n;i++){
 A[i]=rand()%n+1;
 }
 // cout<<"The array elements: "<<endl;
 // for(int i=0;i<n;i++){
 // cout<<A[i]<<" ";
 // }
 cout<<endl;
 
 //Quick Sort Using MOM
 auto before_nqc = high_resolution_clock::now();
 qc.quickSort(A, 0, n-1);
 auto after_nqc = high_resolution_clock::now();
 auto time1 = duration_cast<microseconds>(after_nqc-before_nqc);
 int time_for_nqc = time1.count();
 cout << "\nSorted array is\n";
 qc.printArray(A, n);
 cout << "\nTime taken By Normal Quick Sort: "<<time_for_nqc<<" nanoseconds";
 
 // Normal Quick Sort
 auto before_norqc = high_resolution_clock::now();
 qc.quickSort_normal(A, 0, n-1);
 auto after_norqc = high_resolution_clock::now();
 auto time2 = duration_cast<microseconds>(after_norqc-before_norqc);
 int time_for_norqc = time2.count();
 cout << "\nSorted array is\n";
 qc.printArray(A, n);
 cout << "\nTime taken By Using MOM: "<<time_for_norqc<<" nanoseconds";
 return 0;
}
