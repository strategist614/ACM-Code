#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
std::vector<int> v1;
std::vector<int> v2;
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    int ans = 1e5;
    for(int i= 2;i<=n-1;i++)
    {
        for(int j = i+1;j <= n-1;j++)
        	v1.push_back(a[j+1]-a[j]);
        for(int j =1;j <= i-2;j++)
        	v1.push_back(a[j+1]-a[j]);
        v1.push_back(a[i+1]-a[i-1]);
        sort(v1.begin(),v1.end());
        ans = min(ans,v1[v1.size()-1]);
        v1.clear();
    }
    cout<<ans<<endl;
	return 0 ;
}
