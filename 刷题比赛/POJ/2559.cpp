/*
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N];
ll w[N];
ll s[N];
ll n;
int main ()
{
    while(cin>>n && n)
    {
    	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    	ll p ;
        a[n + 1] = p = 0;
        ll ans = 0;
        for(int i = 1;i <= n+1;i++)
        {
        	if(a[i] > s[p])
        	{
        		s[++p] = a[i],w[p] = 1;
        	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        	else 
        	{
              int width = 0; 
              while(s[p] > a[i])
              {
                 width += w[p];
                 ans = max(ans,(ll)width*s[p]);
                 p--;                                                                                                                                                                                                                                                                                                    
              }
              s[++p] = a[i],w[p] = width +1;
        	}
        }
        printf("%lld\n",ans);
    }
	return 0 ;
}
*/
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
const int N = 100010;
int w[N];
int a[N];
int main ()
{
	int n;
    while(cin >> n&& n)
    {
    	stack<int> s;
    	ll ans = 0;
        for(int i= 1;i <= n;i++) scanf("%d",&a[i]);
        a[n + 1] = 0;
        s.push(0);
    	for(int i = 1;i <= n+1;i++)
    	{
    		if(a[i] > s.top())
    		{
    			s.push(a[i]);
    			w[s.size()] = 1;
    		}
    		else 
    		{
               int width = 0;
               while(s.top() > a[i])
               {
               	  width += w[s.size()];
               	  ans = max(ans,(ll)width*s.top());
               	  s.pop();
               }
               s.push(a[i]);
               w[s.size()] = width + 1;
    		}
    	}
      cout<<ans<<endl;
    }
 	return 0 ;
}