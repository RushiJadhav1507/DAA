#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, i, a[1500] = {0};
	cout<<"Enter number of cabs:";
	cin >> n;
	cout<<"Enter start time and end time for cabs there should be space in between them:";
	for(i = 0; i < n; i++)
	{
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;
		a[h1 * 60 + m1]++;
		a[h2 * 60 + m2 + 1]--;
	}
	int MAX = 0;
	for(i = 1; i < 1500; i++)
	{
		a[i] += a[i - 1];
		MAX = max(MAX, a[i]);
	}
	cout<<"Minimum Number of cabs are:"<<MAX;
}


/*
Enter number of cabs:6
Enter start time and end time for cabs there should be space in between them:1 0 2 0
16 0 21 30
9 30 13 0
21 30 22 30
21 30 22 30
12 0 12 30
Minimum Number of cabs are:3
*/
