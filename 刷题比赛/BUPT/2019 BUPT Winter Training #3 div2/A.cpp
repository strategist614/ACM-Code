#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node
{
   long long x;
   long long y;
   int id;
}a[N];
bool cmp(node a,node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool judge(node c)
{
	return (c.x-a[1].x)*(a[2].y-a[1].y)-(c.y-a[1].y)*(a[2].x-a[1].x) != 0;
}
int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++)
    {
    	cin>>a[i].x >>a[i].y;
    	a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 3;i<=n;i++)
    {
    	if(judge(a[i]))
    	{
    		cout<<a[1].id<<" "<<a[2].id<<" "<<a[i].id<<endl;
    		return 0;
    	}
    }
    return 0 ;
}