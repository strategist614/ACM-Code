/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
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
const int N = 1e4+5;
struct node
{
	int p;
	int d;
}a[N];
bool cmp(node a,node b)
{
	return a.d < b.d;
}
priority_queue<int,vector<int>,greater<int>> q;
int main ()
{
    int n;
    while(cin>>n){
        for(int i= 1;i<=n;i++)
        	scanf("%d %d",&a[i].p,&a[i].d);
        sort(a+1,a+n+1,cmp);
        for(int i= 1;i<=n;i++)
        {
            if(q.size() == a[i].d && q.top() < a[i].p) 
           	{   
                q.pop();
                q.push(a[i].p);
                continue;
           	}
           	if(q.size() < a[i].d) q.push(a[i].p);
        }
        int ans = 0;
        while(q.size())
        {
        	int _ = q.top();
        	ans += _;
        	q.pop();
        }
        printf("%d\n",ans);
    }	
	return 0 ;
}