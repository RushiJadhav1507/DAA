#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int func(int index,int wt_left,vector<int> profit,vector<int> weight)
{
    if(wt_left<0) return 0;
    if(index <0) return 0;
    if(dp[index][wt_left]!=-1) return dp[index][wt_left];

    int ans = func(index-1,wt_left,profit,weight);

    if(wt_left - weight[index] >=0)
        ans = max(ans,func(index-1,wt_left-weight[index],profit,weight)+profit[index]);
    dp[index][wt_left]=ans;
    return ans;

}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cout<<"Enter no of Objects :";
    cin>>n;
    cout<<"Enter total Weight:";
    cin>>w;
    cout<<endl;

    vector<int> profit;
    vector<int> weight;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        profit.push_back(temp);
        cin>>temp;
        weight.push_back(temp);
    }

    cout<<func(n-1,w,profit,weight);

}
