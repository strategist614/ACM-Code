#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int c[N],r[N];
int sumc[N],sumr[N];
int main ()
{
	int n,m,t;
	cin>>n>>m>>t;
    while(t--)
    {
    	int x,y;
    	cin>>x>>y;
    	c[x]++;
    	r[y]++;
    }
    int flagn = 0,flagm = 0;
    long long ans = 0;
    int Tr = 0,Tc = 0;
    for(int i= 1;i<=n;i++)
    {
    	Tc += c[i];
    }
    for(int i =1;i<=m;i++)
    {
    	Tr += r[i];
    }
    if(Tc % n == 0)
    {
      flagn = 1;
      for(int i= 1;i<=n;i++)
      {
        c[i] -= Tc / n;
      }
      for(int i=1;i<=n;i++)
        sumc[i] = sumc[i-1]+c[i];
      sort(sumc+1,sumc+n+1);
      int mid = 0;
      if(n % 2) mid = sumc[n/2+1];
      else mid = (sumc[n/2]+sumc[n/2+1])/2;
      for(int i= 1;i<=n;i++)
      {
      	ans += abs(sumc[i]-mid);
      }
    }
    if(Tr % m == 0)
    {
    	flagm =  1;
    	for(int i =1;i<=m;i++)
    	{
    		r[i] -= Tr / m;
    	}
    	for(int i= 1;i<=m;i++)
    		sumr[i] = sumr[i-1]+r[i];
        sort(sumr+1,sumr+m+1);
        int mid = 0;
        if(m % 2) mid = sumr[m/2+1];
        else mid = (sumr[m/2+1]+sumr[m/2])/2;
        for(int i =1;i<=m;i++)
        {
        	ans += abs(sumr[i]-mid);
        }
    }
    if(flagn && flagm)
    {
    	printf("both %lld\n",ans);
    }
    else if(flagm || flagn)
    {
        if(flagn == 1)
        {
           printf("row %lld\n",ans); 
        }
        else 
        {
          printf("column %lld\n",ans);
        }
    }
    else printf("impossible\n");
	return 0 ;
}