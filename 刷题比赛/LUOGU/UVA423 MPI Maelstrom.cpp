/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>

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
int a[105][105];
void readln(string s,int pos)
{
    int cnt = 1;
	for(int i= 0;i<s.size();)
	{
		if(s[i] == 'x') {i++;continue;}
		else if(s[i] >= '1' && s[i] <= '9') 
		{
			int num = 0;
            while(s[i] >= '0' && s[i] <= '9')
            {
            	num = num * 10 + s[i]-'0';
            	i++;
            }
            a[pos][cnt] = num;
		}
		else {i++;cnt++;}
	}
}
int n;
void print()
{
	for(int i= 2;i<=n;i++){
		for(int j =1;j<=i-1;j++)
			printf("%d",a[i][j]);
		cout<<endl;
	}
}
int main ()
{
	cin >> n;
	getchar();
	memset(a,0x3f,sizeof(a));
	for (int i = 1; i <= n; i++) a[i][i] = 0 ;
	for (int i = 2; i <= n; i++)
	{
	   string s;
       getline(cin,s);
	   readln(s,i);
	}
	for(int i= 2;i<=n;i++)
		for(int j= 1;j<=i-1;j++)
			a[j][i] = a[i][j];
    for(int k= 1;k<=n;k++)
    	for(int i =1;i<=n;i++)
          for(int j= 1;j<=n;j++)
             a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
    int ans = 0;
    for(int j= 1;j<=n;j++)
      ans = max(ans,a[1][j]);
    cout<<ans<<endl;
	return 0 ;
}