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
const int N = 1e5+5;
int a[N];
int main ()
{
    int t;
    cin>>t;
    int j;
    for(int i= 1;i<=100000;i++)
    {
    	int x = i,y = i;
    	while(x)
    	{
    		y += x % 10;
    		x /= 10;
    	}
    	if(a[y] == 0 || i < a[y]) a[y] = i;
    }
    while(t--)
    {
    	int n;
    	read(n);
    	out(a[n]);
    	puts("");
    }
	return 0 ;
}
