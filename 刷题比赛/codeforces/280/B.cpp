/*
#include<bits/stdc++.h>
using namespace std;
int a[1005];
std::vector<double> ansv;
int main()
{
	int n,l;
	cin>>n>>l;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<n;i++)
    {
    	double tmp = (double)(a[i+1] - a[i])/2.0;
    	ansv.push_back(tmp);
    }
    double cnt1 = (double)l - a[n];
    double cnt2 = (double)a[1] - 0;
    ansv.push_back(cnt1);
    ansv.push_back(cnt2);
    sort(ansv.begin(),ansv.end());
    printf("%.9f\n",ansv[ansv.size()-1]);
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int a[1005];
std::vector<int> v;
std::vector<int> ans;
int n,l;
int cal(int x)
{
	if(x < a[1] - 0) return 0;
	if(x < n - a[n]) return 0;
    for(int i = 0;i<v.size();i++)
    {
    	if(2 * x < v[i]) return 0;
    }
    return 1;
}
int main ()
{
	cin>>n>>l;
	for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<n;i++) {v.push_back(a[i+1]-a[i]);ans.push_back(a[i+1]-a[i]);}
    ans.push_back(a[1] - 0);
    ans.push_back(n-a[n]);
    sort(ans.begin(),ans.end());
    double l = 0.0;
    double r = ans[ans.size()-1]/2.0;
	for(int i = 0;i<100;i++)
    {
    	double mid = (l + r)/2.0;
        if(cal(mid)) r = mid;
        else l = mid+1; 
    }
    printf("%.9f\n",l);
	return 0 ;
}