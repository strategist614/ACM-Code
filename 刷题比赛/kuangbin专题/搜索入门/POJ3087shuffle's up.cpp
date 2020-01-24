#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>

using namespace std;
const int N = 105;
int len = 0;
string s1,s2,s;
struct node
{
	string s1;
	string s2;
	string s;
	int t;
};
node tmp;
void bfs(node tmp)
{
   map<pair<string,string>,int> mp;
   queue<node> q;
   mp[make_pair(s1,s2)] = 1;
   q.push(tmp);
   while(!q.empty())
   {
      node v = q.front(),_;
      q.pop();
      if(v.s == s)
      {
      	cout<<v.t<<endl;
      	return ;
      }
      string st;
      for(int i = 0;i<v.s1.size();i++)
      {
            _.s += v.s2[i];
            _.s += v.s1[i];
      }
      _.s1 = _.s.substr(0,len);
      _.s2 = _.s.substr(len,len*2);
      _.t = v.t+1;
      if(!mp[make_pair(_.s1,_.s2)])
      {
      	mp[make_pair(_.s1,_.s2)]++;
      	q.push(_);
      }
   }
   cout<<-1<<endl;
}
int main ()
{
	int t;
	cin>>t;
	for(int i =1;i<=t;i++)
	{
      cin>>len;
      cin>>s1>>s2;	
      cin>>s;
      tmp.s1 = s1;
      tmp.s2 = s2;
      string s;
      for(int i = 0;i<s1.size();i++)
      {
      	 s += s2[i];
      	 s += s1[i];
      }
      tmp.s = s;
      tmp.t = 0;
      cout<<i<<" ";
      bfs(tmp);
	}
	return 0 ;
}