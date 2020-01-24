#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
const ull INF = ~0ULL;
ull ans = INF;
int n;
void dfs(int dep,ull tmp,int num)
{
	if(num > n) return ;
	if(num == n && ans > tmp) {ans = tmp;}
	for(int i = 1;i<=63;i++)
	{
        if(ans / prime[dep] < tmp) break;
        dfs(dep+1,tmp *= prime[dep],num*(i+1));
	}
}
int main ()
{
	cin>>n;
    dfs(0,1,1);
    cout<<ans<<endl;
	return 0 ;
}