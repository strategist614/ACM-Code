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
    ll n,mod;
    ll a[N];
    struct stree
    {
        ll l;
        ll r;
        ll sum;
        ll add;
        ll mul;
    }tree[N<<2];

    void pushup(int rt)
    {
        tree[rt].sum = (tree[rt<<1].sum + tree[rt<<1|1].sum)%mod;
    }

    void pushdown(int rt)
    {
        tree[rt<<1].sum *= tree[rt].mul;
        tree[rt<<1].sum %= mod;
        tree[rt<<1|1].sum *= tree[rt].mul;
        tree[rt<<1|1].sum %= mod;
        tree[rt<<1].mul *= tree[rt].mul;
        tree[rt<<1].mul %= mod;
        tree[rt<<1|1].mul *= tree[rt].mul;
        tree[rt<<1|1].mul %= mod;
        tree[rt<<1].add *= tree[rt].mul;
        tree[rt<<1].add %= mod;
        tree[rt<<1|1].add *= tree[rt].mul;
        tree[rt<<1|1].add %= mod;
        tree[rt<<1].sum += (ll)(tree[rt].add%mod)*((tree[rt<<1].r - tree[rt<<1].l +1)%mod);
        tree[rt<<1].sum %= mod;
        tree[rt<<1|1].sum += (ll)(tree[rt].add%mod)*((tree[rt<<1|1].r - tree[rt<<1|1].l +1)%mod);
        tree[rt<<1|1].sum %= mod;
        tree[rt<<1].add += tree[rt].add;
        tree[rt<<1].add %= mod;
        tree[rt<<1|1].add += tree[rt].add;
        tree[rt<<1|1].add %= mod;
        tree[rt].add = 0;
        tree[rt].mul = 1; 
    }

    void build(int rt,int l,int r)
    {
        tree[rt].l = l;
        tree[rt].r = r;
        tree[rt].add = 0;
        tree[rt].mul = 1;
        if(l == r)
        {
            tree[rt].sum = a[l]%mod;
            return ;
        }
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }

    void updatep(int rt,int L,int R,int val)
    {
        int l = tree[rt].l;
        int r = tree[rt].r;
        if(L <= l && r <= R)
        {
           tree[rt].sum += (val*(tree[rt].r - tree[rt].l+1)%mod)%mod;
           tree[rt].sum %= mod;
           tree[rt].add += val;
           tree[rt].add %= mod;
           return ;
        }
        int mid = (l+r)>>1;
        pushdown(rt);
        if(L <= mid) updatep(rt<<1,L,R,val);
        if(R > mid) updatep(rt<<1|1,L,R,val);
        pushup(rt);
    }

    void updatem(int rt,int L,int R,int val)
    {
        int l = tree[rt].l;
        int r = tree[rt].r;
        if(L <= l && r <= R)
        {
            tree[rt].sum *= val;
            tree[rt].sum %= mod;
            tree[rt].mul *= val;
            tree[rt].mul %= mod;
            tree[rt].add *= val;
            tree[rt].add %= mod;
            return ;
        }
        int mid = (l+r)>>1;
        pushdown(rt);
        if(L <= mid) updatem(rt<<1,L,R,val);
        if(R > mid) updatem(rt<<1|1,L,R,val);
        pushup(rt);
    }

    ll query(int rt,int L,int R)
    {
        int l = tree[rt].l;
        int r = tree[rt].r;
        if(L <= l && r <= R) return tree[rt].sum % mod;
        int mid = (l+r)>>1;
        pushdown(rt);
        ll ans = 0;
        if(L <= mid) ans += query(rt<<1,L,R),ans %= mod;
        if(R > mid) ans += query(rt<<1|1,L,R),ans %= mod;
        pushup(rt);
        return ans % mod; 
    }

    int main ()
    {
          read(n);
        read(mod);
        for(int i = 1;i<=n;i++) read(a[i]);
        build(1,1,n);
        int m;
        read(m);
        for(int i= 1;i<=m;i++)
        {
            int op;
            read(op);
            if(op == 1)
            {
               int l,r,val;
               read(l);
               read(r);
               read(val);
               updatem(1,l,r,val);
            }
            else if(op == 2)
            {
               int l,r,val;
               read(l);
               read(r);
               read(val);
               updatep(1,l,r,val); 
            }
            else 
            {
               int l;
               int r;
               read(l);
               read(r);
               ll ans = query(1,l,r);
               out(ans);
               puts(""); 
            }
        } 
        return 0 ; 
    }