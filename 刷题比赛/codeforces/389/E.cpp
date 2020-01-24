#include<bits/stdc++.h>
using namespace std;
vector<int> v[105];
priority_queue<int> q;
int main()
{
	int n;
	int sumc = 0;
	int sumj = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		int a;
		cin>>a;
        for(int j = 1;j <= a;j++)
           {
           	  int tmp;
           	  cin>>tmp;
           	  v[i].push_back(tmp);
           }
	}
    for(int i = 1;i<=n;i++)
    {
    	int size = v[i].size();
    	if(size % 2== 0)
    	{
            for(int j = 0;j<size/2;j++)
            	sumc += v[i][j];
            for(int j = size/2;j<size;j++)
            	sumj += v[i][j];
    	}
    	else
    	{
           for(int j = 0;j<size/2;j++)
           	   sumc += v[i][j];
           for(int j = size/2 + 1;j<size;j++)
           	   sumj += v[i][j];
           	q.push(v[i][size/2]);
    	}
    } 
   while(q.size())
    {
        int x= q.top();
        sumc += x;
        q.pop();
        if(q.empty()) break;
        int y = q.top();
        sumj += y;
        q.pop();
    }
    cout<<sumc<<" "<<sumj<<endl;
	return 0 ;
}