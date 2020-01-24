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
ull nowk,pofs,k;
unsigned ansa,ansb,n,sq,sp,a,b;
int main ()
{
    while(scanf("%u %u %u",&n,&sp,&sq)!=EOF)
    {
    	k = 0xffffffffffffffff;
    	for( a = 0;a<32;a++){
          for( b = 0;b < 32;b++)
          {
          	   pofs = (n-1)*sp;
          	   nowk = (pofs + (pofs<<a)>>b) + sq;
               if(nowk >= n * sq && nowk < k) k = nowk,ansa = a,ansb = b;
          }
        }
        printf("%llu %u %u\n",k,ansa,ansb);
    }	
	return 0 ;
}
