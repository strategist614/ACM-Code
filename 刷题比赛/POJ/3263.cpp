#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int N = 1e4+5;
int c[N];
int sum[N];
map<pair<int,int>,bool > mp;
int main ()
{
	int n,i,h,r;
	cin>>n>>i>>h>>r;
	memset(c,0,sizeof(c));
	memset(sum,0,sizeof(sum));
	while(r--)
	{
       int l,r;
       cin>>l>>r;
       if(l > r) swap(l,r);
       if(mp[make_pair(l,r)]) continue;
       c[l+1]--;
       c[r]++;
       mp[make_pair(l,r)] = true;
	}
	for(int i= 1;i<=n;i++)
		sum[i] = sum[i-1]+c[i];
    for(int i=1;i<=n;i++)
    	printf("%d\n",h+sum[i]);
	return 0;
}