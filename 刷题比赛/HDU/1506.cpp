#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
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
int a[N];
int w[N];
int main ()
{
	int n;
	while(~scanf("%d",&n) && n)
	{
	   stack<int> s;
	   s.push(0);	
	   ll ans = 0; 
       int tmp = 0;
       a[n+1] = 0;
       for(int i= 1;i<=n;i++) read(a[i]);
       for(int i= 1;i<=n+1;i++)
       {
       	 if(a[i] > s.top())
       	 {
       	 	s.push(a[i]);
       	 	w[s.size()] = 1;
       	 }
       	 else
       	 {
       	 	int width = 0;
       	 	while(s.top() > a[i] && s.size())
       	 	{
                width += w[s.size()];
                ans = max(ans,(ll)width * s.top());
                s.pop();
       	 	}
       	 	s.push(a[i]);
       	 	w[s.size()] = width + 1;
       	 }
       }
       out(ans);
       puts("");
    }
	return 0 ;
}