/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
struct dir
{
	int x;
	int y;
};
dir a[N],b[N];
map<pair<int,int>,int> mk,ml;
map<pair<int,int>,int>::iterator it;
struct node 
{
	int d;
	int dir;
}va[N],vb[N];
std::vector<int> la;
std::vector<int> lb;
bool cmp(node a,node b)
{
   return a.d > b.d;
}
int main ()
{
	int m,n,k,l,d;
	cin>>m>>n>>k>>l>>d;
	int sum1 = 0,sum2 = 0 ;
	for(int i= 1;i<=d;i++) cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
	for(int i= 1;i<=d;i++)
	{
		if(a[i].x == b[i].x)
           {
           	ml[make_pair(a[i].y,b[i].y)]++;
            sum1++;
           }
        if(a[i].y == b[i].y)
          {
           mk[make_pair(a[i].x,b[i].x)]++;  
           sum2++;
	}
}
	int tota = 0,totb = 0 ;
	int flaga = 0,flagb = 0;
    for(it = ml.begin();it != ml.end();it++) {va[++tota].d = it->second;auto tmp = (*it).first;va[tota].dir = min(tmp.first,tmp.second);if(it->second >= 2) flaga = 1;}
    for(it = mk.begin();it != mk.end();it++) {vb[++totb].d = it->second;auto tmp = (*it).first;vb[totb].dir = min(tmp.first,tmp.second);if(it->second >= 2) flagb = 1;}
    sort(va+1,va+tota+1,cmp); 
    sort(vb+1,vb+totb+1,cmp);
    for(int i= 1;i<=totb;i++)
    {
    	lb.push_back(vb[i].dir);
    }
    for(int i= 1;i<=tota;i++)
    {
        la.push_back(va[i].dir);
    }
    sort(la.begin(),la.end());
    sort(lb.begin(),lb.end());
    if(flagb)
    {
      for(int i= 1;i<=totb;i++) 
      {
      	if(i != totb) cout<<lb[i]<<" ";
      	else cout<<lb[i];
      }
    } 
    else 
    {
      for(int i= 0;i<k;i++)
      {
      	if(i != k-1) cout<<lb[i]<<" ";
      	else cout<<lb[i];
      }
    }
    cout<<endl;
    if(flaga)
    {
       for(int i =1;i<=tota;i++) 
       {
       	if(i != tota) cout<<la[i]<<" ";
       	else cout<<la[i];
       }
    }
    else 
    {
      for(int i= 0;i<l;i++)
      {
      	if(i != l-1) cout<<la[i]<<" ";
      	else cout<<la[i];
      }
    } 
 	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int r;
	int l;
	int val;
}a[2005],b[2005];
bool cmp1(node a,node b)
{
	return a.val > b.val;
}
bool cmp2(node a,node b)
{
	return a.l < b.l;
}
int main ()
{
    int n,m,k,l,d;
    cin>>n>>m>>k>>l>>d;
    for(int i= 1;i<=n;i++) a[i].l = i,a[i].r = i+1;
    for(int i= 1;i<=m;i++) b[i].l = i,b[i].r = i+1;
    for(int i= 1;i<=d;i++)
    {
    	int x,y,p,q;
    	cin>>x>>y>>p>>q;
    	if(x == p) a[min(y,q)].val++;
    	else b[min(x,p)].val++;
    }
    sort(a+1,a+n+1,cmp1);
    sort(a+1,a+l+1,cmp2);
    sort(b+1,b+m+1,cmp1);
    sort(b+1,b+k+1,cmp2);
    for(int i =1;i<=k;i++)
    {
    	if(i != k) cout<<b[i].l<<" ";
    	else cout<<b[i].l;
    }
    cout<<endl;
    for(int i= 1;i<=l;i++)
    {
    	if(i != l) cout<<a[i].l<<" ";
    	else cout<<a[i].l;
    }
	return 0 ;
}