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
int a[15];
int vis[50];
int main ()
{
	int ans = 0;
	for(int i= 1;i<=10;i++) cin>>a[i];
	for(int i= 1;i<=10;i++)
		vis[a[i]%42]++;
	for(int i= 0;i<=41;i++)
       if(vis[i]) ans ++;
    cout<<ans<<endl;
	return 0 ;
}