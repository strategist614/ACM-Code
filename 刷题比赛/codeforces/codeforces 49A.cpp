#include<bits/stdc++.h>
using namespace std;
vector<char> v;
char a[] = {'a','e','i','o','u','y'};
int main ()
{
	string s;
    getline(cin,s);
    v.push_back('\0');
    for(int i = 0;i<s.size();i++)
    {        
    	if(isalpha(s[i])) s[i] = tolower(s[i]),v.push_back(s[i]);
    }
    int size = v.size()-1;
    if(v[size] == a[0] || v[size] == a[1] || v[size] == a[2] || v[size] == a[3] || v[size] == a[4] || v[size] == a[5])
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;	
	return 0 ;
}