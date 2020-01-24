/*
独立思考
*/
/*
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
std::vector<int> v;
void dfs(int dep,int n,int flag)
{
	if(dep > n)return ;
	dfs(dep+1,n,1);
	v.push_back(flag?0:1);
	dfs(dep+1,n,0);
}
int main ()
{
    int n;
    cin>>n;
    dfs(1,n,1);
    for(int i= 0;i<v.size();i++) cout<<v[i]; 	
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
int a[100005];
int main ()
{
	 int b,k;
	 cin>>b>>k;
	 ll ans = 0;
	 for(int i= 1;i<=k;i++)
	 { 
	 	int x;
	 	cin>>x;
        ans += x * powmod(b,k-i); 
	 }
	 if(ans % 2) cout<<"odd"<<endl;
	 else cout<<"even"<<endl; 
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
const int N = 2e5+5;
int a[N];
ll sumodd[N];
ll sumeven[N];
int ao[N];
int ae[N];
int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i];
    int toto = 0,tote = 0;
    for(int i =1;i<=n;i++)	
    {
       if(i % 2) ae[++toto] = a[i];
       else ao[++tote] = a[i];	
    }
    for(int i= 1;i<=toto;i++) sumodd[i] = sumodd[i-1]+ao[i];
    for(int i= 1;i<=tote;i++) sumeven[i] = sumeven[i-1]+ae[i];
    int ans = 0 ;
   // for(int i =1;i<=toto;i++) cout<<sumodd[i]<<endl;
    for(int i= 1;i<=n;i++)
    {
    	    int pose = i / 2;
            int poso = i / 2;
            ll even = sumeven[pose]-sumeven[0] + sumodd[toto] - sumodd[poso];
            ll odd = sumodd[poso]-sumodd[0]+ sumeven[tote]-sumeven[pose];
            cout<<even<<" "<<odd<<endl;
            if(even == odd) ans ++;
    }
   // cout<<ans<<endl;
	return 0 ;
}
*/

