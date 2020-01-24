#include<bits/stdc++.h>
using namespace std;
int main ()
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size() != s2.size()) {cout<<"NO"<<endl; return 0;}
	for(int i= 0;i<s1.size();i++)
	{
		if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
		{
            if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u') continue;
            else {
            	cout<<"NO"<<endl;
            	return 0;
            }
		}
		else 
		{
			if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u') 
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0 ;
}