#include<bits/stdc++.h>
using namespace std;
struct  node
{
    int p;
    int id;
}a[1005];
bool cmp(const node &a, const node &b)
{
	return a.p > b.p;
}
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
    	int n,m;
    	scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++) scanf("%d %d",&a[i].p,&a[i].id);
        int tmp = 0;
        double ans = 0.0;
        sort(a+1,a+n+1,cmp);
        for(int i= 1;i<=n;i++)
        {
        	if(a[i].id == 1)
            tmp++;
        }	
        if(tmp >= m)
        {
           for(int i= 1;i<=m;i++)
           {
           	   ans += a[i].p/2.0;
           }
           for(int i= m+1;i<=n;i++)
           {
           	  ans += (double)a[i].p;
           }
           printf("%.1f\n",ans);
        }
        else 
        {
           for(int i = 1;i<=tmp;i++)
           {
           	 ans += a[i].p/2.0;
           }
           for(int i = tmp+1;i<=n;i++)
           {
           	 ans += (double)a[i].p;
           }
           printf("%.1f\n",ans);
        }
    }
	return 0 ;
}