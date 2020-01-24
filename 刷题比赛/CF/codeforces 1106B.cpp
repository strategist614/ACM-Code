#include<bits/stdc++.h>
#define PII pair<int,int>
typedef long long ll;
using namespace std;
const int N = 1e5+5;

int a[N],c[N];

priority_queue<PII,vector<PII>,greater<PII> > q;

ll ans = 0;

int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++) cin>>a[i];
    for(int i= 1;i<=n;i++)
    {
    	cin>>c[i];
    	q.push(make_pair(c[i],i));
    }
    while(m--)
    {
    	    int t,d;
    	    cin>>t>>d;
    	    ans = 0;
    		if(a[t] >= d)
    		{
    		   a[t] -= d;
               ans = (ll)d*c[t];
               cout<<ans<<endl;
    		}
    		else 
    		{
               ans += (ll)a[t] * c[t];
               d -= a[t];
               a[t] = 0;
               while(q.size())
               {
               	  auto tmp = q.top();
               	  q.pop();
               	  int money = tmp.first;
                  int pos = tmp.second;
               	  if(d >= a[pos])
               	  {
               	  	 d -= a[pos];
                     ans += (ll)a[pos]*money;
                     a[pos] = 0;
               	  }
               	  else 
               	  {
               	     a[pos] -= d;
               	     q.push(tmp);
               	     ans += (ll)d*money;
               	     d = 0;
               	  }
               	  if(d == 0) break;
               }
               if(d) ans = 0;
               cout<<ans<<endl;
    		}
    }
	return 0 ;
}