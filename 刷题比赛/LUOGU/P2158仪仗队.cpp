#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 40005;
int d[N];
int n;
void init()
{
    for(int i= 2;i<=n;i++) d[i] = i;
    for(int i= 2;i<=n;i++)
    {
        if(d[i] == i)
        for(int j = i;j <= n;j += i)
          d[j] = d[j]/i*(i-1);
    }
}
int main ()
{
    cin>>n;
    if(n == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    n--;
    init();
    int ans = 0;
    int tmp = 0;
    for(int i = 2;i<=n;i++) tmp += d[i];
    ans = 3 + 2 * tmp;
    cout<<ans<<endl;
    return 0 ;
}