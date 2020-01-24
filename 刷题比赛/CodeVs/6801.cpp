#include<bits/stdc++.h>
using namespace std;
std::vector<char> v;
std::vector<char> _v;
int main ()
{
	string _,__;
	cin>>_;
	cin>>__;
	int ans = 0;
    for(int i= 0;i<__.size();i++)
    {
    	if(__[i] == '+') continue;
        if(__[i] == '-' && v.size()) v.pop_back();
        else 
        {
           v.push_back(__[i]);
        }
    }
    for(int i= 0;i<v.size();i++)
    {
    	if(v[i] != '-')
    		_v.push_back(v[i]);
    }
    if(_v.size() != _.size()) {
    	cout<<"NO"<<endl;
    	return 0;
    }
    else 
    {
    	int pos = 0;
    	for(int i =0;i<_v.size();i++)
    	{
            if(_v[i] != _[i]) {ans++,pos = i;}
    	}
    	if(ans == 0) 
    	{
    		cout<<"YES"<<endl;
    		return 0;
    	}
    	if(ans != 1) {cout<<"NO"<<endl;return 0 ;}
    	else
    	{
    		cout<<"NO"<<endl;
    		cout<<pos+1<<endl;
    		return 0;
    	}
    }
	return 0 ;
}