/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	long long n;
	cin>>n;
    int ans = 0; 
    for(;n;n>>=1)ans++;
    cout<<ans<<endl; 
    return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	long long n;
	cin>>n;
	int ans = 0;
	while(n)
	{
       n/=2;
       ans++;
	}
	cout<<ans<<endl;
	return 0 ;
}