/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
std::vector<int> v[N];
int vis[N];
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i= 1;i<=m;i++) 
	{
		int x,y;
		cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
	}
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
	q.push(1);
	while(q.size())
	{
		int t = q.top();
		q.pop();
		vis[t] = 1;
		cout<<t<<" ";
		for(auto k:v[t])
		{
			if(!vis[k])
			{
				q.push(k);
				vis[k] = 1;
			}
		}
	}
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using  namespace std;
const int maxn = 1e5+5;
std::vector<int> v[maxn];
int n,m;
int vis[maxn];
int main()
{
        cin>>n>>m;
        for (int i = 1, a, b; i <= m; i++) {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);    
         }
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        q.push(1);
        while(!q.empty())
        {
            int t = q.top();
            q.pop();
            vis[t] = 1; 
            cout<<t<<" ";
            for(auto k:v[t])
            {
                if(!vis[k])
                {
                    q.push(k);
                    vis[k] = 1;
                }
            }
        }
        return 0;
}
*/
