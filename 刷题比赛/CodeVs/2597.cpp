#include<bits/stdc++.h>
using namespace std;
int fa[5005],c[5005];
int find(int x)
{
  if(x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
  fa[find(x)] = find(y);
}
int main ()
{
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
   fa[i] = i;
  char str;
  for(int i =  1;i<=m;i++)
   {
     int a,b;
     cin>>str>>a>>b;
     if(str == 'F')
      merge(a,b);
     else {
       if(c[a] == 0)
       c[a] = find(b);
       else fa[find(c[a])] = find(b);
       if(c[b] == 0)
       c[b] = find(a);
       else fa[find(c[b])] = find(a);
     }
   }
   int ans = 0;
   for(int i =1;i<=n;i++)
   {
     if(fa[i] == i) ans++;
   }
   cout<<ans<<endl;
  return 0 ;
}
