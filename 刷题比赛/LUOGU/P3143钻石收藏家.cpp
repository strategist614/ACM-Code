#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
const int N = 5e4+5;

int n,a[N],l[N],r[N],k;

int main ()
{
    read(n);
    read(k);
    int ans = 0;
    for(int i =1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    l[1] = 1;
    for(int i =2;i <= n;i++)
    {
    	int j = 1;
    	while(a[i]-a[j] > k)
    	{
    		j++;
    	}
    	l[i] = max(l[i-1],i-j+1);
    } 
    r[n] = 1;
    for(int i = n-1;i >= 1;i--)
    {
    	int j= n;
    	while(a[j]-a[i] > k)
    	{
    		j--;
    	}
    	r[i] = max(r[i+1],j-i+1);
    }
    for(int i= 1;i<=n-1;i++)
    {
    	ans = max(ans,l[i]+r[i+1]);
    }
    cout<<ans<<endl;
	return 0 ;
}