#include<bits/stdc++.h>
using namespace std;
struct node
{
   int x;
   int y;	
}a[100005];
set<int> s1,s2;
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
       cin>>a[i].x>>a[i].y;
	   s1.insert(a[i].x);
	   s2.insert(a[i].y);
	}
    cout<<min(s1.size(),s2.size())<<endl;
	return 0 ;
}