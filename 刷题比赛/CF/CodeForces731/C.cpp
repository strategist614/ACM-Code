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
const int N = 2e5+5;
int fa[N];
int c[N];
int get(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y)
{
	fa[get(x)] = get(y);
}
map<int,int> mp;
std::vector<int> v[N];
int main ()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i =1;i <= n;i++) read(c[i]);
	for(int i =1;i <= n;i++) fa[i] = i;
	while(m--)
	{
		int l,r;
        read(l);
        read(r);
        merge(l,r);
	}
    int ans = 0;
    int mx = 0;
    for(int i = 1;i <= n;i++){
    	int ans = get(i);
    	v[ans].push_back(i);
    	mx = max(mx,ans);
    }
    for(int i = 1;i <= mx;i++)
    {
    	mp.clear();
    	int maxx = 0 ;
    	for(int j = 0;j < v[i].size();j++)
    	{ 
            mp[c[v[i][j]]]++;
            maxx = max(maxx,mp[c[v[i][j]]]);
    	}
    	ans += v[i].size() - maxx;
    }
    cout<<ans<<endl;
	return 0 ;
}