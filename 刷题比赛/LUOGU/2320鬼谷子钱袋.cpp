#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
int main ()
{
	int n;
	cin>>n;
	int ans = 0;
	while(n)
	{
		v.push_back((n+1)>>1);
		n >>= 1;
		ans++;
	}
	cout<<ans<<endl;
	for(int i= v.size() - 1;i>=0;i--)
		cout<<v[i]<<" ";
	return 0 ;
}