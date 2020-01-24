/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
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
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int a[105];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF && n){
		memset(a,0,sizeof(a));
		int maxn = 0;
		for(int i = 1;i <= n;i++){
			int tmp ;
			read(tmp);
			a[tmp]++;
			maxn = max(maxn,tmp);
		}
		for(int i = 1;i <= 100;i ++){
			if(a[i] != 0){ 
				if(i != maxn){
				for(int j = 1;j <= a[i];j++)
					printf("%d ",i);
                }
                else {
                	for(int j = 1;j <= a[i];j++){
                		if(j != a[i]) printf("%d ",i);
                		else printf("%d\n",i);
                	}
                }
		}
	}
	}
	return 0 ;
}