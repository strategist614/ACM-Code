#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int Next[N],f[N];
char a[N],b[N];
inline int kmp()
{
  Next[1] = 0;
  int res = 0;
  int n = strlen(a+1);
  int m = strlen(b+1);
  for(int i = 2,j = 0;i<=n;i++)
  {
    while(j > 0 && a[i] != a[j+1]) j = Next[j];
    if(a[i] == a[j+1]) j++;
    Next[i] = j;
  }
  for(int i = 1,j = 0;i<=m;i++)
  {
    while(j> 0&&(j == n|| b[i] != a[j+1])) j = Next[j];
    if(b[i] == a[j+1]) j++;
    f[i] = j;
  if(f[i] == n)
  {
    res++;
  }
}
  return res;
}
int main ()
{
	scanf("%s",b+1);
	scanf("%s",a+1);
	int ans = kmp();
	printf("%d\n",ans);
	return 0 ;
}