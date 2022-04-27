#include<bits/stdc++.h>

using namespace std;

class activity
{
	public:
	int start,finish;
};

bool sortFt(activity a, activity b)
{
	return (a.finish<b.finish);
}

void scheduleActivity(activity a[],int n)
{
	sort(a,a+n,sortFt);
	cout<<"Included activitites are:";
	int i=0; 
	cout<<"("<<a[i].start<<","<<a[i].finish<<")";
	for(int j=0;j<n;j++)
	{
		if(a[j].start>=a[i].finish)
		{
		    cout<<"("<<a[j].start<<","<<a[j].finish<<")";
			i=j;
		}
	}
}
int main()
{
    activity a[]={{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(a)/sizeof(a[0]);
    scheduleActivity(a,n);
    return 0;
}