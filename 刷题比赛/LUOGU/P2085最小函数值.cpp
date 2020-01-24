/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
const int N = 10005;
struct node
{
   int x;
   int y;
   int z;	
}a[N];
std::vector<int> v;
priority_queue<int> q;
int main ()
{
    int n,m;
    read(n);
    read(m);
    for(int i = 1;i<=n;i++) 
    {
        read(a[i].x);
        read(a[i].y);
        read(a[i].z);
    } 
    for(int i = 1;i<=n;i++)
     {
         for(int j = 1;j<=100;j++)
         {
         	int ans = a[i].x*j*j+a[i].y*j+a[i].z;
         	q.push(-ans);
         }
    }
    int ans = 0;
    for(int i =1;i<=m;i++)
    {
       ans = q.top();
       q.pop();
       cout<<-ans<<" ";
    }
    return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
struct node
{
   int x;
   int y;
   int z;	
}a[N];
struct heap
{
	int sum;
	int a;
	int b;
	heap(int sum,int a,int b):sum(sum),a(a),b(b){}
	bool operator < (const heap & x) const 
	{
		return sum > x.sum;
	}
};
std::vector<int> v;
priority_queue<heap> q;
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++)
    	cin>>a[i].x>>a[i].y>>a[i].z;
    for(int i= 1;i<=n;i++)
       {
       	 int ans = a[i].x + a[i].y + a[i].z;
       	 q.push(heap(ans,i,1));
       } 
    for(int i= 1;i<=m;i++)
    {
        heap _ = q.top();
        q.pop();
        v.push_back(_.sum);
        int n = _.a;
        int m = _.b;
        m++;
        //cout<<m<<endl;
        int ans = a[n].x*(m)*(m)+a[n].y*(m)+a[n].z; 
        q.push(heap(ans,n,m));
    }
    for(int i = 0;i<v.size();i++)
    	cout<<v[i]<<" ";
	return 0 ;
}