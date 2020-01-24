#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N],b[N];
set<ll> s;
int main ()
{
	int n;
	cin>>n;
	ll ans= 0;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int tot = 0;
	for(int i =1;i<=n;i++)
	{
       if(i == 1||a[i] !=a[i+1]) b[++tot] = a[i];
	}
	if(tot % 2)
	{
		s.clear();
		int mid = b[(tot+1)/2];
		for(int i= 1;i<=n;i++)
		{
		   if(mid > a[i])
		   s.insert(mid-a[i]);
		   else if(a[i] > mid)
		   s.insert(a[i]-mid); 
		}
		if((int)s.size() == 1 || (int)s.size() == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
	else 
	{
		int mid1 = b[tot/2];
		int mid2 = b[tot/2+1];
		if(mid1 == mid2)
		{
			s.clear();
			for(int i= 1;i<=n;i++)
		    {
		        if(mid1 > a[i])
		        s.insert(mid1-a[i]);
		        else if(a[i] > mid1)
		        s.insert(a[i]-mid1); 
		    }
		if((int)s.size() == 1 || (int)s.size() == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		}
		else 
		{
			set<ll> s1;
			set<ll> s2;
           for(int i= 1;i<=n;i++)
		    {
		        if(mid1 > a[i])
		        s1.insert(mid1-a[i]);
		        else if(a[i] > mid1)
		        s1.insert(a[i]-mid1); 
		    }
		    for(int i= 1;i<=n;i++)
		    {
		        if(mid2 > a[i])
		        s2.insert(mid2-a[i]);
		        else if(a[i] > mid2)
		        s2.insert(a[i]-mid2); 
		    }
		    if((int)s1.size() == 1 || (int)s2.size() == 1 || (int)s1.size() == 0 || (int)s2.size() == 0) cout<<"YES"<<endl;
		    else cout<<"NO"<<endl;
		}
	}
	return 0 ;
} 