#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100],d[100];
int ans = 0;
int n;
void print()
{
	ans++;
	if(ans <= 3)
	{
		for(int i= 1;i <= n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
void dfs(int i)
{
	if(i > n)
	{
		print();  
	    return; 
	}
    for(int j = 1;j <= n;j++)
    {
        if((!b[j]) && (!c[i+j]) &&(!d[i-j+n]))
        {
        	a[i] = j;
        	b[j] = 1;
        	c[i+j] = 1;
        	d[i-j+n] = 1;
        	dfs(i+1);
        	b[j] = 0;
        	c[i+j] = 0;
        	d[i-j+n] = 0;
        }
    }
}
int main ()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	cin>>n;
	dfs(1);
    cout<<ans;
	return 0 ;
}