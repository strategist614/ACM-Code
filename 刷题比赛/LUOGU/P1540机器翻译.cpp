#include<bits/stdc++.h>
using namespace std;
int a[1005];
int vis[1005];
queue<int> q;
int main ()
{
	int n,m;
	cin>>m>>n;
	for(int i =1;i<=n;i++) cin>>a[i];
    int ans = 0;
	for(int i= 1;i<=n;i++)
	{
		if(vis[a[i]]) continue;
		else{
			vis[a[i]] = 1;
			if(q.size() <= m-1) {q.push(a[i]);ans++;}
            else {int x = q.front();vis[x] = 0;q.pop();q.push(a[i]);ans++;}
		}
	}
	cout<<ans<<endl;
	return 0 ;
}