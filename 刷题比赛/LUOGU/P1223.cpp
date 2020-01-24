#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct node
{
  int id;
  int rt;
}a[N];
bool cmp(const node &a ,const node &b)
{
  if(a.rt != b.rt)
  return a.rt < b.rt;
  return a.id < b.id;
}
int main ()
{
  int n;
  scanf("%d",&n);
  for(int i =1;i<=n;i++) {
    scanf("%d",&a[i].rt);
    a[i].id = i;
  }
  sort(a+1,a+n+1,cmp);
  for(int i =1;i<=n;i++)
   printf("%d ",a[i].id);
  printf("\n");
  double ans = 0;
  double cnt = 0;
  for(int i =1;i<=n;i++)
   ans += i * a[n-i].rt;
  cnt = ans / n;
  printf("%.2f",cnt);
  return 0 ;
}
