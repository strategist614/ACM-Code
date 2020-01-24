/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];
int b[N];
std::vector<ll> v;
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i];
    for(int i =1;i<=n;i++) cin>>b[i];
    v.push_back(0);
    for(int i =1;i<=n;i++)
      for(int j= 1;j<=n;j++)
      {
      	 v.push_back(a[i]+b[j]);
      } 	
    sort(v.begin(),v.end());
    for(int i =1;i<=n;i++)
    	cout<<v[i]<<" ";
	return 0 ;
}
50分
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct node
{
	ll s,b;
	node(ll s,ll b):s(s),b(b){}
	bool operator < (const node & a) const 
	{
		return s > a.s;
	}
};
int A[N];
int B[N];
std::vector<ll> v;
int main()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>A[i];
    for(int i= 1;i<=n;i++) cin>>B[i];
    priority_queue<node> q;
    for(int i= 1;i<=n;i++)
      q.push(node(A[i]+B[1],1));
    for(int i= 1;i <= n;i++)
    {
        node a = q.top();
        q.pop();
        v.push_back(a.s);
        int b = a.b;
        if(b+1 <= n){q.push(node(a.s-B[b]+B[b+1],b+1));}
    }
    for(int i =0;i<v.size();i++)
    	cout<<v[i]<<" ";
	return 0 ;
}