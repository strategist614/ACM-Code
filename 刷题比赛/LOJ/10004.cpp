#include<bits/stdc++.h>
using namespace std;
struct node
{
	int dl;
	int my;
}a[505];
bool cmp(node &a,node &b)
{
	return a.my > b.my;
}
int vis[505];
int main ()
{ 
    int m;
    scanf("%d",&m);
    int n;
    scanf("%d",&n);
    for(int i= 1;i<=n;i++) scanf("%d",&a[i].dl);
    for(int i= 1;i<=n;i++) scanf("%d",&a[i].my);
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++)
    {
    	int flag = 0;
    	for(int j= a[i].dl;j >= 1;j--)
    	{
            if(!vis[j])
            {
            	vis[j] = 1;
            	flag = 1;
            	break;
            }
    	}
    	if(!flag) m -= a[i].my;
    }
    printf("%d\n",m);
  	return 0 ;
}
//智障的我