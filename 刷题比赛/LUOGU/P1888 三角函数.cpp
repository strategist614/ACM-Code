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
int gcd(int a,int b)
{
	return b ? gcd(b,a%b):a;
}
int a[5];
int main ()
{
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+3+1);
    if(gcd(a[1],a[3]) == 1) printf("%d/%d\n",a[1],a[3]);
    else printf("%d/%d\n",a[1]/gcd(a[1],a[3]),a[3]/gcd(a[1],a[3])); 
	return 0 ;
}
