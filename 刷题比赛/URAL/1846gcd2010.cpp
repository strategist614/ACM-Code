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
const int N = 1e5+5;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

struct segment_tree
{
	int l;
	int r;
	int dat;
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].dat = gcd(tree[rt<<1].dat,tree[rt<<1|1].dat); 
}

void build(int rt,int l,int r)
{
   tree[rt].l = l;
   tree[rt].r = r;
   if(l == r)
   {
   	 tree[rt].dat = 0;
   	 return ;
   }
   int mid = (l+r)>>1;
   build(rt<<1,l,mid);
   build(rt<<1|1,mid+1,r);
   pushup(rt);
}

void update(int rt,int x,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r)
	{ 
		tree[rt].dat = val;
		return ; 
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(rt<<1,x,val);
	else update(rt<<1|1,x,val);
	pushup(rt);
}

int op[N],num[N],q,sum[N];

std::vector<int> v;

int main ()
{
    cin>>q;
    build(1,1,q);
    for(int i =1;i<=q;i++)
    {
    	char s[20];
    	cin>>s;
    	read(num[i]);
    	v.push_back(num[i]);
    	op[i] = (s[0] == '+')?0:1;
    }
    sort(v.begin(),v.end());
    int tot = unique(v.begin(),v.end())-v.begin();
    for(int i= 1;i<=q;i++)
    {
        int pos = lower_bound(v.begin(),v.begin()+tot,num[i])-v.begin()+1;
        if(op[i] == 0)
        {
        	sum[pos]++;
            if(sum[pos] == 1) update(1,pos,v[pos-1]);
        }
        else 
        {
        	sum[pos]--;
        	if(sum[pos] == 0) update(1,pos,0);
        }
        if(tree[1].dat != 0) 
        	cout<<tree[1].dat<<endl;
        else cout<<1<<endl;
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

struct segment_tree 
{
   int l;
   int r;
   int dat;
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].dat = gcd(tree[rt<<1].dat,tree[rt<<1|1].dat);
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].dat = 0;
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}



int main ()
{

	return 0 ;
}