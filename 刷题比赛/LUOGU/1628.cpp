#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
string k,a[N];
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    	cin>>a[i];
    cin>>k;
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)
    {
    	if(a[i].find(k) == 0) cout<<a[i]<<endl;
    }
	return 0 ;
}