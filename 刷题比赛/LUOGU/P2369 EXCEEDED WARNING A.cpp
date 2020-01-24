/*
独立思考
*/
/*
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
const int N = 1e6+5;
std::vector<short int> v;
int main ()
{
	int n,m;
	cin>>n>>m;
	v.push_back(0);
	for(int i= 1;i<=n;i++) 
	{
		short int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	for(int i = 1;i<=m;i++)
	{
		cout<<v[i]<<endl;
	}
	return 0 ;
}
*/
/*
独立思考
*/
/*
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
priority_queue<short int,vector<short int>,greater<short int>> q;
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i =1;i<=n;i++)
	{
	    short int tmp;
	    cin>>tmp;
		q.push(tmp);
	}
	for(int i= 1;i<=m;i++) 
	{
      cout<<q.top()<<endl;
      q.pop();	
	}
	return 0 ;
}
*/
/*
独立思考
*/
// 手写堆
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
	
	return 0 ;
}