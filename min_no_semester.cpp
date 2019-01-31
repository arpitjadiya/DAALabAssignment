#include<bits/stdc++.h>

using namespace std;
vector< vector<int> >out(100000);
vector< vector<int> >in(100000);
int sem[100000]={0};
int counte[100000]={0};
queue<int>q;
int min_sem=1;
vector< vector<int> >vec(100000);
int main()
{
	cout<<"enter number of subjects\n";
	int n;
	cin>>n;
	cout<<"enter number of dependencies\n";
	int m;
	cin>>m;
	
	int i;
	int a,b;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		out[a].push_back(b);
		in[b].push_back(a);

	}

	for(i=1;i<=n;i++)
	{
		counte[i]=in[i].size();
		if(counte[i]==0)
		{
			q.push(i);
			sem[i] = 1;
			vec[sem[i]].push_back(i);

		}

	}

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(i=0;i<out[u].size();i++)
		{
			int v = out[u][i];
			counte[v]--;

			if(counte[v]==0)
			{
				sem[v] = sem[u]+1;
				vec[sem[v]].push_back(v);
				if(sem[v]>min_sem)
					min_sem=sem[v];
				q.push(v);

			}
		}
	}

	cout<<"\n minimum no. of sem  is  "<<min_sem;
	cout<<"courses to be done in  \n";

	i=1;
	while(vec[i].size()!=0)
	{
		cout<<"sem "<<i<<"\n";
		for(int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
		cout<<"\n";

		i++;
	}






}