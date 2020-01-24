#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int sum = 0;
	int j = 0;
	for(int i = 1;i<=n;i = j+1)
	{
		j = n/(n/i);
		sum += (j-i+1)*(n/i);
	}
	cout<<sum<<endl;
	return 0 ;
}