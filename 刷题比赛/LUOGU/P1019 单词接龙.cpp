#include<bits/stdc++.h>
using namespace std;
int n;
string word[25];
int ans = 0;
int vis[25];
int check(string s,string n,int pos)
{
	int lens = s.size();
	for(int i = 0;i < pos;i++)
	{
		if(n[i] != s[lens-pos+i])
			return 0;
	}
	return 1;
}
string add(string s,string n,int pos)
{
   int lens = n.size();
   for(int i =pos;i<lens;i++)
   	s += n[i];
   return s;
}
void dfs(string s)
{
  int len = s.size();
  ans = max(ans,len);
  for(int i= 1;i<=n;i++)
  {
     if(vis[i] >= 2) continue;
     int lens = word[i].size();
     for(int j= 1;j<=lens;j++)
     {
     	if(check(s,word[i],j))
     	{
             string tmp = s;
             tmp = add(tmp,word[i],j);
             if(tmp == s) continue;
             vis[i]++;
             dfs(tmp);
             vis[i]--;
     	}
     }
  }
}
int main ()
{
	cin>>n;
	for(int i= 1;i<=n;i++)
		cin>>word[i];
    string st;
    cin>>st;
    dfs(st);
    cout<<ans<<endl;
	return 0 ;
}