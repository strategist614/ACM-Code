#include<bits/stdc++.h>
using namespace std;
std::vector<string> v;
int main ()
{
    string s;
    int _d = 0;
    while(cin>>s)
    {
     v.clear();
     map<string,int> mp;
     int cnt = 0;
     int flag = 0;
     for(int i = 0;i<s.size();i++)
     {
       if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) flag++;
     }
     if(flag == 0 || s.size() == 0) 
     {
       cout<<"NO"<<endl;
       continue;
     }
     for(int i = 0;i<s.size();i++)
     {
       if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) cnt++;
       else 
       	{
       		string tmp;
       		if(cnt == 0) continue;
       		tmp = s.substr(i-cnt,cnt);
       		cnt = 0 ;
       		if(mp[tmp] >= 1) continue;
       		v.push_back(tmp);
       		mp[tmp]++;
       	}
    }
    if(cnt)
    {
      string _s = s.substr(s.size() - cnt,cnt);
      if(!mp[_s])
      v.push_back(_s);
    } 
    printf("Case %d:\n",++_d);	
    for(int i = 0;i<v.size();i++)
    { 
        cout<<v[i]<<endl;
    }
}
	return 0 ;
}