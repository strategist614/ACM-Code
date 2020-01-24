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
int n,m;
int fa[30005];
int sz[30005];
std::vector<int> v[505];
void init(int n)
{
   for(int i =0;i<n;i++) {fa[i] = i;sz[i] = 1;}
}
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a != b)
	{
		sz[a] += sz[b];
		fa[b] = a;
	}
}
int vis[30005];
int main ()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init(n);
		if(n == 0 && m == 0) break;
        for(int i= 1;i<=m;i++)
        {
             int k,one;
             cin>>k>>one;
             for(int j =1;j<k;j++)
             {
             	int two;
             	cin>>two;
             	merge(one,two);
             }
        }
        cout<<sz[find(0)]<<endl;
	}
	return 0 ;
}
