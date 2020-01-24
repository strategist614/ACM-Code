#include<bits/stdc++.h>
using namespace std;
const int N = 35000+5;
int c[N];
int n;
void add(int x,int y)
{
	for(;x <= N;x += x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x -= x&-x) ans += c[x];
	return ans; 
}
int ans[N];
int main()
{
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    memset(c,0,sizeof(c));
    for(int i = 1;i<=n;i++)
    {
    	int x,y;
    	scanf("%d %d",&x,&y);
        ans[ask(x+1)]++;
        add(x+1,1);
    }
    for(int i = 0;i < n;i++) cout<<ans[i]<<endl;
	return 0 ;
}