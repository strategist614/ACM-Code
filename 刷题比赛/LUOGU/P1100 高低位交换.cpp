/*
独立思考
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
typedef long long ll;
typedef unsigned long long ull;
std::vector<int> v;
int main ()
{
    int n;	
    cin>>n;
    bitset<32> b(n);
    ll ans = 0;
    for(int i= 15;i>=0;i--)
    	v.push_back(b[i]);
    for(int i= 31;i>=16;i--)
        v.push_back(b[i]);
    reverse(v.begin(),v.end());
    for(int i= 0;i<v.size();i++)
    {
    	ans += v[i]*pow(2,i);
        //cout<<v[i];
    }
    cout<<ans<<endl;
	return 0 ;
}