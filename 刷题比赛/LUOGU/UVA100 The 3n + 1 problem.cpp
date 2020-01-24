#include<bits/stdc++.h>
using namespace std;
int sovle(int n)
{
	int ans = 1;
	while(n != 1)
	{
      if(n % 2) n = 3*n+1;
      else n /= 2;
      ans++; 
	}
	return ans;
}
int tot = 0;
int main ()
{
    int l,r;
    while(cin>>l>>r)
    {
    	int maxn = 0;
    	int flag = 0;
    	if(l > r) swap(l,r),flag = 1;
    	for(int i= l;i<=r;i++)
    		maxn = max(maxn,sovle(i));
    	if(flag) swap(l,r); 
    	cout<<l<<" "<<r<<" "<<maxn<<endl; 
    } 
	return 0 ;
}