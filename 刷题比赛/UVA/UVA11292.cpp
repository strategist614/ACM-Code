#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];
int b[N];
int main ()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!= EOF)
	{
		if(n == 0 && m == 0) break;
        for(int i = 1;i<=n;i++) {scanf("%d",&a[i]);}
        for(int i = 1;i<=m;i++) {scanf("%d",&b[i]);}
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        int i = 1;
        int j = 1;
        ll _ans = 0; 
        while(i <= n&& j <= m)
        {
           if(b[j] >= a[i]) {_ans += b[j];i++;j++;}
           else j++;
        }
        if(i <= n) {cout<<"Loowater is doomed!"<<endl;}
        else cout<<_ans<<endl;
    }
	return 0 ;
}