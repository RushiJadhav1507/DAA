#include<iostream>
using namespace std;
void primMST()
{
	int v;
	cout<<"Enter total no. of vertices:";
	cin>>v;
	int graph[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i<j)
			{
				cout<<"Enter edge weight "<<i<<"-"<<j<<":";
				cin>>graph[i][j];
			}
			else if(i==j)
			{
				graph[i][j]=0;
			}
			else
			{
				graph[i][j]=graph[j][i];
			}
		}
	}
	cout<<"Adjacency Matrix:\n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
	int wg;
	int no_edge=0;
	int visited[v]={false};
	visited[0]=true;
	int x,y;
	cout<<"Edge:"<<" : "<<"Weight"<<endl;
	while(no_edge < v-1)
	{
		int min=999;  //dummy value
		x=0;         //to avoid garbage value
		y=0;
		for(int i=0;i<v;i++)
		{
			if(visited[i]==true)
			{
				for(int j=0;j<v;j++)
				{
					if(visited[j]==false && graph[i][j]!=0) 
					{
						if(min>graph[i][j])
						{
							min=graph[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		cout<<x<<" - "<<y<<" : "<<graph[x][y];
		wg=wg+graph[x][y];
		cout<<endl;
		visited[y]=true;
		no_edge++;
	}
	
	cout<<"\ntotal weight:"<<wg;
}
int main()
{
	primMST();
	return 0;
}
