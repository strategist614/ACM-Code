#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x)) 
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
const int X = 2e5+5;
struct node
{
	int x;
	int y;
	int z;
	int ans;
	int cnt;
}a[X],b[X];
int ans[X];
int tree[X];
int N,k;

bool cmp(node a,node b){
    if(a.x!=b.x) return a.x<b.x;
    else if(a.y!=b.y) return a.y<b.y;
    else return a.z<b.z;
}

void add(int x,int v){ for(int i=x;i<=k;i+=lowbit(i))tree[i]+=v;}
int ask(int x)
{
	int ans = 0;
	for(;x;x-=x&-x) ans += tree[x];
	return ans ;
}

void CDQ(int ll,int rr)
{
    if(ll==rr) return;
    int mid=(ll+rr)>>1;
    CDQ(ll,mid); CDQ(mid+1,rr);

    int t1=ll,t2=mid+1,p=ll;
    while(t2<=rr)
    {
        while(a[t1].y<=a[t2].y&&t1<=mid) 
        add(a[t1].z,a[t1].cnt),b[p++]=a[t1++];
        a[t2].ans+=ask(a[t2].z); b[p++]=a[t2++];
    }
    for(int i=ll;i<t1;++i)
    add(a[i].z,-a[i].cnt);

    while(t1<=mid) b[p++]=a[t1++];
    while(t2<=rr) b[p++]=a[t2++];
    for(int i=ll;i<=rr;++i) a[i]=b[i];
}
int main ()
{
    read(N);
    read(k);
    for(int i= 1;i<=N;i++) 
    {
    	read(b[i].x);
    	read(b[i].y);
    	read(b[i].z);
    }
    sort(b+1,b+N+1,cmp);
    int num = 0;
    int n = 0;
    for(int i=1;i<=N;++i)
    {
        num++;
        if(b[i].x!=b[i+1].x||b[i].y!=b[i+1].y||b[i].z!=b[i+1].z)
        a[++n]=b[i],a[n].cnt=num,a[n].ans=0,num=0;
    }
    CDQ(1,n);
	for(int i=1;i<=n;++i)
    ans[a[i].ans+a[i].cnt-1]+=a[i].cnt;
    for(int i=0;i<N;++i)
    printf("%d\n",ans[i]);
	return 0 ;
}
