/*
#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
map<int,int>::iterator it;
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
       int x;
       cin>>x;
       mp[x]++;
	}
	int ans = 0;
	int maxn = 0;
    for(it = mp.begin();it != mp.end();it++)
    {
    	if(it->second > maxn)
    	{
    		maxn = it->second;
    		ans = it->first;
    	}
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
//摩尔投票法
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int ans = 0;
	int count = 0;
	for(int i= 1;i<=n;i++)
	{
		int x;
		cin>>x;
       if(count == 0)
       {
       	   ans = x;
       	   count = 1;
       }
       else 
       {
       	if(ans == x) count++;
       	else count--;
       }
	}
	cout<<ans<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int a[2000];
int main()
{
	int n;
	cin>>n;
	int numa = 0,numb = 0;
	int cnta = 0,cntb = 0;
	for(int i= 1;i<=n;i++)
    {
       cin>>a[i];
       if(a[i] == numa) cnta++;
       else if(a[i] == numb) cntb++;
       else if(cnta == 0) {numa = a[i];cnta = 1;}
       else if(cntb == 0) {numb = a[i];cntb = 1;}
       else {cnta--;cntb--;}
    }
    int ansa = 0,ansb =0;
    for(int i =1;i<=n;i++)
    {
    	if(a[i] == numa) ansa++;
    	if(a[i] == numb) ansb++;
    }    
    if(ansa >= n/3) cout<<numa<<endl;
    if(ansb >= n/3) cout<<numb<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int cnt[33];
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j= 0;(1<<j)<=x;j++)
		{
			if((1<<j) & x) cnt[j]++;
		}
	}
	int ans = 0;
	for(int i = 0;i<=32;i++)
	{
		if(cnt[i] > n/2)
			ans += 1 << i;
	}
	cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
int cnt[33];
int main ()
{
    int n;
    read(n);
    for(int i =1;i<=n;i++)
    {
        int x;
        read(x);
        bitset<32> s(x);
        for(int i= 0;(1<<i)<=x;i++)
        {
            if(s[i] == 1)
                cnt[i]++;
        }
    }
    int ans = 0;
    for(int i= 0;i<=32;i++)
    {
        if(cnt[i] > n/2)
            ans += 1 << i;
    }
    cout<<ans<<endl;
    return 0 ;
}