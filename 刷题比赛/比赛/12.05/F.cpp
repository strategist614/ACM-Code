
#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int l,n;
    	scanf("%d %d",&l,&n);
    	for(int i =1;i<=n;i++) scanf("%d",&a[i]);
    	int minn = 0;
        int maxn = 0;
    	for(int i =1;i<=n;i++) 
    	{ 
              minn = max(minn,min(a[i],l-a[i]));
              maxn = max(maxn,max(a[i],l-a[i]));
    	}
    	printf("%d %d\n",minn,maxn);
    }
	return 0 ;
}
