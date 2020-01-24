/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int a[N];
multiset<int> s1;
multiset<int> s2;
multiset<int>::iterator i1,i2;
int main ()
{
	int n ;
	cin>>n;
	for(int i  =1;i<=n;i++) {cin>>a[i];s1.insert(a[i]);}
    int _ans = 0;
    int ans = 0;
    for(int i = 1;i<=n-1;i++)
    {
       int a;
       cin>>a;
       s2.insert(a);
       if((i1 = s1.find(a)) != s1.end()) s1.erase(i1);
    } 
    for(i1 = s1.begin();i1 != s1.end();i1++) ans = *i1;
    for(int i = 1;i<=n-2;i++)
    {
    	int a;
    	cin>>a;
    	if((i2 = s2.find(a)) != s2.end()) {s2.erase(i2);}
    }
   for(i2 = s2.begin();i2 != s2.end();i2++) _ans = *i2;
    cout<<ans<<endl;
    cout<<_ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	long long sum = 0;
	long long sum1 = 0;
	long long sum2 = 0;
	for(int i =1;i<=n;i++) 
    {
    	int a;
    	cin>>a;
    	sum += a;
    }
    for(int i =1;i<=n-1;i++)
    {
    	int a;
    	cin>>a;
    	sum1 += a;
    }
    for(int i =1;i<=n-2;i++)
    {
    	int a;
    	cin>>a;
    	sum2 += a;
    }
    cout<<sum - sum1<<endl;
    cout<<sum1 - sum2<<endl;
	return 0 ;
}