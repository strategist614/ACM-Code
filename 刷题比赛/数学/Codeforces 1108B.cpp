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
int a[10006];
int vis[10006];
void solve(int x)
{
	vis[1]++;
	vis[x]++;
	for(int i= 2;i <= sqrt(x);i++)
	{
	    if(x % i == 0) {
	    	vis[i]++;
	        if(x / i != i)vis[x / i]++;
	    }
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	std::vector<int> v;
	int n;
	cin>>n;
	for(int i= 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    if(n == 2)
    {
    	if(a[1] == 1 && a[2] == 1)
    		cout << 1 << " "<<1<<endl;
    	return 0;
    }
	ll x = a[n];
	solve(x);
    for(int i =1;i <= n;i++){
         if(!vis[a[i]]) v.push_back(a[i]);
         else 
         {
         	vis[a[i]]--;
         } 
    }
    sort(v.begin(), v.end());
    //cout << v.size() << endl;
    ll y = v[v.size() - 1];
    cout << x <<" "<<y<<endl;
	return 0 ;
}