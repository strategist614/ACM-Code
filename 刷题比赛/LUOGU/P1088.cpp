#include<bits/stdc++.h>
using namespace std;
int a[10005];
int ans[10005];
int main ()
{
	int n;
	cin>>n;
    int m;
    cin>>m;
    for(int i= 1;i<=n;i++) cin>>a[i];
    while(m--) next_permutation(a+1,a+n+1);
    for(int i= 1;i<n;i++) cout<<a[i]<<" ";
    cout<<a[n]<<endl;
	return 0 ;
}