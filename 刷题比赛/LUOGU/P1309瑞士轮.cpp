/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
const int N = 1e5+5;
struct node
{
    ll s;
	ll w;
	int id;
}a[N<<1];
bool cmp(node a,node b)
{
	if(a.s == b.s) return a.id < b.id;
	return a.s > b.s;
}
int main ()
{
	int n,r,q;
	read(n);
	read(r);
	read(q);
    for(int i= 1;i<=2*n;i++) {read(a[i].s);a[i].id = i;}
    for(int i =1;i<=2*n;i++) read(a[i].w);
    while(r--)
    {
       stable_sort(a+1,a+2*n+1,cmp);
       for(int i= 1;i<=2*n-1;i+=2)
       {
           if(a[i].w > a[i+1].w) a[i].s += 1;
           else a[i+1].s += 1;
       }
    }	
    stable_sort(a+1,a+2*n+1,cmp);
    out(a[q].id);
    puts("");
	return 0 ;
}
O2过*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct node
{
   ll s;
   int id;
}a[N];
node A[N];
node B[N];
node temp[N];
int w[N];
int n,r,q;
bool cmp(node a,node b)
{
    if(a.s == b.s) return a.id < b.id;
    return a.s > b.s;
}
void mergesort()
{
     int i = 1;
     int j = 1;
     int k = 1;
     while(i <= n && j <= n)
     {
     	if((A[i].s > B[j].s) || (A[i].s == B[j].s && A[i].id < B[j].id))
     	{
     		a[k].s = A[i].s;
     		a[k++].id = A[i++].id;
     	}
     	else 
     	{
     		a[k].s = B[j].s;
     		a[k++].id = B[j++].id;
     	}
     }
     while(i <= n)
     {
     	a[k].s = A[i].s;
     	a[k++].id = A[i++].id;
     } 
     while(j <= n)
     {
     	a[k].s = B[j].s;
     	a[k++].id = B[j++].id;
     }
}
int main ()
{
    cin>>n>>r>>q;
    for(int i= 1;i<=2*n;i++) {cin>>a[i].s;a[i].id = i;}
    for(int i= 1;i<=2*n;i++) cin>>w[i];
    sort(a+1,a+2*n+1,cmp);
    while(r--)
    {
         int cnt = 1;
         for(int i= 1;i<=2*n-1;i+=2)
         {
             if(w[a[i].id] > w[a[i+1].id])
             {
                A[cnt].s = a[i].s+1;
                A[cnt].id = a[i].id;
                B[cnt].s = a[i+1].s;
                B[cnt].id = a[i+1].id;
                cnt++; 
             }
             else 
             {
                B[cnt].s = a[i].s;
                B[cnt].id = a[i].id;
                A[cnt].s = a[i+1].s+1;//如果不在一个获胜集合内，则无法保证序列的有序
                A[cnt].id = a[i+1].id;
                cnt++;
             }
         }
         mergesort();
    }
    cout<<a[q].id<<endl;
    return 0 ;
}
