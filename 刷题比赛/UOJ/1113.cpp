#include<bits/stdc++.h>
using namespace std;
const int N = 250005;
struct node
{
	int l;
	int r;
}a[N];
int main ()
{
	int n;
	scanf("%d",&n);
	stack<int> s;
	for(int i= 1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r);
	int ans = 0;
    for(int i =1;i<=n;i++)
	{
       if(s.empty() || s.top() < a[i].r) s.push(a[i].r);
       else 
       {
       	  while(s.size() && s.top() >= a[i].r) 
       	  {
       	  	if(s.top() == a[i].r) ans++;
       	  	s.pop();
       	  }
       	  s.push(a[i].r);
       }
	} 
	printf("%d\n",n - ans);
	return 0 ;
}