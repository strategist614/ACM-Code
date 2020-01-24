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
map<int,string> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    int n;
    cin>>n;
    mp[0] = "05";
    mp[1] = "08";
    mp[2] = "17";
    mp[3] = "02";
    mp[4] = "20";
    mp[5] = "11";
    if(n <= 2)
    	cout << -1 << endl;
    else 
    {
    	if(n == 3)
    		cout << 210 << endl;
    	else {
    		int tmp = n;
    		n -= 4;
            n %= 6;
            cout << 1;
            for(int i = 1;i <= tmp - 4;i++)
            	cout << 0;
            cout << mp[n];
            cout << 0 << endl;
    	}
    }
	return 0 ;
}