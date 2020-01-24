#include<bits/stdc++.h>
using namespace std;
int a[150];
map<int,int> mp;
bool cmp(int a,int b)
{
	return a > b;
}
int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i];
    int x = *max_element(a+1,a+n+1);
    int y = 0;
    for(int i =1;i<=n;i++)
    {
        if(x % a[i] == 0 && !mp[a[i]])
        {
        	mp[a[i]] = 1;
        }
        else y = max(y,a[i]);
    }
    cout<<x<<" "<<y<<endl;
	return 0 ;
}