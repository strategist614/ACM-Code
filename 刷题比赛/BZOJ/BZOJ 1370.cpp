#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int fa[N],a[N];
int find(int x)
{ return x==fa[x]? x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
 	fa[find(x)] = find(y);
 }
int n,m;
int main ()
{
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= 2*n;i++) fa[i] = i;
   int ans = 0;
   for(int i = 1;i <= m;i++)
   {
   	  char op[20];
   	  int x,y;
      scanf("%s",op);
      scanf("%d %d",&x,&y);
      if(op[0] == 'E')
       {fa[find(x)]=find(y+n); fa[find(x+n)]=find(y);}
      else 
      {
        fa[find(x)] = find(y);//敌人的朋友不一定是朋友
      }
   }
  for(int i= 1;i<=n;i++) a[i] = find(i);
  sort(a+1,a+n+1);
  for(int i= 1;i<=n;i++) if(a[i] != a[i-1]) ans++;
  printf("%d\n",ans);
  return 0 ; 
}
/*
6
4
E 1 4
F 3 5
F 4 6
E 1 2
*/


