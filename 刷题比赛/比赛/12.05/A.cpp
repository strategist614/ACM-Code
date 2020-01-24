#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005];
int judge(int x,int y,int z)
{
	if(x+y > z && y + z > x && x +z > y) return 1;
	else return 0;
}
int main ()
{
   int n;
   while(scanf("%d",&n) != EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int flag = 0;
		sort(a+1,a+n+1);      
		for(int i=n;i>=1;i--){
			if(a[i]<a[i-1]+a[i-2]){
				flag = 1;
			    printf("%d\n",a[i]+a[i-1]+a[i-2]);
				break;
			}
		} 
		if(!flag) printf("-1\n");
	}
	return 0 ;
}