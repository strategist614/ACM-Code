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
const int N = 105;
int gcd(int a, int b)
{
	return b ? gcd(b,a%b):a;
}
int a[N],n;
void read_list()
{
	string line;
	getline(cin,line);
	stringstream ss(line);
	n = 0;
	int x;
	while(ss >> x) a[++n] = x;
}

int main ()
{
	int t;
	cin>>t;	
	while (getchar() != '\n');
	while(t--)
	{
      read_list();
      int maxn = 0;
      for(int i= 1;i<=n;i++)
      	for(int j =i+1;j<=n;j++)
      	{
      		maxn = max(maxn,gcd(a[i],a[j]));
      	}
      cout<<maxn<<endl;
	}
	return 0 ;
}