#include<bits/stdc++.h>

using namespace std;

int coin;
int w;

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void coinChange(int coin,int w)
{
	int a[coin+1][w+1];
	for(int i=0;i<=coin;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0||j==0)
				a[i][j]=0;
			else if(i==1)
				a[i][j]=j;
			else if(i>j)
				a[i][j]=a[i-1][j];
			else
				a[i][j]=min(a[i-1][j],1+a[i][j-i]);
		cout<<a[i][j]<<" ";
		}
	cout<<endl;
	}
	cout<<a[coin][w];
	
}

int main()
{
    int coin,w;
    cout<<"enter number of coins: ";
    cin>>coin;
    cout<<"enter the weight: ";
    cin>>w;
    coinChange(coin,w);
    return 0;
}
