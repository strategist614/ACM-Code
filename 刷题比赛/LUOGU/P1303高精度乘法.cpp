#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
char a1[N],b1[N];
int a[N],b[N],ans[N];
int lena,lenb;
void solve()
{
   memset(ans,0,sizeof(ans));
   int x=  0;
   for(int i= 1;i<=lena;i++)
   {
      x=  0;
      for(int j = 1;j<=lenb;j++)
      {
      	 ans[i+j-1] += a[i]*b[j]+x;
      	 x = ans[i+j-1]/10;
      	 ans[i+j-1] %= 10;
      }
      ans[i+lenb] = x;
   }
}
int main ()
{
    scanf("%s",a1);
    scanf("%s",b1);
    lena = strlen(a1);
    lenb = strlen(b1);
    for(int i = 0;i<lena;i++) a[lena-i] = a1[i]-'0';
    for(int i= 0;i<lenb;i++) b[lenb-i] = b1[i]-'0';
    solve();
    int lenc = lenb+lena;
    while(ans[lenc]==0&&lenc>1)
    	lenc--;
    for(int i= lenc;i>=1;i--)
    	cout<<ans[i];
    cout<<endl;
	return 0 ;
}