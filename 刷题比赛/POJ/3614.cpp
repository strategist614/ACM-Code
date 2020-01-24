/*
#include<iostream>
#include<algorithm>
using namespace std;
struct sum1
{
  int maxn;
  int minn;
}cow[2505];
struct sum2
{
  int spf;
  int cov;
}spa[2505];
bool cmp(const sum1 &a,const sum1 &b)
{
  return a.minn>b.minn;
}
bool cmp2(const sum2 &a,const sum2 &b)
{
  return a.spf>b.spf;
}
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c,l,cnt = 0;
  cin>>c>>l;
  for(int i=0 ;i<c;i++)
    cin>>cow[i].minn>>cow[i].maxn;
  sort(cow,cow+c,cmp);
  for(int i =0;i<l;i++)
   cin>>spa[i].spf>>spa[i].cov;
  sort(spa,spa+l,cmp2);
  for(int i =0;i<c;i++)
  {
    for(int j =0;j<l;j++)
    {
      if(spa[j].cov>0&&spa[j].spf<=cow[i].maxn&&spa[j].spf>=cow[i].minn)
         {
           spa[j].cov--;
           cnt++;
           break;
         }
    }
  }
  cout<<cnt<<endl;
  return 0 ;
}
*/
