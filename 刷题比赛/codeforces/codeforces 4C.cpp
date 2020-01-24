#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main () 
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++)
    {
    	string tmp;
    	cin>>tmp;
    	if(mp[tmp] == 0) cout<<"OK"<<endl;
    	else cout<<tmp<<mp[tmp]<<endl;
    	mp[tmp]++;
    }
	return 0 ;
}