#include<bits/stdc++.h>
using namespace std;
int e[11];
struct node
{
	int w;
	int d;
	int c;
}a[20005];
bool cmp(node a,node b)
{
	if(a.w == b.w) return a.d < b.d;
	return a.w > b.w;
}
int main ()
{
	int n,k;
	cin>>n>>k;
	for(int i= 1;i<=10;i++) cin>>e[i];
    for(int i= 1;i<=n;i++) {cin>>a[i].w;a[i].d = i;}
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++)
    {
        a[i].c = (i-1) % 10+1;
        a[i].w += e[a[i].c];
    }
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=k;i++)
    	cout<<a[i].d<<" ";
	return 0 ;
}