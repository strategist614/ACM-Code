#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1000000007;
unsigned long long k1,k2;
unsigned long long _xor()
{
	unsigned long long k3 = k1,k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4; 
}
int n,m,u[100005],v[100005];
unsigned long long w[100005];
void gen()
{
	for(int i = 1;i<=m;i++)
	{
		u[i] = _xor()%n+1;
		v[i] = _xor()%n+1;
		w[i] = _xor();
	}
}
int fa[100005];
struct rec
{
	long long x;
	long long y;
	unsigned long long z;
}edge[100005];
bool cmp(rec a,rec b)
{
	return a.z < b.z;
}
int find(int x)
{
   if(x == fa[x]) return x;
   return  fa[x] = find(fa[x]);
}
vector<unsigned long long> ansv;
set<int> s;

int main ()
{
	scanf("%d %d %llu %llu",&n,&m,&k1,&k2);
    gen();
    for(int i= 1;i<=m;i++)
    {
        edge[i].x = u[i];
        edge[i].y = v[i];
        edge[i].z = w[i];
    }
  
    sort(edge+1,edge+m+1,cmp);
    for(int i = 1;i<=n;i++) fa[i] = i;
    unsigned long long ans = 0;
	int cnt = 0 ;
    for(int i = 1;i<=m;i++)
    {
        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if(x == y) continue;
        fa[x] = y;
        cnt ++ ;
        ans = ((ans % mod) + (edge[i].z%mod))%mod;
    }
    if(cnt < n-1)
    {
    	cout << 0 << endl ;
    	return 0 ;
    }--
    cout<<ans%mod<<endl;
	return 0 ;
}
/*
2
100000
123456789
987654321
*/