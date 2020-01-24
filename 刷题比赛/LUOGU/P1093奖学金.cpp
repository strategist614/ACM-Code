#include<bits/stdc++.h>
using namespace std;
const int N = 305;
struct  node
{
	int c;
	int m;
	int e;
	int xh;
	int sum;
}a[N];
bool cmp(node a,node b)
{
	if(a.sum == b.sum)
	{ 
       if(a.c == b.c)
       {
           return a.xh < b.xh;
       }
       else return a.c > b.c;
	}
	else return a.sum > b.sum;
}
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
     {
      cin>>a[i].c>>a[i].m>>a[i].e;
      a[i].xh = i;
      a[i].sum = a[i].c+a[i].m+a[i].e;
     }
     sort(a+1,a+1+n,cmp);
     for(int i= 1;i<=5;i++)
       cout<<a[i].xh<<" "<<a[i].sum<<endl;     
	return 0 ;
}