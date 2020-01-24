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
const int N = 1e5+5;
int c[N];
int a[N];
int n,k;
void add(int x,int y)
{
	for(;x <= N;x+=x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x-=x&-x) ans += c[x];
	return ans;
}
int main ()
{
//	int n,k;
    read(n);
    read(k);
    for(int i = 1;i<=k;i++)
    {
    	char op[20];
    	scanf("%s",op);
    	if(op[0] == 'A')
    	{
           int m;
           read(m);
           int ans = ask(m);
           out(ans);
           puts("");
    	}
    	else if(op[0] == 'B')
    	{
           int m,p;
           read(m);
           read(p);
           add(m,p);
    	}
    	else 
    	{
           int m,p;
           read(m);
           read(p);
           add(m,-p);
    	}
    }
	return 0 ;
}