/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2505;
struct node
{
	int maxn;
	int minn;
}a[N];
bool cmp(node a,node b)
{
	return a.minn > b.minn;
}
struct rec
{
	int spf;
	int num;
}b[N];
int main ()
{
	int c,l;
	cin>>c>>l; 
    for(int i =1;i<=c;i++)
    	cin>>a[i].minn>>a[i].maxn;
    sort(a+1,a+c+1,cmp);
    for(int i=1;i<=l;i++)
       cin>>b[i].spf>>b[i].num;
    int ans = 0 ;
    for(int i = 1;i <= c;i++)
    {
    	int minn = a[i].minn;
    	int maxn = a[i].maxn;
    	int pos = 0;
    	for(int j = 1;j<=l;j++)
    	{
            if(b[j].spf >= minn && b[j].num && b[j].spf <= maxn)
            {
            	minn = b[j].spf;
            	pos = j;
            }
    	}
    	if(pos)
        {
    	b[pos].num--;
    	ans++;
      }
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
//Nlog(N)
