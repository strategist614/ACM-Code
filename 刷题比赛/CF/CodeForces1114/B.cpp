#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node 
{
	int x;
	int id;
}a[N];
bool cmp1(node a,node b)
{
	return a.x > b.x;
}
bool cmp2(node a,node b)
{
	return a.id < b.id;
}
std::vector<node> v;
int main ()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i =1;i<=n;i++) {cin>>a[i].x;a[i].id = i;}
    sort(a+1,a+n+1,cmp1);
    for(int i= 1;i<=m*k;i++)
    {
       node tmp;
       tmp.x = a[i].x;
       tmp.id = a[i].id;
       v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp2);
    long long ans = 0;
    for(int i= 0;i<v.size();i++)
            ans += v[i].x;
    cout<<ans<<endl;
    std::vector<int> d(k-1);
    for(int i= 0;i < k-1;i++)
    {
    	d[i] = v[(i+1)*m-1].id; 
    }
    for(auto p : d)
    {
    	cout<<p<<" ";
    }
	return 0 ;
}