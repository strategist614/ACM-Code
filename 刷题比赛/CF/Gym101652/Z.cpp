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
std::vector<int> v;
const int N = 1e6;
bool solve(int n)
{
	//int flag = 0;
	while(n)
    {
    	if(n % 10 == 0)return 0;
    	n /= 10; 
    }
    return 1;
}
int main ()
{
	for(int i= 1;i <= N;i++)
		if(solve(i)) v.push_back(i);
	int n;
	cin>>n;
	if(n == 999999)
	{
		cout<<1111111<<endl;
		return 0;
	}
    int pos = upper_bound(v.begin(),v.end(),n)-v.begin();
	cout<<v[pos]<<endl;
	return 0 ;
}