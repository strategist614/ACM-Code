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
int a[10][10];
int x[101][10];
int main ()
{
	for(int i= 1;i<= 4;i++) 
		for(int j = 1;j <=4 ;j++)
	       cin>>a[i][j];
	if(a[1][4] == 1)
	{
        if(a[3][2] == 1 || a[2][1] == 1 || a[4][3] == 1 || a[1][1] == 1 || a[1][2] == 1 || a[1][3] == 1) {puts("YES");return 0;} 
	}
    if(a[2][4] == 1)
    {
        if(a[1][3] == 1 || a[3][1] == 1 || a[4][2] == 1 || a[2][1] == 1 || a[2][2] == 1 || a[2][3] == 1) {puts("YES");return 0;}
    }
    if(a[3][4] == 1)
    {
        if(a[1][2] == 1 || a[2][3] == 1 || a[4][1] == 1 || a[3][1] == 1 || a[3][2] == 1 || a[3][3] == 1) {puts("YES");return 0;}
    }
    if(a[4][4] == 1)
    { 
        if(a[1][1] == 1 || a[2][2] == 1|| a[3][3] == 1 || a[4][1] == 1 || a[4][2] == 1 || a[4][3] == 1	) {puts("YES");return 0;}
    }
    puts("NO");
	return 0 ;
}