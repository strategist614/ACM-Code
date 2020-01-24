#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int c,v0,v1,a,l;
	cin>>c>>v0>>v1>>a>>l;
	int day = 1;
	int va = v0;
	int cnt = v0;
	while(va < c)
	{
       cnt = min(v1,cnt+a);
       va += cnt-l;
       day++;
	}
	cout<<day<<endl;
	return 0 ;
}