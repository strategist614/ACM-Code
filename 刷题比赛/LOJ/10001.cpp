#include<bits/stdc++.h>
using namespace std;
const int N = 6010;
const int M = 2e5+5;
struct node
{
  int l;
  int r;
  int dat;	
}a[N];
int vis[M];
bool cmp(node &a,node &b)
{
	return a.r < b.r ;
}
int main ()
{
    int n;
    scanf("%d",&n);
    int q;
    scanf("%d",&q);
    for(int i = 1;i <= q;i++) scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].dat);
    sort(a+1,a+q+1,cmp);
    int tmp = 0;
    int ans = 0;
    for(int i= 1;i<=q;i++)
    {
       tmp = 0;
       for(int j = a[i].l;j <= a[i].r;j++) if(vis[j]) tmp++;
       if(tmp >= a[i].dat) continue;
       for(int j = a[i].r;j >= a[i].l;j--) 
       {
       	  if(!vis[j])
       	  {
       	  	ans++;
       	  	tmp++;
       	  	vis[j] = 1;
       	  }
       	  if(tmp >= a[i].dat) break;
       }
    } 
    printf("%d\n",ans);
	return 0 ;
}
