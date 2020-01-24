#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+5;
int a[N];
int n,c;
int solve(int x)
{
   int last = 1;
   for(int i = 1;i < c;i++)
   {
   	  int crt = last + 1;
      while(crt <= n && a[crt] - a[last] < x)
      {
         crt++;
      }
      if(crt == n+1) return 0;
      last = crt ; 
   }
   return 1;
}
int main ()
{
	while(scanf("%d %d",&n,&c)!=EOF)
	{
		for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l = 0;
	    int r = 1e9;
		while(l < r)
		{
			int mid = (l+r+1)>>1;
			if(solve(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n",r);
	}
	return 0 ;
}