#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3;
string s;
std::vector<char> v;
int main (){
  cin>>p1>>p2>>p3;
  cin>>s;
  for(int i= 0;i<s.size();i++){
    if(s[i] != '-') v.push_back(s[i]);
    else if((i == 0) || i == s.size()-1 && s[i] == '-') v.push_back('-');
    else if(s[i] == '-' && (s[i-1] == '-' || s[i+1] == '-')) v.push_back('-');
    else if(s[i] == '-')
    {
      if(s[i-1]>=s[i+1] || (s[i-1] < 58 && s[i+1] > 96)) v.push_back('-');
      else if(s[i+1]==s[i-1]+1) continue;
      else 
      {
         int len = (s[i+1]-s[i-1]-1)*p2;
         if(p1 == 3) for(int j= 1;j <= len;j++) v.push_back('*');
         else if(p1 == 1)
         {
         	if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9')
         	{
                for(int j= (s[i-1]-'0'+1);j<(s[i+1]-'0');j++)
                    {
                    	for(int k =1;k<=p2;k++)
                    		v.push_back(j+'0');
                    }
         	}
         	if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z')
         	{
                for(int j= (s[i-1]-'a'+1);j<(s[i+1]-'a');j++)
                {
                	for(int k =1;k<=p2;k++)
                		v.push_back(j+'a');
                }
         	}
         }
         else 
         {
         	if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9')
         	{
                for(int j= (s[i-1]-'0'+1);j<(s[i+1]-'0');j++)
                    {
                    	for(int k =1;k<=p2;k++)
                    		v.push_back(j+'0');
                    }
         	}
         	if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z')
         	{
                for(int j= (s[i-1]-'a'+1);j<(s[i+1]-'a');j++)
                {
                	for(int k =1;k<=p2;k++)
                		v.push_back(j+'a'-32);
                }
         	}
         }
         if(p3 == 2) reverse(v.end()-len,v.end());        
      }
    }
  }
  for(int i= 0;i<v.size();i++)
     cout<<v[i];
  return 0 ;
}