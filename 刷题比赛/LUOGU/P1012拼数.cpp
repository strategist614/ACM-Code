#include<bits/stdc++.h>
using namespace std;
std::vector<string> v;
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main ()
{
	int n;
	cin>>n;
	string s;
	for(int i= 1;i<=n;i++)
	{
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i= 0;i<v.size();i++)
		cout<<v[i];
	return 0 ;
}