/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 0x7fffffff;
int a[N];
set<pair<int,int>> s;
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    s.insert(make_pair(a[1],1)); 
    for(int i= 2;i<=n;i++)
    {
    	set<pair<int,int>>::iterator it = s.lower_bound(make_pair(a[i],0));
    	set<pair<int,int>>::iterator ib = it;
        if(it != s.begin()) it--;
        if(ib == s.end()) ib--;
        int prev = abs((*it).first-a[i]);
        int Next = abs((*ib).first-a[i]);
        if(prev <= Next) cout<<prev<<" "<<(*it).second<<endl;
        else cout<<Next<<" "<<(*ib).second<<endl;
        s.insert(make_pair(a[i],i));
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0 ;
}