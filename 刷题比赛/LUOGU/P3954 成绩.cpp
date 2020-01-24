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
int main ()
{
	int a,b,c;
	cin>>a>>b>>c;
    double ans1 = a * 0.2;
    double ans2 = b * 0.3;
    double ans3 = c * 0.5;
    printf("%d\n",(int)(ans1+ans2+ans3));
	return 0 ;
}
