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
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
map<string ,int> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    string s;
    int ans = 0;
    int sum = 0;
    while(getline(cin,s))
    {
       string tmp;
       if(s[0] == '+' || s[0] == '-')
       {
           for(int i = 1;i < s.size();i++)
           	tmp += s[i];
           if(s[0] == '+'){
           	if(!mp[tmp]) 
           	{
           		ans ++;
           		mp[tmp]++;
           	}
           	else mp[tmp]++;
           }
           else 
           {
           	 if(mp[tmp] >= 2) mp[tmp]--;
           	 else if(mp[tmp] == 1){
           	 	ans--;
           	 	mp[tmp]--;
           	 }
           }
       }
       else 
       {
          int _ = 0;
       	  for(int i = 0;i < s.size();i++){
       	  	if(s[i] == ':'){_++;break;}
            else _++;
       	  }
       	  sum += (s.size() - _) * ans;
       }
    }
    cout << sum << endl;
	return 0 ;
}