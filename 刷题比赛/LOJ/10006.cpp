#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main ()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    int ans = 0;
    int tmp = 0;
    for(int i = 1;i <= n;i++)
    {
    	tmp += a[i];
    	if(tmp > m)
        {
        	tmp = a[i];
        	ans++;
        }
        if(i == n)
        {
        	if(tmp <= m) ans++;
        	break;
        }
    }
    printf("%d\n",ans);
	return 0 ;
}