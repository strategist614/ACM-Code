/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 5e5+5;
int a[N];
priority_queue<int,vector<int>,greater<int> > q;
int main ()
{
	int n,m,d,l;
	cin>>n>>m>>d>>l;
	int pos = 0;
	for(int i= 1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    for(int i= 1;i<=n;i++) 
    {
    	if(a[i] < l) pos = i;
    }
    int ans = 0;
    for(int i= pos+1;i<=pos+m;i++)
    {
        q.push(1);
    	ans++;
    }
    for(int i= pos+m+1;i<=n;i++)
    {
    	auto x = q.top();
        if(a[i] - x*d >= l) 
        {
        	q.pop();
            x++;
            q.push(x);
            ans++;
        }
    }
    cout<<ans<<endl;
 	return 0 ;
}