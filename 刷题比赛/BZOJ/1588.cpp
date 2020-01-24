/*
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
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
const int N = 50000;
const int inf = 1e9;
int ch[N][2];
int fa[N];
int val[N];
int ans,size,t1,t2,n,rt;
void rotate(int x,int &k)
{
	int y = fa[x];
	int z = fa[y];
    int l,r;
    if(ch[y][0] == x) l = 0;
    else l = 1;
    r = l ^ 1;
    if(y == k) k = x;
    else 
    {
    	if(ch[z][0] == y)
    		ch[z][0] = x;
    	else ch[z][1] = x;
    } 
    fa[x] = z;
    fa[y] = x;
    fa[ch[x][r]] = y;
    ch[y][l] = ch[x][r];
    ch[x][r] = y; 
}
void splay(int x,int &k)
{
	int y,z;
	while(x != k)
	{
		y = fa[x];
		z = fa[y];
		if(y != k)
		{
			if((ch[y][0] == x) ^ (ch[z][0] == y)) rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
}
void insert(int &k,int x,int last)
{
    if(k == 0){
    	size++;
    	k = size;
    	val[k] = x;
    	fa[k] = last;
    	splay(k,rt);
      return ;
    }
    if(x < val[k]) insert(ch[k][0],x,k);
    else insert(ch[k][1],x,k);
}
void getpre(int k,int x)
{
    if(k == 0) return ;
    if(val[k] <= x)
    {
    	t1 = val[k];
    	getpre(ch[k][1],x);
    } 
    else 
       getpre(ch[k][0],x);
}
void getnext(int k,int x)
{
	if(k == 0)return; 
    if(val[k] >= x) 
    {
    	t2 = val[k];
    	getnext(ch[k][0],x);
    }
    else getnext(ch[k][1],x);
}
int main ()
{
    read(n);
    for(int i= 1;i<=n;i++)
    {
    	int x;if(scanf("%d",&x)==EOF)x=0;
    	t1 = -inf;
    	t2 = inf;
    	getpre(rt,x);
    	getnext(rt,x);
    	if(i != 1) ans += min(x-t1,t2-x);
    	else ans += x;
    	insert(rt,x,0);
    }
    out(ans);
    puts("");
	return 0 ;
}	
*/
#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
multiset<int>::iterator it;
int main ()
{
	int n;
	cin>>n;
	int ans = 0 ;
	for(int i= 1;i<=n;i++)
	{

		int x ;
		if(scanf("%d",&x)==EOF) x=0;
		s.insert(x);
        if(i != 1)
        {
           it = s.find(x);
           int b = 1<<30;
           if(it != s.begin()) it--,b = x - (*it),it++;
           it++;
           if(it != s.end()) b = min(b,(*it)- x);
           ans += b;
        }
        else 
        ans += x;
	}
	cout<<ans<<endl;
	return 0 ;
}