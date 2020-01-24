/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;
struct node
{
   ll x;
   ll y;	
}a[N];
ll _a[N];
ll _b[N];
ll c(ll n)
{
	ll ans =0 ;
	if(n < 2) return 0;
	else 
    ans = (ll)(n-1)*(ll)n/2;
	return ans; 
}
std::vector<pair<ll,ll>> v;
int main ()
{
	int n,ma,mb;
	cin>>n;
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		_a[i] = a[i].x;
		_b[i] = a[i].y;
		v.push_back(make_pair(a[i].x,a[i].y));
	}
	ll _cnt = 1;
	ll _ans = 0;
	sort(v.begin(),v.end());
	for(int i =0;i<v.size();i++)
	{
	    if(_cnt > 1 && i == v.size() - 1) {_ans += c(_cnt);break;}
        if(v[i].first == v[i+1].first && v[i].second == v[i+1].second)
        {
        	_cnt++;
        }
        else 
        {  
            _ans += c(_cnt);
            _cnt = 1;
        }
	}
	sort(_a+1,_a+n+1);
	sort(_b+1,_b+n+1);
	int cnta = 1;
	int cntb = 1;
	ll _ = 0;
	ll __ = 0 ;
	for(int i =1;i<=n;i++)
    {
    	if(cnta > 1 && i == n) {_ += c(cnta);break;}
    	if(_a[i] == _a[i+1])
    	{
    		cnta++;
    	}
    	else 
    	{
           _ += c(cnta);
           cnta = 1;
    	}
    }
    for(int i =1;i<=n;i++)
    {
    	if(cntb > 1 && i == n) {__ += c(cntb);break;}
    	if(_b[i] == _b[i+1])
    	{
    	   cntb++;
    	}
    	else 
    	{
    		__ += c(cntb);
    		cntb = 1;
    	}
    }
    cout<<_+__-_ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> ma;
map<int,int> mb;
map<pair<int,int>,int> _m;
map<int,int>::iterator ia,ib;
map<pair<int,int>,int>::iterator im; 
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	ma[a]++;
    	mb[b]++;
    	_m[make_pair(a,b)]++;
    }
    ll ans = 0;
    for(ia = ma.begin();ia != ma.end();ia++)
    	ans += (ll)ia->second*(ll)(ia->second-1)/2;
    for(ib = mb.begin();ib != mb.end();ib++)
    	ans += (ll)ib->second*(ll)(ib->second-1)/2;
    for(im = _m.begin();im != _m.end();im++)
    	ans -= (ll)im->second*(ll)(im->second-1)/2;
    cout<<ans<<endl;
	return 0 ;
}