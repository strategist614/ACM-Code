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
const int INF = 1e7;
const int N = 505;
const int maxn = 1e6+5;
int w[N];
int v[N];
int f[maxn];
int main ()
{
    int t ;
    read(t);
    while(t--)
    {
    	int e,fx,n;
    	scanf("%d %d",&e,&fx);
    	scanf("%d",&n);
    	int m = fx - e;
    	for(int i = 1;i<=n;i++) {read(w[i]);read(v[i]);}
    	//for(int i = 1;i<=n;i++) read(v[i]);
    	for(int i = 0;i<=m;i++) f[i] = INF;
    	f[0] = 0;
       // cout<<f[1]<<endl;
        for(int i= 1;i<=n;i++)
        {
        	for(int j =v[i];j<=m;j++)
        	{
        		f[j] = min(f[j],f[j-v[i]]+w[i]);
        	}
        }
        if(f[m] == INF) 
        {
        	printf("This is impossible.\n");
        }
        else printf("The minimum amount of money in the piggy-bank is %d.\n",f[m]);
    }
	return 0 ;
}
