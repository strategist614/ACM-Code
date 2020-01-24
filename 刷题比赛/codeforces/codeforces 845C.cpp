#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node
{
	int l;
	int r;
}a[N];
bool cmp(node a,node b)
{
	if(a.l == b.l) 
	return a.r < b.r;
	return a.l < b.l;
}
int main ()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+n+1,cmp);
    int pos = 0;
    int _ = 0;
    int __ = 0;
    //cout<<_<<" "<<__<<endl;
    for(int i = 1;i<=n;i++)
    {
    	if(a[i].r <= a[i+1].l )
    	{
    		//cout<<1;
    		_ = a[i].r;
    		__ = a[i+1].r;
    		//cout<<_<<" "<<__<<endl;
    		for(int j = i + 1;j <= n;j++)
    		{
    			//cout<<j<<endl;
    			//cout<<a[j+1].l<<endl;
    			if(j == n) break;
    			if(_ >= a[j+1].l && __ >= a[j+1].l)
    			{
    				cout<<"NO"<<endl;
    				return 0 ;
    			}
    			else 
    			{
    				if(abs(_ - a[j+1].l) <= abs(__ - a[j+1].l)) _ = a[j+1].r;
    				else __ = a[j+1].r;
    			}
    		}
    	}
    }
    //cout<<_<<" "<<__<<endl;
    cout<<"YES"<<endl;
	return 0 ;
}
/*
3
1 2
2 3
2 4
*/
/*
3
1 2
2 3
4 5
*/

