#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4+4;
struct node
{
	int x;
	int y;
	int d;
}a[N];
ll c[N],sum[N];
bool cmp(node a,node b)
{
    if(a.d != b.d) return a.d < b.d;
    if(a.d <= 0) return a.x < b.x;
    return a.y > b.y;
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
       int n;
       cin>>n;
       for(int i= 1;i<=n;i++) {
       	cin>>a[i].x>>a[i].y;
        if(a[i].x > a[i].y) a[i].d = 1;
        else if(a[i].x < a[i].y) a[i].d = -1;
        else a[i].d = 0;
       }
       sort(a+1,a+n+1,cmp);
       ll ans = 0;
       for(int i =1;i<=n;i++)
       { 
         ans += a[i].x;
         c[i] = max(c[i-1],ans) + a[i].y;
       }
       cout<<c[n]<<endl;
	}
	return 0 ;
}