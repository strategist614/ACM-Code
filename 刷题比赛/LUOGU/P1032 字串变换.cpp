#include<bits/stdc++.h>
using namespace std;
const int aim = 10;
const int N = 7;
string st,ed;
string yuan[N];
string xian[N];
int n;
map<string,int> mp;
struct node 
{
	string s;
	int t;
};
string trans(const string &str,int i,int j)
{
	string ans = "";
	if(i + yuan[j].size() > str.size())
		return ans;
	for(int k = 0;k<yuan[j].size();k++)
		if(str[i+k] != yuan[j][k])
			return ans;
	ans = str.substr(0,i);
	ans += xian[j];
	ans += str.substr(i+yuan[j].size());
	return ans;
}
void bfs()
{
   queue<node> q;
   node tmp;
   tmp.s = st;
   tmp.t = 0;
   q.push(tmp);
   mp[st] = 1;
   while(!q.empty())
   {
      node v = q.front(),_;
      q.pop();
      if(v.s == ed)
      {
      	if(v.t > 10 || v.t == 0)
      		cout<<"NO ANSWER!"<<endl;
      	else cout<<v.t<<endl;
      	return;
      }
      for(int i= 0;i<v.s.size();i++)
      {
      	for(int j= 0;j<n;j++)
      	{
      	   string tmp = trans(v.s,i,j);
           if(tmp != "" && !mp[tmp])
           {
           	  mp[tmp] = 1;
           	  _.s = tmp;
           	  _.t = v.t+1;
           	  q.push(_);
           }
      	}
      }
   }
   cout<<"NO ANSWER!"<<endl;
}
int main ()
{
    cin>>st>>ed;
    while(cin>>yuan[n]>>xian[n])
    	n++;
    bfs();
	return 0 ;
}