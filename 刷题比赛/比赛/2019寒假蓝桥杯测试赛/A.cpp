/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct node 
{
	int nian;
	int yue;
	int ri;
	bool operator < (node b) const 
    {
        if (nian == b.nian) 
        {
            if (yue == b.yue) {
                return ri < b.ri;
            }
            return yue < b.yue;
        }
        return nian < b.nian;
    }
}a[7];

int judge(int nian)
{
	if(nian % 4 == 0 || (nian % 400 == 0 && nian % 100 != 0)) return 1;
	else return 0;
}

int solve(node a)
{
	int x[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int nian = a.nian;
	int yue = a.yue;
	int ri = a.ri;
    if(nian > 2059 || nian < 1960) return 0;
    if(yue < 1 || yue > 12) return 0;
    if(judge(nian))
     x[2] = 29;
    else x[2] = 28;
    if(ri < 1 || ri > x[yue])
    	return 0;
    return 1;
}

void out(node a)
{
	printf("%02d-%02d-%02d",a.nian,a.yue,a.ri);
}
set<node> s;
set<node>::iterator it;
int main ()
{
	node tmp;
    char x,y;
    scanf("%d%c%d%c%d",&tmp.nian,&x,&tmp.yue,&y,&tmp.ri);
    a[1].nian = tmp.nian+1900;
    a[1].yue = tmp.yue;
    a[1].ri = tmp.ri;
    a[2].nian = tmp.nian+2000;
    a[2].yue = tmp.yue;
    a[2].ri = tmp.ri;
    a[3].nian = tmp.ri+1900;
    a[3].yue = tmp.nian;
    a[3].ri = tmp.yue;
    a[4].nian = tmp.ri+2000;
    a[4].yue = tmp.nian;
    a[4].ri = tmp.yue;
    a[5].nian = tmp.ri+1900;
    a[5].yue = tmp.yue;
    a[5].ri = tmp.nian;
    a[6].nian = tmp.ri+2000;
    a[6].yue = tmp.yue;
    a[6].ri = tmp.nian;
    sort(a+1,a+6+1);
    for(int i= 1;i<=6;i++)
    {
       if(solve(a[i]))
       {
       	  s.insert(a[i]);
       }
    }
    for(it = s.begin();it != s.end();it++)
    {
    	out(*it);
    	cout<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 0;
int vis[10][10];
void dfs(int x,int y)
{
	if(x == 0 || x == 6 || y == 0 || y == 6)
	{
		ans++;
		return ;
	}
	for(int i= 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!vis[nx][ny])
		{
			int dnx = 6-nx;
			int dny = 6-ny;
			vis[nx][ny] = vis[dnx][dny] = 1;
			dfs(nx,ny);
			vis[nx][ny] = vis[dnx][dny] = 0;
		}
	}
}
int main ()
{
	vis[3][3] = 1;
    dfs(3,3);
    cout<<ans/4<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N];
ll sum[N];
int vis[N];
int main ()
{
    int n,k;
    cin>>n>>k;
    for(int i= 1;i<=n;i++)
    	cin>>a[i];
    for(int i= 1;i<=n;i++)
       sum[i] = (sum[i-1]+a[i])%k;
    int ans = 0;
    for(int i= 1;i<=n;i++)
    {
        ans += vis[sum[i]]++;
    }
    ans += vis[0];
    cout<<ans<<endl;
	return 0 ;
}