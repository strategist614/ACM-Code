//看题解的
/*
#include<bits/stdc++.h>
using namespace std;
int a[3000];
int r[3000];
void mul(int a[],int b[])
{
	memset(r,0,sizeof(r));
	for(int i = 0; i < 500; ++i)
    {
        int before = 0;
        for(int j = 0; j < 500; ++j)
        {
            r[i + j] += a[i] * b[j] + before;
            before = r[i + j] / 10;
            r[i + j] %= 10;
        }
        if(before)
            r[i + 500] += before;
    }
}
void solve(int p)
{
	int b[3000];
	memset(b,0,sizeof(b));
	b[0] = 2;
	while(p)
	{
		if(p & 1)
		{
			mul(a,b);
			for(int i= 0;i<500;i++)
				a[i] = r[i];
		}
	    mul(b,b);
	    for(int i= 0;i<500;i++)
		   b[i] = r[i]; 
		p >>= 1;
	}
}
int main ()
{
	int p;
	cin>>p;
    cout<<(int)(p*log10(2))+1<<endl;
    memset(a,0,sizeof(a));
    a[0] = 1;
    solve(p);
    a[0]--;
    int sum = 0;
    for(int i = 499;i >= 0;i--)
    {
    	sum++;
    	cout<<a[i];
    	if(sum % 50 == 0)
    		cout<<endl;
    }
	return 0;
}
*/
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