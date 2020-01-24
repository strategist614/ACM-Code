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
int main ()
{
	string s,t;
	while(cin>>s>>t)
	{
		int j = 0;
		if(s.size() > t.size()) 
		{
			cout<<"No"<<endl;
			continue;
		}
		for(int i= 0;i<t.size();i++)
		{
			if(t[i] == s[j])
				j++;
		}
		if(j == s.size()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0 ;
}
