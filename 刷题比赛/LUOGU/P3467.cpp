#include<bits/stdc++.h>
using namespace std;
const int N = 250005;
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
int main ()
{
	int n;
	read(n);
	int ans = 0;
	stack<int> s;
	for(int i = 1;i <= n;i++)
	{
       int a,b;
       read(a);
       read(b);
       while(s.size() && s.top() >= b)
       {
          if(s.top() == b) ans++;
          s.pop();
       } 
       s.push(b);
	}
	out(n-ans);
	puts("");
	return 0 ;
}