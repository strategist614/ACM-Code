#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
	stack<int> s;
    int ans = 0;
	for(int i= 1;i<=n;i++)
	{
       if(s.empty() || s.top() > a[i]) s.push(a[i]);
       else
       {
       	  ans += a[i]-s.top();
       	  while(s.size() && s.top() > a[i]) s.pop();
       	  s.push(a[i]);
       } 
	}
	cout<<ans+a[1]<<endl;
	return 0;
}