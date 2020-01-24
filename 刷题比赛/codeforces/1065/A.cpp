#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll s,a,b,c;
        cin>>s>>a>>b>>c;
        ll cnt = s/c;
        ll cnt1 = (cnt/a)*b;
        ll ans = cnt+cnt1;
        cout<<ans<<endl;
    }
    return 0 ;
}