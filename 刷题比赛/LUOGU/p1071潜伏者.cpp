#include<bits/stdc++.h>
using namespace std;
int vismi[27],visyu[27];
int a[27],b[27];
map<int,int>mp;
map<char,char>ma;
int main ()
{
    string smi,syu,sb;
    cin>>smi>>syu>>sb;
    for(int i= 0;i<smi.size();i++)
    	vismi[smi[i]-'A'] = 1;
    for(int i= 0;i<syu.size();i++)
    	visyu[syu[i]-'A'] = 1;
    for(int i = 0;i < 26;i++)
    {
        if(vismi[i] == 1 && visyu[i] == 0) 
        {
        	cout<<"Failed"<<endl;
        	return 0 ;
        }
    }
    for(int i= 0;i<smi.size();i++)
    {
       int x = smi[i]-'A'+1;
       int y = syu[i]-'A'+1;
       if(mp[x] != 0) 
       {
       	 if(mp[x] == y) continue;
       	 else 
       	 cout<<"Failed"<<endl;
       	 return 0;
       }
       else mp[x] = y;
    }
    int len = 0;
    for(int i= 0;i<smi.size();i++)
    {
    	if(!a[smi[i]-'A'+1] && !b[syu[i]-'A'+1])
    	{
    		a[smi[i]-'A'+1] = b[syu[i]-'A'+1] = 1;
    		len++;
    	}
    }
    if(len!=26)
    {
    	cout<<"Failed"<<endl;
    	return 0;
    }
    for(int i= 0;i<smi.size();i++)
    {
        ma[smi[i]] = syu[i];
    }
    for(int i= 0;i<sb.size();i++)
    	cout<<ma[sb[i]];
	return 0 ;
}