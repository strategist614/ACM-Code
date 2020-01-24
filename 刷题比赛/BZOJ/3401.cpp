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
const int N = 1e5+5;
int a[N];
int l[N];
stack<int> s;
int main ()
{
    int n;
    read(n);
    for(int i= 1;i<=n;i++) read(a[i]);
    for(int i= 1;i<=n;i++)
    {
       while(s.size() && a[s.top()] >= a[i]) s.pop();
       if(s.empty())  l[i] = 0;
       else l[i] = s.top();
       s.push(i); 
    }
    for(int i = 1;i <= n;i++) cout<<l[i]<<endl;
	return 0 ;
}