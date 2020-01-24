/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
const int N = 4e5+5;
char s[N];
int Next[N];
std::vector<int> v;
void solve()
{
	v.clear();
	memset(Next,0,sizeof(Next));
	int n = strlen(s+1);
	Next[1] = 0;
	for(int i = 2,j = 0;i <= n;i ++)
	{ 
		while(j > 0 && s[i] != s[j+1]) j = Next[j];
		if(s[i] == s[j+1]) j++;
		Next[i] = j;
	}
	int j = Next[n];
	v.push_back(j);
	v.push_back(n);
	while(Next[j])
	{
		v.push_back(Next[j]);
		j = Next[j];
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++) {if(v[i] == 0) continue;cout<<v[i]<<" ";}
	cout<<endl;
}
int main ()
{ 
    while(scanf("%s",s+1) != EOF)
    {
    	solve();
    }	
	return 0 ;
}