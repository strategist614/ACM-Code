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
const int N = 1e6+5;
int is_prime[N];
int prime[N],m = 0;
void sieve(int n)
{
	for(int i= 0;i<=n;i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
    for(int i= 2;i<=n;i++)
    {
    	if(is_prime[i])
    	{
    	  prime[++m] = i;
    	  for(int j = 2*i;j<=n;j+=i) is_prime[j] = 0;	
    	}
    }
}
int solve(int x,int y)
{
	if(x < y) return 0;
	return x/y+solve(x/y,y);
}
map<int,int> mp;
int main ()
{
	int n;
	cin>>n;
	sieve(n);
    for(int i= 1;i<=m;i++)
    {
       int ans = solve(n,prime[i]);
       if(ans != 0) mp[prime[i]] = ans;
    }
    for(auto it = mp.begin();it != mp.end();it++)
    	cout<<it->first<<" "<<it->second<<endl;
	return 0 ;
}