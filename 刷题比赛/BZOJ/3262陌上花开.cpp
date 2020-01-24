/*
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
*/
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
const int N = 2e5+5;
struct node 
{
    int x;
    int y;
    int z;
    int cnt;
    int ans;
}a[N],b[N];
int c[N],ans[N],use[N];
bool cmp(node a,node b)
{
    if(a.x == b.x)
    {
        if(a.y == b.y) return a.z < b.z;
        else 
        return a.y < b.y;
    }
    else return a.x < b.x;
}
struct treearray
{
    void add(int x,int y)
    {
        for(;x <= N;x += x&-x) c[x]+=y;
    }
    int ask(int x)
    {
        int ans = 0;
        for(;x;x-=x&-x) ans += c[x];
        return ans ; 
    }
}ta;
void CDQ(int l,int r)
{
    if(l == r) return ;
    int mid = (l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
    int i = l;
    int j = mid+1;
    for(int k = l;k<=r;k++)
    {
       if(j > r || (b[i].y <= b[j].y && i <= mid)) 
         ta.add(b[i].z,b[i].cnt),a[k] = b[i++],use[k] = 1;
       else b[j].ans += ta.ask(b[j].z),a[k] = b[j++];
    }
    for(int k = l;k<=r;k++) b[k] = a[k];
    for(int i = l;i<=r;i++)
        if(use[i]) ta.add(b[i].z,-b[i].cnt),use[i] = 0;
}
int main ()
{
    int n,k;
    read(n);
    read(k);
    for(int i= 1;i<=n;i++)
    {
        read(a[i].x);
        read(a[i].y);
        read(a[i].z);
    }
    sort(a+1,a+n+1,cmp);
    int num = 0;
    int tot = 0;
    for(int i =1;i<=n;i++)
    {
      num++;
      if(a[i].x != a[i+1].x || a[i].y != a[i+1].y || a[i].z != a[i+1].z)
        b[++tot] = a[i],b[tot].cnt = num,b[tot].ans = 0,num = 0;
    }
    CDQ(1,tot);
    for(int i= 1;i<=tot;i++)
        ans[b[i].ans+b[i].cnt-1] += b[i].cnt;
    for(int i= 0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0 ;
}