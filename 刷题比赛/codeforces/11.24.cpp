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
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
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
int main ()
{
	ll n,k;
	cin>>n>>k;
    ll tmp1 = 2*n;
    ll tmp2 = 5*n;
    ll tmp3 = 8*n;
    ll _ = ceil((double)tmp1/k);
    ll __ = ceil((double)tmp2/k);
    ll ___ = ceil((double)tmp3/k);
    ll ans = _ + __ + ___;
    cout<<ans<<endl;  
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		int _ = (r-l+1);
		if(l == r)
		{
			if(l % 2 == 0) cout<<l<<endl;
			else cout<<0-r<<endl;
			continue;
		}
		if(_ % 2 == 0)
		{
           if(l % 2 == 0) cout<<0-_/2<<endl;
           else cout<<_/2<<endl;
		}
		else 
		{
            int tmp = _-1;
            int ans = 0;
            if(l % 2 == 0) tmp = 0-tmp/2;
            else tmp = tmp/2;
            if(r % 2 == 0) cout<<tmp+r<<endl;
            else cout<<tmp-r<<endl;
		}
	}
	return 0;}

*/
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	for(int i= 1;i<=t;i++)
	{
		int n,m;
		int x1,x2,x3,x4;
		int y1,y2,y3,y4;
		cin>>n>>m;
		cin>>x1>>x2>>x3>>x4;
		cin>>y1>>y2>>y3>>y4;
		int w = m * n / 2;
		int b = m * n / 2;
		int tmp1 = abs(x1-x3+1)*abs(x2-x4+1);
        w += tmp1 / 2;
        b -= tmp1 / 2;
        int tmp2 = abs(y1-y3+1)*(y2-y4+1);

	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
#define x first 
#define y second
using namespace std;
typedef long long ll;
pair<ll,ll>calc(int dd,ll n,ll m)
{
  if(m % 2 == 0) return make_pair(n*m/2,n*m/2);
  if(n% 2 == 0) return make_pair(n*m/2,n*m/2);
  ll w = n *m/2+(dd == 0);
  ll b = n * m-w;
  return make_pair(b,w);
}
struct Point{
  ll x,y;
  Point(ll _x = 0,ll _y = 0)
  {
    x = _x;
    y = _y;
  }
}p[4];
int check(Point a,Point b,Point c,Point d)
{
  ll dx = abs(a.x+b.x-c.x-d.x),dy = abs(a.y+b.y-c.y-d.y);
  ll x = abs(a.x-b.x)+abs(c.x-d.x),y = abs(a.y-b.y)+abs(c.y-d.y);
  if(dx <= x && dy <= y) return 1;
  return 0 ;
}
int tmp;
pair<ll,ll> get()
{
  if(p[0].x > p[1].x) swap(p[0],p[1]);
  if(p[2].x > p[3].x) swap(p[2],p[3]);
  ll x1 = max(p[0].x,p[2].x),x2 = min(p[1].x,p[3].x);
  ll x = x2 - x1;
  if(p[0].y > p[1].y) swap(p[0],p[1]);
  if(p[2].y > p[3].y) swap(p[2],p[3]);
  ll y1 = max(p[0].y,p[2].y),y2 = min(p[1].y,p[3].y);
  ll y = y2-y1;
  tmp = (x1+y1)%2;
  return make_pair(x+1,y+1);   
}
void init(ll a,ll b,int i)
{
  p[i] = {a,b};
}
int main ()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    ll x1,x2,y1,y2;
    ll x3,x4,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    init(x1,y1,0);
    init(x2,y2,1);
    init(x3,y3,2);
    init(x4,y4,3);
    if(check(p[0],p[1],p[2],p[3]))
    {
      auto  r = calc(0,n,m);
      auto  wh = calc((x1+y1)%2,abs(x1-x2)+1,abs(y1-y2)+1);
      auto bl = calc((x3+y3)%2,abs(x3-x4)+1,abs(y3-y4)+1);
      auto res = get();
      auto bb = calc(tmp,res.x,res.y);
      r.x+=bl.y;
      r.y-=bl.y;
      r.y+=wh.x;
      r.x-=wh.x;
      r.x+=bb.x;
      r.y-=bb.x;
      cout<<r.y<<" "<<r.x<<endl;
    }
    else 
    {
            auto r=calc(0,n,m);
			auto wh=calc((x1+y1)%2,abs(x1-x2)+1,abs(y1-y2)+1);
			auto bl=calc((x3+y3)%2,abs(x3-x4)+1,abs(y3-y4)+1);
			r.x+=bl.y;
			r.y-=bl.y;
			r.y+=wh.x;
			r.x-=wh.x;
			cout<<r.y<<' '<<r.x<<endl;
    }
  }
  return 0 ;
}