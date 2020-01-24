#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int m,n;
int a[N*3],tot,b[N*3],tmp,sum[N*3];
int x[N*3],y[N*3][2];
int query(int x)
{
  return lower_bound(b+1,b+tmp+1,x) - b;
}
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i =1;i<=n;i++) cin>>x[i],a[++tot] = x[i];
  cin>>m;
  for(int i = 1;i<=m;i++) cin>>y[i][0],a[++tot] = y[i][0];
  for(int i = 1;i<=m;i++) cin>>y[i][1],a[++tot] = y[i][1];
  sort(a+1,a+tot+1);
  for(int i = 1;i<=tot;i++)
  {
    if(i == 1 || a[i] != a[i-1])
    b[++tmp] = a[i];
  }
  for(int i= 1;i<=n;i++)
  {
    int tmp = query(x[i]);
    sum[tmp]++;
  }
  int cmax = -1,dmax = -1,ans = 0;
  for(int i = 1;i <= m;i++)
  {
    int xx = query(y[i][0]);
    int yy = query(y[i][1]);
    if(sum[xx] > cmax){
      cmax = sum[xx],dmax = sum[yy],ans = i;
    }
    else if(sum[xx] == cmax && sum[yy] > dmax)
    {
      cmax = sum[xx],dmax = sum[yy],ans = i;
    }
  }
   cout<<ans<<endl;
  return 0;
}
