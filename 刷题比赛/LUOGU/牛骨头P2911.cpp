#include<bits/stdc++.h>
using namespace std;
int vis[100];
int main ()
{
	int s1,s2,s3;
	cin>>s1>>s2>>s3;
	int ans = 0;
	int tmp = 0;
	for(int i = 1;i<=s1;i++)
		for(int j = 1;j<=s2;j++)
			for(int k = 1;k<=s3;k++)
			{
				int tmp = i+j+k;
				vis[tmp]++;
			}
    for(int i = 1;i<=100;i++)
    {
    	if(vis[i] > tmp)
    		{
    			ans = i;
    			tmp = vis[i];
    		}
    }
    cout<<ans<<endl;
	return 0 ;
}