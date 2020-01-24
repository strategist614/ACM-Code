#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int n;
  scanf("%d",&n);
  double S = 0.0;
  double T = 0.0;
  double x;
  double y;
  for(int i = 1;i<=n;i++)
  {
    scanf("%lf %lf",&x,&y);
    T += y;
    S += (double)x*(double)y;
  }
  double ans = 0.0;
  ans = (double)S/(double)T;
  printf("%.1lf\n",ans);
  return 0;
}
