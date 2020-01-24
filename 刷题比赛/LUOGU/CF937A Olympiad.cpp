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
int a[105];
std::vector<int> v;
set<int> s;
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
	for(int i= 1;i<=n;i++)
	{
		if(a[i] != 0) v.push_back(a[i]);
	}
	for(int i=0;i<v.size();i++)
		s.insert(v[i]);
	cout<<(int)s.size()<<endl;	
	return 0 ;
}
