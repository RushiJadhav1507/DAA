#include<bits/stdc++.h>

using namespace std;

class job
{
	public:
	char jobID;
	int ded;
	int profit;
};

bool profitComp(job a, job b)
{
	return(a.profit>b.profit);
}

void jobScheduling(job a[],int n)
{
	int result[n];
	bool slot[n];
	int profit=0; 
	for(int i=0;i<n;i++)
		slot[i]=false;

	sort(a,a+n,profitComp);

	for(int i=0;i<n;i++)
	{
		for(int j=min(n,a[i].ded)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=i;
				slot[j]=true;
				profit=profit+a[i].profit;
				break;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(slot[i])
			cout<<a[result[i]].jobID<<" ";
	}
	cout<<"Max profit is:"<<profit;
}

int main()
{
    job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    jobScheduling(arr, n);
    return 0;
}
