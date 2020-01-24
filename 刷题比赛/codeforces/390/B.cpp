#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
   ll x;
   ll y;	
}a[100005];
int main ()
{
	int n;
	cin>>n;
	long long sum = 0;
	for(int i = 1;i<=n;i++) cin>>a[i].x;
    for(int i = 1;i<=n;i++) cin>>a[i].y;
    for(int i = 1;i<=n;i++)
    {
    	if(a[i].x * 2 >= a[i].y && a[i].y >=2) 
    	{
           ll tmp = a[i].y / 2;
           ll cnt = a[i].y - tmp;
           sum += (long long)(tmp * cnt);
    	}
    	else
    	{
    		sum -= 1;
    	}
    }
    cout<<sum<<endl;
	return 0 ;
}