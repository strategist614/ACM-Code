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
const int MAX_L = 1e6+5;
const int MAX_SQRT_B = 1e6+5;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];
int a,b;
void sieve(ll a,ll b)
{
	for(int i= 0;(ll)i*i<=b;i++)is_prime_small[i] = true;
	for(int i= 0;i<=b-a;i++) is_prime[i] = true;
	for(int i= 2;(ll)i*i<=b;i++)
	{
		if(is_prime_small[i])
		{
			for(int j= 2*i;(ll)j*j <= b;j += i)is_prime_small[j] = false;
			for(ll j = max(2LL,(a+i-1)/i)*i;j <= b;j += i) is_prime[j-a] = false;
		}
	}
}
int main ()
{
    int n,m;
    cin>>n>>m;
    while(n--)
    {
       read(a);
       read(b);
       if(a < 1 || b > m) cout<<"Crossing the line"<<endl;
       else 
       {
       	   sieve(a,b);
       	   int cnt = 0;
       	   for(int j = 0;j <= b-a;j++)
       	   	if(is_prime[j]) cnt++;
       	   if(a == 1) cnt--;
       	   out(cnt);
       	   puts("");
       } 
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int sum[N];
bool prime[N];
void sieve(int n)
{
	sum[1] = 0;
	for(int i= 0;i<=n;i++) prime[i] = true;
	prime[0] = prime[1] = false;
    for(int i= 2;i<=n;i++)
    {
    	if(prime[i])
    	{
    		sum[i] = sum[i-1] + 1;
    		for(int j =2*i;j<=n;j+=i) prime[j] = false;
    	}
        else sum[i] = sum[i-1];
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    sieve(m);
    while(n--)
    {
    	int l,r;
    	cin>>l>>r;
    	if(l < 1 || r > m) cout<<"Crossing the line"<<endl;
    	else cout<<sum[r]-sum[l-1]<<endl;
    }
	return 0 ;
}