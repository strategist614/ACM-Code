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
const int N = 1e5+5;
int c[N];
int a[N];
int n,q;
void add(int x,int y)
{
	for(;x <= N;x += x&-x) c[x] += y;
}
int ask(int x)
{
	int ans =0 ;
	for(;x;x-=x&-x) ans += c[x];
	return ans;
}
int main ()
{
    read(n);
    read(q);
    while(q--)
     {
     	int op;
     	read(op);
     	if(op == 1)
     	{
           int l,r;
           read(l);
           read(r);
           add(l,1);
           add(r+1,-1);
     	}
     	else 
     	{
     	   int x;
     	   read(x);
           int cnt = ask(x);
           int ans = 0;
           if(cnt %2 == 0) ans = 0;
           else ans = 1;
           printf("%d\n",ans); 
     	}
     }
	return 0 ;
}
*/
