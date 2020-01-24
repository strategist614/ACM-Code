#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int ans[N];
int b[N];
multiset<int> s;
multiset<int>::iterator it;
int main ()
{
	int n,m;
    cin>>n>>m;
	for(int i =1;i<=n;i++) cin>>a[i];
	for(int i =1;i<=m;i++) cin>>b[i];
	reverse(a+1,a+n+1);
    ans[1] = 1;
    s.insert(a[1]);
    for(int i = 2;i<=n;i++)
    {
        int _ = 0;
        if((it = s.find(a[i])) == s.end()) _ = 1;
        s.insert(a[i]);
        ans[i]= ans[i-1]+_;
     }
     for(int i =1;i<=m;i++) cout<<ans[n-b[i]+1]<<endl;
	return 0 ;
}

