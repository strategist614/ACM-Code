/*
#include<bits/stdc++.h>
using namespace std;
set<int> s;
int vis[1005];
int main ()
{
	int a[7];
	int ans = 0;
	for(int i= 1;i<=6;i++) scanf("%d",&a[i]);
    for(int a1 = 0;a1<=a[1];a1++)
    	for(int a2 =0;a2<=a[2];a2++)
           for(int a3 = 0;a3<=a[3];a3++)
           	  for(int a4 = 0;a4 <= a[4];a4++)
           	  	for(int a5 = 0;a5 <= a[5];a5++)
           	  		for(int a6 = 0;a6<=a[6];a6++)
           	  		{
           	  			int tmp = a1*1 + a2*2+a3*3 + a4*5+a5*10+a6*20;
           	  		    if(tmp == 0) continue;
           	  		    if(!vis[tmp]) 
           	  		    {
                           vis[tmp] = 1;
                           ans++;
           	  		    }
           	  		}
    printf("Total=%d\n",ans);
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int a[7];
int ans[1010];
int b[7]={0,1,2,3,5,10,20};
void dfs(int now,int weight)
{
	ans[weight]  =1;
	for(int i= now;i<=6;i++)
	{
		if(a[i])
		{
			a[i]--;
			dfs(i,weight+b[i]);
			a[i]++;
		}
	}
}
int main ()
{
	int _ = 0;
    for(int i = 1;i<=6;i++) cin>>a[i];
    dfs(1,0);
    for(int i =1;i<=1000;i++)
    {
         if(ans[i]) _++;  
    }
    cout<<"Total=";
    cout<<_<<endl;
	return 0 ;
}
*/
