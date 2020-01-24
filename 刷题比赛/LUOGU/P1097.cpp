#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
map<ll,int>mp;
map<ll,int>::iterator it;
int main ()
{
	int n;
	read(n);
	for(int i= 1;i<=n;i++) 
	{
       ll x ;
       read(x);
       mp[x]++;
	}
	for(it = mp.begin();it != mp.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0 ;
}