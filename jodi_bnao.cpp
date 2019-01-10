#include<bits/stdc++.h>

using namespace std;

int main()
{

	cout<<"enter number of men";
	int n;
	cin>>n;

	int man_pref[n][n],woman_pref[n][n];
	int priority_for_man[n][n];
	int man_ispaired[n],woman_ispaired[n];
	int no_of_prop[n];



	int i,j;
	cout<<"enter men preference list\n";

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>man_pref[i][j];

	}
	cout<<"enter women preference list"<<"\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>woman_pref[i][j];

	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			priority_for_man[i][woman_pref[i][j]] = j;
		}
	}


	for(i=0;i<n;i++)
	{
		man_ispaired[i] = -1;
		woman_ispaired[i] = -1;
		no_of_prop[i]=0;

	}

	queue<int>q;

	for(i=0;i<n;i++)
		q.push(i);

	while(!q.empty())
	{
		int m = q.front();
		q.pop();

		int w = man_pref[m][no_of_prop[m]];
		no_of_prop[m]++;


		if(woman_ispaired[w] == -1)
		{
			man_ispaired[m]=w;
			woman_ispaired[w]=m;
		}
		else if(priority_for_man[w][m]  < priority_for_man[w][woman_ispaired[w]])
		{
			man_ispaired[m]=w;
			q.push(woman_ispaired[w]);
			woman_ispaired[w]=m;

		}
		else
			q.push(m);



	}

	for(i=0;i<n;i++)
	{
		cout<<i<<" "<<man_ispaired[i]<<"\n";
	}




}