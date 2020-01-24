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
const int N = 1e7+5;
int p[6645480],v[N],phi[N],m;
ll f[N];
void euler(int n)
{
	phi[1] = 1;
	memset(v,0,sizeof(v));
	m = 0;
    for(int i = 2;i<=n;i++)
    {
    	if(v[i] == 0)
    	{
    		v[i] = i,p[++m] = i;
    		phi[i] = i-1;
    	}
        for(int j = 1;j<=m;j++)
        {
    	 if(p[j] > v[i] || p[j] > n/i) break;
    	 v[i*p[j]] = p[j];
    	 phi[i*p[j]] = phi[i]*(i%p[j]?p[j]-1:p[j]);
        }
   }
}
int main ()
{
	int n;
	cin>>n;
	euler(n);
	ll ans = 0;
	for(int i= 1;i <= n;i++) f[i] = f[i-1]+phi[i];
	for(int i= 1;i <= m;i++)
	{
		if(p[i] > n) break;
		ans +=2*f[n/p[i]]-1;
	}
	cout<<ans<<endl;
 	return 0 ;
}
/*
//gcd(x,y)为pp的数对个数即为1<=a,b<= \frac{n}{p}1<=a,b<= pn
中互质对a,b的个数
*/