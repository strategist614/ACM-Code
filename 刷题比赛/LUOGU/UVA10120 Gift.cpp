/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int vis[N];
int n,m;
int dfs(int x,int len)
{
	if(x <= 0 || x > n) return 0;
	if(x == m) return 1;
	if(dfs(x+len,len+2)) return 1;
	if(dfs(x-len,len+2)) return 1;
	return 0;
}
int main ()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    	if(n == 0 && m == 0)  break;
        memset(vis,0,sizeof(vis));
    	if(n >= 49) 
    	{
    		cout<<"Let me try!"<<endl;
            continue;
    	}
    	if(dfs(1,3))
    	{
    		cout<<"Let me try!"<<endl;
    	}
    	else cout<<"Don't make fun of me!"<<endl;
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int vis[N];
int n,m;
int flag = 0;
void dfs(int x,int len)
{
	if(x <= 0 || x > n) return ;
	if(x == m) {flag = 1;return;}
    dfs(x+len,len+2); 
    dfs(x-len,len+2); 
    return;
}
int main ()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    	if(n == 0 && m == 0)  break;
        flag = 0;
        memset(vis,0,sizeof(vis));
    	if(n >= 49) 
    	{
    		cout<<"Let me try!"<<endl;
            continue;
    	}
    	dfs(1,3);
    	if(flag)
    	{
    		cout<<"Let me try!"<<endl;
    	}
    	else cout<<"Don't make fun of me!"<<endl;
    }
	return 0 ;
}