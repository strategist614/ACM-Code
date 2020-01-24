/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
char a[36];
struct node 
{
	char str[36];
	int s;
};
char aim[36] = {
	11,12,13,14,15,16,17,1,
    21,22,23,24,25,26,27,1,
    31,32,33,34,35,36,37,1,
    41,42,43,44,45,46,47,1
};
//map<string,int> mp;
void bfs()
{
	unordered_map<string,int> mp;
	queue<node> q;
	node tmp;
	strcpy(tmp.str,a);
    mp[tmp.str] = 1;
    tmp.s = 0;
    q.push(tmp);
    while(!q.empty())
    {
    	node v = q.front(),_;
    	q.pop();
    	if(strcmp(v.str,aim) == 0)
    	{
           cout<<v.s<<endl;
           return ;
    	}
    	for(int i = 1;i<32;i++)
    	{
    		if(v.str[i] ==  1 && v.str[i-1] != 1 && v.str[i-1]%10 != 7)
    		{
    		   _ = v;	
               for(int j= 0;j<32;j++)
               	{
               		if(_.str[i-1] + 1== _.str[j])
               		{
               			_.str[i] = _.str[j];
               			_.str[j] = 1;
               			break;
               		}
               	}
               	_.s ++;
               	if(!mp[_.str])
               	{
               		mp[_.str] = 1;
               		q.push(_);
               	} 
    		}
    	}
    }
    cout<<-1<<endl;
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int k = 0;
    	for(int i= 1;i <= 4;i++)
    	{
    	   a[k++] = i * 10 + 1;
    	   for(int j = 1;j <= 7;j++)
    	   {
    	   	  int tmp;
    	   	  cin>>tmp;
    	   	  a[k] = tmp;
    	   	  if(tmp % 10 == 1)
    	   	  	a[k] = 1;
    	   	  k++;
    	   }
    	}
    	bfs();
    }
	return 0 ;
}