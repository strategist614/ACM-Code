/*#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
map<pair<char,int>,int> mp1;
map<pair<char,int>,int> mp2;
vector<pair<int,pair<int,int>>> ans;
int main ()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
        int tmp,num;
        char a,b;
        scanf("%d %c %d %c",&tmp,&a,&num,&b);
        if(b == 'r')
        {
        	if(mp2[make_pair(a,num)]) continue;
        	if(mp1[make_pair(a,num)] >= 2) continue;
        	if(a == 'h') 
        	ans.push_back(make_pair(tmp,make_pair(num,1)));
            else 
            ans.push_back(make_pair(tmp,make_pair(num,0)));
            mp2[make_pair(a,num)]++;
        }
        else 
        {
        	if(mp2[make_pair(a,num)]) continue;
        	if(mp1[make_pair(a,num)] >= 2)continue;
        	mp1[make_pair(a,num)]++;
        	if(mp1[make_pair(a,num)] >= 2)
        	{
        		if(a == 'h')
        			ans.push_back(make_pair(tmp,make_pair(num,1)));
        		else ans.push_back(make_pair(tmp,make_pair(num,0)));
        		continue;
        	}
        }
	}
	sort(ans.begin(),ans.end());
	for(int i = 0;i<ans.size();i++)
	{
		int x = ans[i].second.second;
		if(x == 1)
		{
			cout<<s1<<" "<<ans[i].second.first<<" "<<ans[i].first<<endl;
		}
		else 
		{
			cout<<s2<<" "<<ans[i].second.first<<" "<<ans[i].first<<endl;
		}
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
std::vector<int> v1;
std::vector<int> v2;
long long a[200005];
int main ()
{
	int n;
	cin>>n;
    long long ans1 = 0;
    long long ans2 = 0;
    for(int i = 1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i] > 0)
    	{
    		ans1 = (long long)ans1 + (long long)a[i];
    		v1.push_back(a[i]);
    	}
    	else 
    	{
    		ans2 = (long long)ans2 + (long long)abs(a[i]);
    		v2.push_back(-a[i]);
    	}
    }
    if(ans1 > ans2)
    {
    	cout<<"first"<<endl;
    }
    else if(ans1 < ans2)
    {
    	cout<<"second"<<endl;
    }
    else 
    {
    	if(v1.size() > v2.size())
       { 
    	for(int i = v2.size();i<v1.size();i++)
    		v2.push_back(0);
     }
    else 
    {
        for(int i = v1.size();i<v2.size();i++)
           v1.push_back(0);	
    }
    	for(int i = 0;i<max(v1.size(),v2.size());i++)
    	{
             if(v1[i] > v2[i])
             {
             	cout<<"first"<<endl;
             	return 0;
             }
             else if(v1[i] < v2[i])
             {
             	cout<<"second"<<endl;
             	return 0 ;
             }
    	}
        if(a[n]<0) cout<<"second"<<endl;
        else cout<<"first"<<endl;
    }
	return 0 ;
}