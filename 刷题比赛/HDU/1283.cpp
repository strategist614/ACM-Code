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
int m1,m2,r1,r2,r3;
void A()
{
   r1 = m1;
}
void B()
{
  r2 = m2;
}
void C()
{
  m1 = r3;
} 
void D()
{
  m2 = r3;
}
void E()
{
  r3 = r1+r2;
}
void F()
{
  r3 = r1-r2;
}
int main ()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		string s;
		cin>>s;
		m1 = n,m2 = m,r1 = 0,r2 = 0,r3 = 0;
		for(int i = 0;i<s.size();i++)
		{
			if(s[i] == 'A') A();
			else if(s[i] == 'B') B();
			else if(s[i] == 'C') C();
			else if(s[i] == 'D') D();
			else if(s[i] == 'E') E();
			else F();
		}
		cout<<m1<<","<<m2<<endl;
	}
	return 0 ;
}