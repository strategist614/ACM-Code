//a ^ b ^ b = a
//偶数次异或是0，奇数次异或是1
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node
{
	int s;
	int e;
	int d;
}a[N];
std::vector<long long> v[N];
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i= 1;i<=n;i++)
	      cin>>a[i].s>>a[i].e>>a[i].d;
	    int res = 0;
	    for(int i= 1;i<=n;i++)
	    {
	    	for(int j = a[i].s;j<=a[i].e;j+=a[i].d)
                res ^= j;
	    }
	    int sum = 0;
	    for(int i =1;i<=n;i++)
	    {
	    	if(res >= a[i].s && res <= a[i].e && (res-a[i].s) % a[i].d == 0)
	    		sum++;
	    }
	    if(res) cout<<res<<" "<<sum<<endl;
	    else cout<<"There's no weakness."<<endl;
	}
	return 0 ;
}