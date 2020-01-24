#include<bits/stdc++.h>
using namespace std;
int a[205];
int b[205];
int sum[6][6]={
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};
int main ()
{
	int n,na,nb;
	cin>>n>>na>>nb;
	for(int i= 0;i<na;i++) cin>>a[i];
	for(int i= 0;i<nb;i++) cin>>b[i];
    int ansa = 0,ansb = 0;
    int _ = 0,__ = 0;
    for(int i= 0;i<n;i++)
	{
       _ = a[i%na];
       __ = b[i%nb];
       ansa+=sum[_][__];
       ansb+=sum[__][_];
	}
	cout<<ansa<<" "<<ansb<<endl;
	return 0 ;
}