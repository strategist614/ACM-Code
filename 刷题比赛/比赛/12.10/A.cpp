/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(int i)
{
	int x = i % 10;
	int y = (i / 10)%10;
	int z = i /100;
	if(x*x*x + y*y*y + z*z*z == i) return 1;
	else return 0;
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
       int l;
       int r;
       cin>>l>>r;
       int ans = 0;
       for(int i= l;i<=r;i++)
          if(solve(i)) ans++;
      cout<<ans<<endl;
      } 
	return 0 ;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	ll ans = pow(2,n-1);
    	cout<<ans<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int x = floor(sqrt(n));
    	cout<<x<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000];
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
       scanf("%s",s);
       int size = strlen(s);
       for(int i= 0;i<size;i++)
       {
       	  if(s[i] >= '0' && s[i] <= '9')

       }
    }
	return 0 ;
}
*/
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
    int t;
    read(t);
    while(t--)
    {
    	int n,m;
    	read(n);
    	read(m);
    	int ans = 0;
    	for(int i= 1;i<=n;i++)
    		for(int j = 1;j<=m;j++)
    		{
    			if((i+j)%7 == 0) ans++;
    		}
        out(ans);
        puts("");
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		int n;
		cin>>n;
		while(n)
		{
           v.push_back(n%2);
           n /= 2;
		}
		for(int i= v.size()-1;i>=0;i--)
			{
			  cout<<v[i];
			}
		cout<<endl;
	}
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
char s[1000];
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s);
		int size = strlen(s);
		int a = 0;
		int b = 0;
		int flag = 0;
		int pos = 0;
		for(int i = 0;i<size;i++)
		{
            if(s[i] > '9' || s[i] < '0')
            {
                 pos = i;
                 if(s[i] == '+') flag =1 ;
                 if(s[i] == '-') flag =2;
                 if(s[i] == '*') flag = 3;
                 if(s[i] == '/') flag = 4;
                 break;
            }
		}
		for(int i =0;i<pos;i++)
		{
            a = a*10+s[i]-'0';
		}
		for(int i = pos+1;i<size;i++)
		{
			b = b*10+s[i]-'0';
		}
		if(flag == 1)
		{
			cout<<a+b<<endl;
		}
		else if(flag == 2)
		{
			cout<<a-b<<endl;
		}
		else if(flag == 3)
		{
			cout<<a*b<<endl;
		}
		else cout<<a/b<<endl;
 	}
	return 0 ;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	ll ans = pow(2,n-1);
    	cout<<ans<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[40];
int main ()
{
	int t;
	cin>>t;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for(int i= 4;i<=30;i++)
		a[i] = a[i-1]+a[i-2]+a[i-3];
	while(t--)
	{
       int n;
       cin>>n;
       cout<<a[n]<<endl;
	}
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main ()
{
	int t;
	cin>>t;
	a[1] = 1;
	a[2] = 1;
	for(int i =3;i<=1000;i++)
	    a[i] = a[i-1]+a[i-2];
	while(t--)
	{
		int n;
		cin>>n;  
		int f = 0;
        for(int i =1;i<=1000;i++)
            if(n == a[i]) f = 1;
        if(f == 1) cout<<"Big"<<endl;
        else cout<<"Small"<<endl;
	}
	return 0 ;
}
*/