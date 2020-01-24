#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int N = 5e4+5;
int sum[N];
int tot;
int a[N];
int len,m,n;
int solve(int x)
{
   int st = 0,_ = 0;
   for(int i =1;i<=tot;i++)
   {
   	if(sum[i] - st < x)
       _++;
    else st = sum[i];
   }
   if(_ > m) return 0;
   return 1;
}
int main ()
{  
    scanf("%d %d %d",&len,&n,&m);
    for(int i= 1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++) sum[++tot] = a[i];
    sum[++tot] = len;	
    int l = 1;
    int r = 1e9;
    while(l < r)
    {
    	int mid = (l+r+1)>>1;
    	if(solve(mid)) l = mid;
    	else r = mid - 1;
    }
    printf("%d\n",l);
	return 0 ;
}