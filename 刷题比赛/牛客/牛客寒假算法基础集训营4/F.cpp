#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
struct node
{
	int x;
	int y;
}f[N*2];
std::vector<int> vec[N];
queue<int> q;
int in[N];
int n,m;
bool check(int x)
{
    for(int i=1;i<=n;i++)
        vec[i].clear(),in[i]=0;
    for(int i=1;i<=x;i++)
    {
        vec[f[i].x].push_back(f[i].y);
        in[f[i].y]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int i=0;i<vec[x].size();i++)
        {
            in[vec[x][i]]--;
            if(!in[vec[x][i]]) q.push(vec[x][i]);
        }
    }
    for(int i=1;i<=n;i++)
        if(in[i]) return 1;
    return 0;
}
int main ()
{
	cin>>n>>m;
    for(int i= 1;i<=m;i++) cin>>f[i].x>>f[i].y;
	int l = 1;
	int r = m+1;
	int ans = 0;
	while(l < r)
	{
       int mid = (l+r) >> 1;
       if(check(mid)) r = mid;
       else l = mid +1;
	}
	for(int i = 1;i < l;i++) cout<<"Yes"<<endl;
	for(int i = l;i <=m;i++) cout<<"No"<<endl; 
	return 0 ;
}