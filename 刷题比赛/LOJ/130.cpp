/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n,q;
ll c[N],a[N];
ll ask(int x)
{
	ll ans = 0;
	for(;x;x -= x&-x) ans += c[x];
	return ans;
}

void add(int x,int y)
{
	for(;x <= n;x += x&-x) c[x] += y;
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i = 1;i<=n;i++) add(i,a[i]);
    for(int i = 1;i<=q;i++)
    {
    	int op,l,r;
    	scanf("%d %d %d",&op,&l,&r);
    	if(op == 1)
    	{
           add(l,r);
    	}
    	else 
    	{
           printf("%lld\n",ask(r) - ask(l-1));
    	}
    }
	return 0 ;
}	
*/
    #include<bits/stdc++.h>
    #define ll long long
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
    using namespace std;

    const int N=5000010;
    int n,m,totx=0,tot=0;      

    struct node{
        int type,id;
        ll val;
        bool operator < (const node &a) const   
        {
            if (id!=a.id) return id<a.id;
            else return type<a.type;
        }
    };
    node A[N],B[N];
    ll ans[N];

    void CDQ(int L,int R)
    {
        if (L==R) return;
        int M=(L+R)>>1;
        CDQ(L,M);
        CDQ(M+1,R);
        int t1=L,t2=M+1;
        ll sum=0; 
        for (int i=L;i<=R;i++)
        {
            if ((t1<=M&&A[t1]<A[t2])||t2>R) 
            {
                if (A[t1].type==1) sum+=A[t1].val;   
                B[i]=A[t1++]; 
            }
            else                       
            {
                if (A[t2].type==3) ans[A[t2].val]+=sum;
                else if (A[t2].type==2) ans[A[t2].val]-=sum;
                B[i]=A[t2++];
            }
        }
        for (int i=L;i<=R;i++) A[i]=B[i];
    }

    int main()
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            tot++;
            A[tot].type=1; A[tot].id=i;        
            read(A[tot].val);
        }
        for (int i=1;i<=m;i++)
        {
            int t;
            scanf("%d",&t);
            tot++;
            A[tot].type=t; 
            if (t==1)
                {
                    read(A[tot].id);
                    read(A[tot].val);
                }
            else
            {
                int l,r;
                read(l);
                read(r);    
                totx+q+; 
                A[tot].val=totx; A[tot].id=l-1;    
                tot++; A[tot].type=3; A[tot].val=totx; A[tot].id=r; 
            }
        }
        //for(int i= n;i<=n+m;i++) cout<<A[i].id<<" "<<A[i].val<<endl;
        CDQ(1,tot);
        //for(int i= n;i<=n+m;i++) cout<<A[i].id<<" "<<A[i].val<<endl;
        for (int i=1;i<=totx;i++) printf("%lld\n",ans[i]);
        return 0;
    }
