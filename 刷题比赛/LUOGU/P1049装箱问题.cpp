/*
#include<bits/stdc++.h>
using namespace std;
int va[35];
int f[20005];
int main ()
{
	int v,n;
	cin>>v>>n;
	for(int i= 1;i<=n;i++) cin>>va[i];
	memset(f,0,sizeof(f));
    f[0] = 1;
    for(int i= 1;i<=n;i++)
    {
    	for(int j= v;j >= va[i];j--)
    		f[j] += f[j-va[i]];
    }
    int ans = 0;
    for(int i = v;i >= 0;i--)
    {
    	if(f[i] != 0)
    	{
    		cout<<v-i<<endl;
    		return 0;
    	}
    }
	return 0 ;
}
*/
