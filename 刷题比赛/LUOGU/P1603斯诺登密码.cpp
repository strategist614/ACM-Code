#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main ()
{
	mp["zero"] = 999;
	mp["one"] = 1;
	mp["two"] = 4;
	mp["three"] = 9;
	mp["four"] = 16;
	mp["five"] = 25;
	mp["six"] = 36;
	mp["seven"] = 49;
	mp["eight"] = 64;
	mp["nine"] = 81;
	mp["ten"] = 9999;
    mp["eleven"] = 21;
    mp["twelve"] = 44;
    mp["thirteen"] = 69;
    mp["fourteen"] = 96;
    mp["fifteen"] = 25;
    mp["sixteen"] = 56;
    mp["seventeen"] = 89;
    mp["eighteen"] = 24;
    mp["nineteen"] = 61;
    mp["twenty"] = 999;
    mp["a"] = 1;
    mp["both"] = 4;
    mp["another"] = 1;
    mp["first"] = 1;
    mp["second"] = 4;
    mp["third"] = 9;
    string s;
    std::vector<int> v;
    for(int i= 1;i<=6;i++)
    {
    	cin>>s;
        if(mp[s] == 0) continue;
        else if(mp[s] == 999) v.push_back(0);
        else if(mp[s] == 9999) v.push_back(0);
        else v.push_back(mp[s]);
    }
    sort(v.begin(),v.end());
    int flag = 0;
    for(int i = 0;i<v.size();i++)
    {
       if(flag)
       {
       	 printf("%.2d",v[i]);
       }
       else
       {
       	 if(v[i])
       	 {
       	 	printf("%d",v[i]);
       	 	flag = 1;
       	 }
       }
    }
    if(flag == 0) cout<<0<<endl;
    return 0; 
}