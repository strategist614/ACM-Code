
/*#include<bits/stdc++.h>
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
}*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int n,m;
    cin>>n>>m;
    if(m == 0)
    {
        cout<<n<<" "<<n<<endl;
        return 0 ;
    }
    if(m >= n)
    {
        cout<<0<<" "<<0<<endl;
    }
    else 
    {  
       if(n <= (ll)(2*m)) 
        {   
            if(m <= 2)
            cout<<0<<" "<<n-(ll)(m+1)<<endl;
            else 
            cout<<0<<" "<<n-m<<endl;
    } 
    else 
    {
            if(m <= 2)
            cout<<n-(ll)(m*2)<<" "<<n-(ll)(m+1)<<endl;
            else 
            cout<<n-(ll)(m*2)<<" "<<n-m<<endl;
    }
}
    return 0 ;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{

    return 0 ;
}
*/

