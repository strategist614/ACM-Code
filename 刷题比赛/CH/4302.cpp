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
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

const int N = 5e5+5;

ll a[N],b[N],c[N];

int n,m;

struct segment_tree
{
	int l;
	int r;
	ll ans;
}tree[N*4];

void build(int rt,int l,int r)
{
   tree[rt].l = l;
   tree[rt].r = r;
   if(l == r)
   {
      tree[rt].ans = b[l];
      return ; 
   }
   int mid = (l+r)>>1;
   build(rt<<1,l,mid);
   build(rt<<1|1,mid+1,r);    
   tree[rt].ans = gcd(tree[rt<<1].ans,tree[rt<<1|1].ans);
}  
  void update(int rt,int x,ll val)
  {
  	int l = tree[rt].l;
  	int r = tree[rt].r;
  	if(l == r)
  	{
  		tree[rt].ans += val;
  		return ;
  	}
  	int mid = (l+r)>>1;
  	if(x <= mid) update(rt<<1,x,val);
  	else update(rt<<1|1,x,val); 
    tree[rt].ans = gcd(tree[rt<<1].ans,tree[rt<<1|1].ans);
  } 
   
  ll ask(int rt,int L,int R)
  {
  	  int l = tree[rt].l;
  	  int r = tree[rt].r;
      if(L <= l && r <= R) return tree[rt].ans;
      int mid = (l+r)>>1;
      ll ans = 0;
      if(L <= mid) ans = gcd(ans,ask(rt<<1,L,R));
      if(R > mid) ans = gcd(ans,ask(rt<<1|1,L,R));
      return abs(ans);
  }
  
  void add(int x,ll y)
  {
    for(;x<=n;x+=x&-x)c[x]+=y;
  }

  ll query(int x)
  {
    ll ans = 0;
    for(;x;x-=x&-x) ans += c[x];
    return ans ;
  }

int main ()
{
    read(n);
    read(m);
    memset(c,0,sizeof(c));
    for(int i = 1;i<=n;i++)  read(a[i]);
    b[0] = 0;
    for(int i = 1;i <= n;i++)  b[i] = a[i]-a[i-1];
    build(1,1,n);
    while(m--) 
    {
    	char op[20];
    	cin>>op;
    	if(op[0] == 'C')
    	{ 
    	   int l,r;
    	   ll d;
    	   read(l);
         read(r);
         read(d);
    	   update(1,l,d);
    	   add(l,d);
    	   if(r+1 <= n)
    	   {
    	   	  update(1,r+1,-d);
    	   	  add(r+1,-d);
    	   }
    	}
    	else 
    	{
           int l,r;
           read(l);
           read(r);
           cout<<gcd(a[l]+query(l),ask(1,l+1,r))<<endl;
    	}
    } 
    return 0 ;
}