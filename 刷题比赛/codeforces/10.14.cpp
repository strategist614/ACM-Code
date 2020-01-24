/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool j(int a,int b,int c)
{
	if(b+c>a) return true;
	else return false;
}
int main ()
{ 
	int a[4];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    int cnt = a[1]+a[2];
    int tmp = a[3];
    if(cnt > tmp) cout<<0<<endl;
    else 
    {
    	tmp += 1;
    	cout<<tmp-cnt<<endl;
    }
	return 0; 
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll BitCount(unsigned long long n)
{
    unsigned int c =0 ; 
    while (n >0)
    {
        if((n &1) ==1)
            ++c ; 
        n >>=1 ; 
    }
    return c ;
}
ll power(ll a, ll n)
{
    long long ans = 1;
    while(n > 0) {
        if(n&1) {
            ans *= a;
        }
        a *= a;
        n /= 2;
    }
    return ans;
}

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {

    	ll a;
    	cin>>a;
        ll ans = 0;
        ll cnt = 0;
        ans = BitCount(a);
        cnt =power(2,ans);
        cout<<cnt<<endl;
    }
	return 0; 
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
char a[N];
int b[27];
int main ()
{
	int n;
    cin>>n;
    scanf("%s",a);
    sort(a,a+n);
    cout<<a<<endl;
	return 0; 
}
*/
