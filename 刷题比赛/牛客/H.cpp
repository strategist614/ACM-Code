#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn(100005), mod(1e9 + 7);
LL Jc[maxn];
 
void calJc()   
{
    Jc[0] = Jc[1] = 1;
    for(LL i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}
 
LL pow(LL a, LL n, LL p)   
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
 
LL niYuan(LL a, LL b)  
{
    return pow(a, b - 2, b);
}
 
LL C(LL a, LL b)  
{
    return Jc[a] * niYuan(Jc[b], mod) % mod
        * niYuan(Jc[a - b], mod) % mod;
}
 
 
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        calJc();
        int n,m;
        scanf("%d %d",&n,&m);
        int u,v;
        for(int i= 1;i<=n-1;i++) scanf("%d %d",&u,&v);
        if(m == 1)
        {
            printf("1\n");
            continue;
        }
        long long ans = 0;
        ans = C(n-1,m-1);
        ans = (ans*Jc[m])%mod;
        printf("%lld\n",ans);
    }
    return 0 ;
}