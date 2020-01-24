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

const int N = 1e6+6;
std::vector<int> v[N];

int main ()
{
   int n,m,d;
   cin>>n>>m>>d;
   for(int i= 1;i<=m;i++) v[0].push_back(0);
   for(int i = 1;i<=n;i++)
   	{
         v[i].push_back(0);
   		 for(int j = 1;j <= m;j++)
   	     {
           int x;
           read(x);
           int t = (x >= d) ? 1 : 0;
           v[i].push_back(v[i-1][j]+v[i][j-1]-v[i-1][j-1]+t);
         }
    }
    int q;
    read(q);
    while(q--)
    {
    	int a,b,x,y;
    	read(a);
    	read(b);
    	read(x);
    	read(y);
    	long long ans = v[x][y]-v[a-1][y]-v[x][b-1]+v[a-1][b-1];
    	out(ans);
    	puts("");
    }
   return 0;
}