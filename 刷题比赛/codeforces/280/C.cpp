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
struct node
{
	int a;
	int b;
}s[N];
bool cmp(node x,node y)
{
	if(x.b == y.b) return x.a < y.a;
	return x.b < y.b; 
}
int main ()
{

	int n,r,avg;  
	read(n);
	read(r);
	read(avg);
    long long sum = 0;
    long long cnt = (long long)((long long)avg*(long long)n);
	for(int i= 1;i<=n;i++) {read(s[i].a);read(s[i].b);sum += s[i].a;}
	if(sum >= cnt)
	{
		cout<<0<<endl;
		return 0 ;
	}
    long long ans = 0;
    long long tmp = cnt - sum;
    sort(s+1,s+n+1,cmp);
	for(int i= 1;i<=n;i++)
	{
		s[i].a = r - s[i].a; 
	}
	for(int i = 1;i<=n;i++)
	{
		if(s[i].a <= 0) continue;
	    if(tmp - s[i].a >= 0)
	    {
	    	ans += (long long)s[i].b * (long long)s[i].a;
	        tmp -= s[i].a;
	    }
	    else {
            ans += (long long)tmp * (long long)s[i].b;
            break;
	    }
	}
    out(ans);
    puts("");
	return 0 ;
}
/*
6 5 5
1 7
2 4
3 5
4 6
5 6
4 7
63
*/