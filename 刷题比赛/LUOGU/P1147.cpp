#include<bits/stdc++.h>
using namespace std;
std::vector<pair<int,int>> v;
std::vector<pair<int,int>> ans;
int main ()
{
	int n;
	cin>>n;
	int _ = 2*n;
	for(int i = 2;i<=sqrt(_);i++)
	{
		if(_ % i == 0) 
		{
			v.push_back(make_pair(i,_/i));
		}
	}
	for(int i= 0;i<v.size();i++)
	{
		int _ = v[i].second - v[i].first +1;
		int __ = v[i].second + v[i].first -1;
        if((_ % 2 == 0) &&(__ % 2 == 0))
        {
        	if(_ > __) swap(_,__);
        	ans.push_back(make_pair(_/2,__/2));
        }
    }
    sort(ans.begin(),ans.end());
	for(int i= 0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0 ;
}