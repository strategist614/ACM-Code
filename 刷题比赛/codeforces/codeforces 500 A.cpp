/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main ()
{
	int n,t;
	cin>>n>>t;
    for(int i =1;i<=n-1;i++) cin>>a[i];
    int to = 0;
    for(int i =1;i<=n-1;)
    {
    	to = i+a[i];
        i = to;
        if(to == t) {
        	cout<<"YES"<<endl;
        	return 0;
        }
    }
    cout<<"NO"<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int fa[N];
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)] = find(y);
}
int main ()
{
    int n,t;
    cin>>n>>t;
    for(int i =1;i<=n-1;i++) cin>>a[i];
    for(int i =1;i<=n-1;i++) fa[i] = i;
    for(int i = 1;i<=n-1;)
    {
        int x = i;
        int y = i+a[i];
        i = y;
        if(find(x) != find(y))
        	merge(x,y);
    }
    if(find(1)==find(t)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int n,t;
int flag = 0;
int dfs(int now)
{
    if(now > n-1) 
    {
        if(flag) return 1;
        else return 0;
    }
    int y = now+a[now];
    if(y == t) flag = 1;
    dfs(y);
}
int main ()
{
    cin>>n>>t;
    for(int i =1;i<=n-1;i++) cin>>a[i];
    if(dfs(1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0 ;
}