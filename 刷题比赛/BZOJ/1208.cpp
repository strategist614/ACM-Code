
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6;
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
set<ll> s[2];
set<ll>::iterator r,r1;
int main ()
{
	int n;
	read(n);
	ll ans  = 0;
    for(int i= 1;i<=n;i++)
    {
      ll x,b;
      read(x);
      read(b);
      if(s[x^1].empty())
      {
      	s[x].insert(b);
      	continue;
      }
      r = s[1^x].lower_bound(b);
      if(r == s[1^x].end()) r--;
      if(r != s[1^x].begin())
      {
      	r1 = r;
      	r1--;
      	if(abs(*r1 - b) <= abs(*r - b)) r--;
      }
      ans += abs(*r-b)%mod;
      ans %= mod;
      s[1^x].erase(r);
    } 
    out(ans);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6;
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
set<ll> sl;
set<ll> sc;
set<ll>::iterator ic,il,r;
int main ()
{ 
    int n;
    scanf("%d",&n);
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a == 0)
        {
          if(sl.empty()) 
          {
          	sc.insert(b);
          	continue;
          }
          il = sl.lower_bound(b);
          if(il == sl.end()) il--;
          if(il != sl.begin())
          {
             r = il;
             r--;
             if(abs(*r- b) <= abs(*il - b)) il--;
          }
          ans += abs(*il - b)%mod;
          ans %= mod;
          sl.erase(il);
        }
        else 
        {
           if(sc.empty())
           {
              sl.insert(b);
              continue;
           }
           ic = sc.lower_bound(b);
           if(ic == sc.end()) ic--;
           if(ic != sc.begin())
           {
           	 r = ic;
           	 r--;
           	 if(abs(*r - b) <= abs(*ic - b)) ic--;
           }
           ans += abs(*ic - b)%mod;
           ans %= mod;
           sc.erase(ic);
        }
    }
    printf("%lld\n",ans);
	return 0 ;
}
*/
//SPLAY
#include<bits/stdc++.h>
using namespace std;
int main ()
{
  
	return 0 ;
}