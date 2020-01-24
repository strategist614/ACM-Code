/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
struct node
{
	int x;
	int y;
	int ans;
}a[N],b[N];
bool cmp(node a,node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int cnt = 0;
int temp[N];
void CDQ(int l,int r)
{
	if(l < r)
	{
    int mid = (l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
    int i = l;
    int j = mid+1;
    for(int k = l;k<=r;k++)
    {
    	if(j > r || (a[i].y <= a[j].y && i <= mid)) {
    		b[k] = a[i++];b[k].ans += r-j+1;
    	}
    	else {
    		b[k] = a[j++];
    	}
    }
    for(int k = l;k<=r;k++) a[k] = b[k];
   }
}
int main ()
{
    cin>>n;
    for(int i= 1;i<=n;i++) {cin>>a[i].x>>a[i].y;a[i].ans = 1;}
    sort(a+1,a+n+1,cmp);
    CDQ(1,n);
    int ans = 0;
    for(int i =1;i <= n;i++)
    	if(a[i].ans > 1) ans++;
    cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node 
{
	int x;
	int y;
}a[N];
bool cmp(node a,node b)
{
	if(a.x == b.x)return a.y<b.y;
	return a.x < b.x;
}
int w[N];
int c[N];
struct treearray
{
	void add(int x,int y)
	{
		for(;x<=N;x+=x&-x) c[x] += y;
	}
    int ask(int x)
    {
    	int ans = 0;
    	for(;x;x-=x&-x) ans += c[x];
    	return ans;
    }
}ta;
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
    	cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++) w[i] = a[i].y;
    sort(w+1,w+n+1);
    int t = unique(w+1,w+n+1)-(w+1);
    for(int i= 1;i<=n;i++)
      a[i].y = lower_bound(w+1,w+n+1,a[i].y)-w;
    sort(a+1,a+n+1,cmp);
    int ans = 0;
    for(int i = n;i>=1;i--)
    {
    	int d = ta.ask(a[i].y);
    	if(n-d-i) ans++;
    	ta.add(a[i].y,1);
    }
    cout<<ans<<endl;
	return 0;
}