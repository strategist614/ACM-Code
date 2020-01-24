/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main ()
{  
    int n,m;
    int cas = 0;
    while(scanf("%d",&n)!=EOF && n)
    {
    	//if(n == 0) break;
    	if(cas++) 
    	{
    		cout<<endl;
    	}
    	map<int,pair<int,int>> mp;
        scanf("%d",&m);
        int t = m * n * (n-1)/2;
    	for(int i =1;i<=t;i++)
    	{
    		int ox,px;
    		char o[20],p[20];
    		cin>>ox>>o;
    		cin>>px>>p;
    		if(o[0] == 'r' && p[0] == 'r') continue;
    		else if(o[0] == 'r' && p[0] == 'p')
    		{
    			mp[ox].second++;
    			mp[px].first++;
    		}
    		else if(o[0] == 'r' && p[0] == 's')
    		{
    			mp[ox].first++;
    			mp[px].second++;
    		}
    		else if(o[0] == 'p' && p[0] == 'p') continue;
    		else if(o[0] == 'p' && p[0] == 'r')
    		{
    			mp[ox].first++;
    			mp[px].second++;
    		}
    		else if(o[0] == 'p' && p[0] == 's')
    		{
    			mp[ox].second++;
    			mp[px].first++;
    		}
    		else if(o[0] == 's' && p[0] == 's') continue;
    		else if(o[0] == 's' && p[0] == 'p')
    		{
    			mp[ox].first++;
    			mp[px].second++;
    		}
    		else if(o[0] == 's' && p[0] == 'r')
    		{
               mp[ox].second++;
               mp[px].first++;
    		}
    	}
    	for(int i= 1;i<=n;i++)
    	{
           double ans = 0.0;
           if(!mp[i].first && !mp[i].second) 
           {
           	 printf("-\n");
           	 continue;
           }
           ans = (double)mp[i].first/(mp[i].first+mp[i].second);
           printf("%.3f\n",ans);
    	}
    } 	 
	return 0 ;
}
