#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node 
{
	int l;
	int r;
	int id;
}a[N];
struct tree
{
	int l;
	int r;
	int id;
}b[N];
int num[N],ans[N];
bool cmp1(node a,node b)
{
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
bool cmp2(tree a,tree b)
{
	if(a.l == b.l) return a.r < b.r ;
	return a.l < b.l;
}
set<pair<int,int>> s;
int tot = 1;
int main ()
{
	int n,m;
	cin>>n;
	for(int i= 1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r;
		a[i].id = i;
	}
	cin>>m;
	for(int i = 1;i<=m;i++)
	{
		cin>>b[i].l>>b[i].r>>num[i];
		b[i].id = i;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1,cmp2);
	s.insert(make_pair(1e9+5,0));
	for(int i= 1;i<=n;i++)
	{
       while(tot <= m && b[tot].l <= a[i].l)
       {
       	  s.insert(make_pair(b[tot].r,b[tot].id));
          tot++;
       }
       auto tmp = *(s.lower_bound(make_pair(a[i].r,0)));
       if(tmp.first == 1e9+5)
       {
       	  cout<<"NO"<<endl;
       	  return 0 ;
       }
       num[tmp.second]--;
       ans[a[i].id] = tmp.second;
       if(num[tmp.second] == 0) s.erase(tmp);
	}
	cout<<"YES"<<endl;
	for(int i= 1;i<=n;i++) cout<<ans[i]<<" ";
	return 0 ;
}