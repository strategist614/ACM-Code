#include<bits/stdc++.h>
using namespace std;
const int N= 1e6+5;
int a[N];
int c[N];
void add(int x,int y)
{
   for(;x<=N;x+=x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x-=x&-x) ans += c[x];
	return ans;
}
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    memset(c,0,sizeof(c));
    int ans = 0;
    for(int i=n;i;i--)
    {
       ans += ask(a[i]-1);
       add(a[i],1);
    }
    if(n % 2 == 0)
    {
    	if(ans % 2 == 0) cout<<"Petr"<<endl;
    	else cout<<"Um_nik"<<endl;
    }
    else 
    {
    	if(ans % 2 == 0) cout<<"Um_nik"<<endl;
    	else cout<<"Petr"<<endl;
    }
	return 0;
}