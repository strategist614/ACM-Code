#include<bits/stdc++.h>
using namespace std;
int ans = 0;

int main ()
{
	int n;
	while(cin>>n)
	{
     ans = 0;
	int l = n;
	ans += n;
	while(l >= 3)
	{
		ans += l/3;
		l = l/3+l%3;
	}
	if(l == 2) ans += 1;
    cout<<ans<<endl;
}
	return 0 ;
}