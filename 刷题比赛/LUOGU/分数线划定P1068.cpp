#include<bits/stdc++.h>
using namespace std;
struct  node
{
	int k;
	int s;
}a[5005];
bool cmp(node a,node b)
{
	if(a.s == b.s) return a.k<b.k;
	return a.s > b.s;
}
std::vector<pair<int,int>> v;
int main()
{
	int n,m;
	cin>>n>>m;
    for(int i= 1;i<=n;i++) cin>>a[i].k>>a[i].s;
    m = floor(m * 1.5);
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++)
    {
    	if(a[i].s >= a[m].s) v.push_back(make_pair(a[i].k,a[i].s));
    }
    cout<<a[m].s<<" "<<v.size()<<endl;
    for(int i= 0;i<v.size();i++)
    	cout<<v[i].first<<" "<<v[i].second<<endl;
	return 0 ;
}