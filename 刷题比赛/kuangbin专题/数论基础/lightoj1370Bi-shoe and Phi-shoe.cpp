#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000004;
int prime[80000];
bitset<maxn> s;
int tot = 0;
void sieve()
{
   for(int i = 0;i <= maxn;i++) s[i] = 1;
   s[0] = s[1] = 0;
   for(int i =2;i <= maxn;i++)
   {
   	 if(s[i])
   	 {
   	 	prime[++tot] = i;
   	 	for(int j = 2 * i ;j<=maxn;j+=i) s[j] = 0;
   	 }
   }
} 
int main ()
{
    int t;
    cin>>t;
    sieve();
    int flag = 0;
    while(t--)
    {
       int n;
       cin>>n;
       long long ans = 0;
       for(int i= 1;i<=n;i++)
       {
          int x;
          cin>>x;
          int pos = upper_bound(prime+1,prime+tot+1,x)-prime;
          ans = ans + (long long)prime[pos];
       }  
       printf("Case %d: %lld Xukha\n",++flag,ans);
    }
	return 0 ;
}