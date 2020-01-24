#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,string>> mp;
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i =1;i<=n;i++) 
	{
       int x;
       string s;
       cin>>x>>s;
       mp[i] = make_pair(x,s);
	}
	int _ = 0;
	string ans;
	for(int i = 1;i <= m;i++)
	{
		int a,s;
		cin>>a>>s;
		if(i == 1)
		{
		   _ = 1;
           auto tmp = mp[_];
           if(a == 0)
           {
              if(tmp.first == 0)
              {
                 _ -= s;
                 if(_ <= 0) _ += n;
                 ans = mp[_].second;
              }
              else 
              {
                _ += s;
                if(_ > n) _ -= n;
                ans = mp[_].second;
              }
           }
           else 
           { 
              if(tmp.first == 0)
              {
                 _ += s;
                 if(_ > n) _ -= n;
                 ans = mp[_].second;
              }
              else 
              {
              	_ -= s;
              	if(_ <= 0) _ += n;
              	ans = mp[_].second;
              }
           }  
		}
		else 
		{
           auto tmp = mp[_];
           if(a == 0)
           {
              if(tmp.first == 0)
              {
                 _ -= s;
                 if(_ <= 0) _ += n;
                 ans = mp[_].second;
              }
              else 
              {
                _ += s;
                if(_ > n) _ -= n;
                ans = mp[_].second;
              }
           }
           else 
           { 
              if(tmp.first == 0)
              {
                 _ += s;
                 if(_ > n) _ -= n;
                 ans = mp[_].second;
              }
              else 
              {
              	_ -= s;
              	if(_ <= 0) _ += n;
              	ans = mp[_].second;
              }
           }  
		}
	} 
	cout<<ans<<endl;
	return 0 ;
}