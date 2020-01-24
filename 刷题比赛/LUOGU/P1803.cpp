#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct  node
{
	int s;
	int e;
}a[N];
bool cmp(node &a,node&b)
{
	return a.e < b.e;
}
int main ()
 {
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d %d",&a[i].s,&a[i].e);
    sort(a+1,a+n+1,cmp);
    long long ans = 0;
    int last = 0;
    for(int i = 1;i <= n;i++)
    {
    	if(a[i].s >= last) {ans++;;last = a[i].e;}
    }
    printf("%lld\n",ans);
	return 0;
}
