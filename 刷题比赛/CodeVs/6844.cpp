#include<bits/stdc++.h>
using namespace std;
int main ()
{
	string s;
	cin>>s;
	int li = s[s.size()-1]-'0';
	int si = s[s.size()-2]-'0';
	int ans = si*10+li;
	if(ans % 4 == 0 || ans % 4 == 3) cout<<0<<endl;
	else cout<<1<<endl;
	return 0 ;
}