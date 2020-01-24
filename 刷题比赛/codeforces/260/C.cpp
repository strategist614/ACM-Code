/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
ll a[N];
set<ll> s;
vector<int> v;
int main ()
{
    ll n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;i++) cin>>a[i];
    ll minn = inf;
    ll pos = 0; 
    for(int i = 1;i<=n;i++) 
    {
        if(a[i] < minn)
        {
            pos = i;
            minn = a[i];
        }
        s.insert(a[i]);
    } 
    for(int i= 1;i<=n;i++)
    {
        if(a[i] == a[pos])
            v.push_back(i);
    }
    if(s.size() == 1)
    {
        for(int i =1;i<=x-1;i++)
            cout<<0<<" ";
        ll tmp = n*minn;
        cout<<tmp<<" ";
        for(int i =x+1;i<=n;i++)
            cout<<0<<" "; 
        return 0;
    }
    if(pos <= x)
    {
         ll psimin = inf;
        for(int i = 0;i<v.size();i++)
         {
          int tmp = abs(x-v[i]);
          if(tmp < psimin)
          {
            psimin = tmp;
            pos = v[i];
         }
    }
        if(minn == 0)
        {
            a[pos] = x - pos;
            for(int i = pos+1;i<=x;i++)
                a[i] -= 1;
            for(int i = 1;i<=n;i++)
                cout<<a[i]<<" ";
        }
        else 
        {
            ll tmp = (ll)n*minn + x -pos;
            for(int i = 1;i<=pos-1;i++)
                a[i] -= minn;
            a[pos] = tmp;
            for(int i = pos+1;i<= x;i++)
                a[i] -= (minn+1);
            for(int i = x+1;i<=n;i++)
                a[i] -=minn;
            for(int i = 1;i<=n;i++)
                cout<<a[i]<<" ";
        }
    }
    else 
    {
        ll mipos = -inf;
        for(int i = 0;i<v.size();i++)
        {
             int tmp = abs(v[i] - x);
             if(tmp > mipos)
             {
                tmp = mipos;
                pos = v[i];
             }
        }
        if(minn == 0)
        {
            ll tmp = n-pos+x;
            for(int i = pos +1;i<=n;i++)
                a[i] -= 1;
            a[pos] = tmp;
            for(int i = 1;i<=x;i++)
                a[i] -= 1;
            for(int i = 1;i<=n;i++)
                cout<<a[i]<<" ";
        }
        else 
        {
            ll tmp = (ll)minn*n+x+n-pos;
            for(int i = pos+1;i<=n;i++)
                a[i] -= (minn+1);
            a[pos] = tmp;
            for(int i = 1;i<=x;i++)
                a[i] -= 1;
            for(int i  =1;i<=pos-1;i++)
                a[i] -= minn;
            for(int i = 1;i<=n;i++)
                cout<<a[i]<<" ";
        }
    }
    return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 110000;

long long v[maxn];

int main ()
{

    int n, x;
    
    cin >> n >> x;

    long long y = inf;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        chkmin(y, v[i]);
    }
    for (int i = 1; i <= n; ++i)
        v[i] -= y;
    
    for (int i = x, j = 0; ; ) {

        if (v[i] == 0) {
            v[i] = y * n + j;
            break;
        }
        --v[i], ++j;
        
        if (i == 1)
            i = n;
        else
            --i;
    }

    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0; 
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
ll a[N];
int main ()
{
    int n,x;
    cin>>n>>x;
    ll minn = inf;
    int pos = 0;
    for(int i = 1;i<=n;i++)  
    {
        cin>>a[i];
        minn = min(a[i],minn);
    }
    ll sum = 0;
    while(a[x] != minn)
    {
       a[x]--;
       sum++;
       x--;
       if(x == 0) x = n; 
    }
    for(int i = 1;i<=n;i++)
    {
        if(i == x) printf("%lld ",sum + n*minn);
        else printf("%lld ",a[i]-minn);
    }
    return  0;
}