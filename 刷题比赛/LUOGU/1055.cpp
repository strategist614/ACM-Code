#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main ()
{
	string s;
	cin>>s;
    for(int i = 0;i<s.size();i++)
      if(s[i] >= '0' && s[i] <= '9' || s[i] == 'X') v.push_back(s[i]);
    int ans = 0;
    for(int i = 0;i < v.size()-1;i++)
    {
       ans += (i+1) * (v[i]-'0');
    }
    if(ans % 11 == v[v.size()-1] - '0' || (ans % 11 == 10 && v[v.size()-1] == 'X')) cout<<"Right"<<endl;
    else 
    {
       for(int i = 0;i < s.size()-1;i++) cout<<s[i];
       if(ans % 11 != 10) cout<<ans%11<<endl;
       else cout<<'X'<<endl;
    }	
	return 0 ;
}
/*
0-010-23232-X
*/