/*
独立思考
*/
/*
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
int main ()
{
    int n,v;
    cin>>n>>v;
    if(v + 1 >= n) 
    {
    	cout<<n-1<<endl;
        return 0;
    }	
    int ans = v;
    int tmp = n - v - 1;
    int j = 2;
    for(int i=1;i<=tmp;i++)
    {
    	ans += j;
    	j++; 
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
const int N = 2e5+5;
int a[N];
ll sumodd[N];
ll sumeven[N];
int ao[N];
int ae[N];
int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i];
    int toto = 0,tote = 0;
    for(int i =1;i<=n;i++)	
    {
       if(i % 2) ae[++tote] = a[i];
       else ao[++toto] = a[i];	
    }
    for(int i= 1;i<=toto;i++) sumodd[i] = sumodd[i-1]+ao[i];
    for(int i= 1;i<=tote;i++) sumeven[i] = sumeven[i-1]+ae[i];
    int ans = 0 ;
   // for(int i =1;i<=tote;i++) cout<<sumeven[i]<<endl;
    //ll even = 0,odd = 0;
    for(int i= 1;i<=n;i++)
    { 
    	ll even = 0,odd = 0;
        if(i % 2) 
        {
        	int pos = i / 2;
        	even += sumeven[pos]-sumeven[0];
        	odd += sumodd[pos]-sumodd[0];
            odd += sumeven[tote]-sumeven[(i+1)/2];
            even += sumodd[toto]-sumodd[(i)/2];
        }
        else
        {
           int pos = i / 2;
           even += sumeven[pos]-sumeven[0];
           odd += sumodd[pos-1]-sumodd[0];
           even += sumodd[toto] - sumodd[i/2];
           odd += sumeven[tote]-sumeven[(i+1)/2];
        }
        if(even == odd) ans++;
    }
   
   cout<<ans<<endl;
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
const int N = 5e4+4;
int a[N];
int ans = 0;
int tmp = 0;
std::vector<int> v;
void solve(int n)
{
	v.push_back(n);
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n % i == 0)
		{
			v.push_back(i);
			if(n / i != i) v.push_back(n/i); 
		}
	}
}
const int INF = 0x7fffffff;
int main ()
{
    int n;	
    cin>>n;
    for(int i= 1;i<=n;i++){ read(a[i]);ans += a[i];}
    tmp = ans;
    sort(a+1,a+n+1);
    int minn = INF;
    v.clear();
    solve(a[1]);
    //cout<<v.size()<<endl;
    for(int i= 0;i<v.size();i++)
    {
    	//memcpy()
    	int x = a[1] / v[i];
    	int y = a[2] * v[i];
    	int ini = ans;
        int tmp = ini - a[1] - a[2] + x + y;
        minn = min(minn,tmp);
        //cout<<tmp<<endl;
    }
    for(int i= 2;i<=n;i++)
    {
    	v.clear();
    	solve(a[i]);
        for(int j = 0;j<v.size();j++)
        {
        	int x = a[i] / v[j];
            int y = a[1] * v[j];
            int ini = ans;
           // cout<<a[i]<<" "<<v[j]<<endl;
            int tmp = ini - a[i] - a[1]+x+y;
            minn = min(minn,tmp);
            //cout<<tmp<<" "<<i<<endl;

            //cout<<ini<<endl;
        }
    }
    cout<<min(minn,tmp)<<endl;
	return 0 ;
} 
*/
/*
独立思考
*/
/*
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
const int N = 3e5+5;
int a[N];
struct s_tree
{
	int l;
	int r;
	int dat;
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].dat = tree[rt<<1].dat ^ tree[rt<<1|1].dat;
}
void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].dat = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

int query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].dat;
	int ans = 0 ;
	int mid = (l+r)>>1;
	if(L <= mid) ans ^= query(rt<<1,L,R);
    if(R > mid) ans ^= query(rt<<1|1,L,R);
    return ans;
}

int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++) read(a[i]);
    build(1,1,n);
    int ans = 0;
    for(int i= 1;i<=n;i += 2)
    {
    	for(int j =1;j+i<= n;j++)
    	{
    		if(!query(1,j,j+i))   ans++;
    		//cout<<j<<" "<<j+i+1<<endl;
    	}
    }
    cout<<ans<<endl;	
	return 0 ; 
}
*/
/*
独立思考
*/
/*
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
const int N = 3e5+5;
int a[N];
ll sum[N];
int vis[(1<<20)+5][2];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) read(a[i]);
	for(int i= 1;i<=n;i++) sum[i] = sum[i-1]^a[i];
	ll ans = 0;
    vis[0][0] = 1;
	for(int i =1;i<=n;i++)
	{
		ans += vis[sum[i]][i&1];
		vis[sum[i]][i&1]++;
	}
	cout<<ans<<endl;
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>d;
		int delta = d*d-4*d;
		if(d == 0)
		{
			printf("Y 0.000000000 0.000000000\n");
			continue;
		}
		if(delta < 0)
		{
			cout<<"N"<<endl;
			continue;
		}
		else 
		{
			double a = (-d+sqrt((double)delta))/(-2);
			double b = (double)d - a;
			printf("Y %.9f %.9f\n",b,a);
		}
	}
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
ll mypow(ll x,ll n)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = res*x;
		x = x * x ;
		n >>= 1;
	}
	return res;	
}
//
int main ()
{
    int n;
    cin>>n;
    ll ans = 0;
    for(int i =1;i<=n;i++)
    {
    	ans += mypow(2,i);
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
独立思考
*/
/*
独立思考
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool notprime[1000003];
int prime[1000003], cnt;
inline void getPrime() {
    prime[1] = 2; cnt = 1;
    for(int i = 3; i <= 100003; i += 2) {
        if(notprime[i]) continue;
        prime[++cnt] = i;
        for(int j = 2; i * j < 100003; ++j)
            notprime[i * j] = 1;
    }
}
inline ll fj(ll n)
{
	ll ans = 0;
	for(int i = 2;i <= cnt;i++)
	{
		if(n % prime[i] == 0) 
		{
			ans = prime[i];
			break;
		}
	}
	return ans;
}
int judge(ll n)
{
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
int main ()
{
    ll n;
    cin>>n;
    getPrime();
    int ans = 0;
    if(judge(n))
    {
    	cout<<1<<endl;
    	return 0;
    }
    if(n % 2 == 0)
    {
    	cout<<n/2<<endl;
    	return 0;
    }
    else 
    {
    	ll ans = fj(n);
    	ll tmp = 0;
    	tmp++; 
    	n -= ans;
    	tmp += n/2;
    	cout<<tmp<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e2+5;
struct node
{
	int x;
	int id;
}a[N];
bool cmp(node a,node b)
{
	return a.x < b.x;
}
std::vector<int> v;
int main ()
{
    int n,w;
    cin>>n>>w;
    for(int i= 1;i<=n;i++) 
    {
    	cin>>a[i].x;
    	a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    v.push_back(0);
    int sum = 0;
    int tmp = 0;
    if(a[1].x % 2) tmp += a[1].x/2+1;
    else tmp += a[1].x/2;
    v.push_back(tmp);
    sum += tmp;
    for(int i= 2;i <= n;i++)
    {
       if(a[i].x != a[i-1].x) {sum += ++tmp;v.push_back(tmp);}
       else {sum += tmp;v.push_back(tmp);}    
    } 
    //cout<<sum<<endl;
    //for(int i= 0;i<v.size();i++) cout<<v[i]<<endl;
    //cout<<sum<<endl;
    if(sum > w) 
    {
    	cout<<-1<<endl;
    	return 0;
    }
    if(sum == w)
    {
    	for(int i =1;i<=v.size()-1;i++)
    		cout<<v[a[i].id]<<" ";
        return 0;
    }
    w -= sum;
    //cout<<a[2].x<<endl;
    for(int i = v.size()-1;i>=1 && w;i--)
    {
        if(a[i].x - v[i] < w) {v[i] = a[i].x;w-=a[i].x;}
        else {v[i] += w;w = 0;}
    }
    for(int i = 1;i<=v.size()-1;i++)
    {
    	cout<<v[a[i].id]<<" ";
    }
    //cout<<v[1]<<endl
	return 0 ;
}
*/
/*
独立思考
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
	const int N = 1e5+5;
	string ans;
	int a[N];
	string str;
	int tot = 0;
	void solve1(int sz)
	{
		sz += 1;
		for(int i= 1;i<=sz/2;i++)
			ans.push_back('4');
		for(int i= 1;i<=sz/2;i++)
			ans.push_back('7');
	}
	void solve2(int sz)
	{
	    sz += 2;
	    for(int i= 1;i<=sz/2;i++)
	    	ans.push_back('4');
	    for(int i= 1;i<=sz/2;i++)
	    	ans.push_back('7');
	}
	int main ()
	{
	    string s;
	    cin>>s;
	    int sz = s.size();
	    if(sz % 2)
	    {
	       solve1(sz);
	       cout<<ans<<endl;
	    }    	
	    else 
	    {
	    	for(int i= 0;i<sz/2;i++)
	    		str.push_back('4');
	    	for(int i= 0;i<sz/2;i++)
	    		str.push_back('7');
	    	int tot = 0;
	    	int flag = 0;
	    	do
	    	{
	          if(str >= s)
	          {
	          	for(int i= 0;i<str.size();i++)
	          		cout<<str[i];
	          	return 0;
	          }
	    	}while(next_permutation(str.begin(),str.end()));
	    	solve2(sz);
	    	cout<<ans<<endl;
	    }
		return 0 ;
	}
