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
const int N = 1e5+5;
int trie[N*33][2];
int tot = 1;
int cnt = 0;
int a[N];
ll ksm(ll a,ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}

void insert(string s)
{
	int p = 1;
	for(int i= 0;i<s.size();i++)
	{
		int ch = s[i]-'0';
		if(!trie[p][ch]) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
}

ll search(string s)
{
	int p = 1;
	cnt = 0;
	for(int i = 0; i<s.size();i++)
	{
	   int ch = s[i]-'0';
       if(ch == 1)
       {
          if(trie[p][0]) p = trie[p][0],a[cnt++] = 0;
          else if(trie[p][1]) p = trie[p][1],a[cnt++] = 1;
       }
       else 
       {
          if(trie[p][1]) p = trie[p][1],a[cnt++] = 1;
          else if(trie[p][0]) p = trie[p][0],a[cnt++] = 0;
       }
	}
	ll ans = 0;
	for(int i= 0;i < cnt;i++)
	{
		 ans += a[i]*ksm(2,32-i-1);
	}
	return ans;
}
int main ()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int n;
	read(n);
	int a;
	read(a);
    ll ans = a;
    bitset<32> b(a);
    string s;
    for(int i = 31;i>=0;i--)
    	s += b[i]+'0';
    insert(s);
    for(int i= 2;i<=n;i++)
    {
       int a;
       read(a);
       string _;
       bitset<32> b(a);
       for(int i = 31;i>=0;i--)
           _ += b[i]+'0';
       ll tmp = search(_);
       ans = max(ans,tmp^a);
       insert(_);
    }
     cout<<ans<<endl;
	return 0 ;
}