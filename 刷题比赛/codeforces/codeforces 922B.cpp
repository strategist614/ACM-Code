#include<bits/stdc++.h>
using namespace std;
bool solve(int x,int y,int z)
{
	if(x+y > z && x+z > y && y+z > x) return 1;
	else return 0;
}
int main ()
{
	int n;
	cin>>n;
	int ans = 0;
	for(int i =1;i<=n;i++)
		for(int j =i;j<=n;j++)
		{
			int c = i^j;
            if(c >= j && c <= n)
            {
            	if(solve(i,j,c))
                {
                	ans++;
                }
            }
		}
    cout<<ans<<endl;
	return 0 ;
}