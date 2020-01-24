#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	while(n--)
	{
	int a,b,c;
	cin>>a>>b>>c;
	if(a > c) 
	{
		cout<<c<<endl;
		continue;
	}
	long long _ = b / c;
	_ += 1;
	long long __ = _ * c;
	cout<<__<<endl;
}
	return 0 ;
}