/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	scanf("%d",&n);
	int ans =  0;
	for(int i = 1;i<=n;i++)
	{
       ans += n/i;
	}
	cout<<ans<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	scanf("%d",&n);
	int ans =  0;
	int j ;
	for(int i = 1;i<=n;i = j +1)
	{
       j = n/(n/i);
       ans += (j-i+1)*(n/i);
	}
	cout<<ans<<endl;
	return 0 ;
}
整数分块
*/