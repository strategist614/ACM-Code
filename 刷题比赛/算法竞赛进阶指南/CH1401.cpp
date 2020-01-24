#include<bits/stdc++.h>
using namespace std;
char s[1000010];
unsigned long long f[1000010],p[1000010];
int main ()
{
  scanf("%s",s+1);
  int n = strlen(s+1),q; cin>>q;
  p[0] = 1;
  for(int i =1;i<=n;i++)
  {
    f[i]= f[i-1]*131+(s[i]-'a'+1);
    p[i] = p[i-1]*131;
  }
  for(int i=1;i<=q;i++)
  {
    int l1,r1,l2,r2;
    scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
    if(f[r1]-f[l1-1]*p[r1-l1+1] == f[r2]-f[l2-1]*p[r2-l2+1])
    puts("Yes");
    else puts("No");
  }
  return 0 ;
}