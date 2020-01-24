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
const int N = 10000;
typedef long long ll;
const int S = 8;
ll mult_mod(ll a,ll b,ll c)
{
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}
ll pow_mod(ll a,ll n,ll mod)
{
   ll ret = 1;
   ll temp = a % mod;
   while(n)
   {
   	if(n&1) ret = mult_mod(ret,temp,mod);
   	temp = mult_mod(temp,temp,mod);
   	n>>=1;
   } 
  return ret; 
}
bool check(ll a,ll n, ll x ,ll t)
{
	ll ret = pow_mod(a,x,n);
	ll last = ret;
	for(int i  =1;i<=t;i++)
	{
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1&&last != n-1) return true;
		last = ret;
	}
	if(ret != 1) return true;
	else return false;
}
bool miller_rabin(ll n)
{
	if(n <2) return false;
	if(n == 2) return true;
	if((n&1) == 0) return false;
	ll x = n-1;
	ll t = 0 ;
	while((x&1) == 0){x >>= 1;t++;}
	srand(time(NULL));
	for(int i = 0;i<S;i++)
	{
		ll a = rand()%(n - 1)+1;
		if(check(a,n,x,t))
			return 	false;
	}
	return true;
}
struct node
{
	int a;
	int b;
	int c;
	int d;
	int t;
};
int a,b;
int vis[N];
map<int,int> mp;
void init()
{
	for(int i = 1000;i < 10000;i++)
	{
		if(miller_rabin(i)) mp[i] = 1;
		else mp[i] = 0;
	}
}
void bfs(node tmp)
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	vis[a] = 1;
	tmp.t = 0;
	q.push(tmp);
	while(q.size())
	{
		node _,v;
		v = q.front();
		q.pop();
		int x = v.a*1000+v.b*100+v.c*10+v.d;
		    if(x == b)
		    {
			   cout<<v.t<<endl;
			   return  ;
		    }
		    //_ = v;
		    for(int i =1;i<=4;i++)
		    {
		      if(i ==1)
		      {
			  for(int i = 1;i <= 9;i++)
			   {
				if(i != v.a)
				{
					_ = v;
					_.a = i;
					int tmp = _.a*1000+_.b*100+_.c*10+_.d;
                    if(!mp[tmp]) continue; 
                    _.t = v.t+1;
                    if(!vis[tmp])
                    {
                    	q.push(_);
                    	vis[tmp] = 1;
                    }     
				}
			}
		}
		else if(i == 2)
		{
          for(int i = 0;i <= 9;i++)
           {
           	  if(i != v.b)
           	  {
           	  	_ = v;
           	  	_.b = i;
           	  	int tmp = _.a*1000+_.b*100+_.c*10+_.d;
           	  	//cout<<tmp<<endl;
           	  	if(!mp[tmp]) continue;
           	  	_.t = v.t+1;
           	  	if(!vis[tmp])
           	  	{
           	  		q.push(_);
           	  		vis[tmp] = 1;
           	  	}
           	  }
           }
       }
         else if(i == 3)
         {
           for(int i =0;i<=9;i++)
           {
           	  if(i != v.c)
           	  {
           	  	_ = v;
           	  	_.c = i;
           	  	int tmp = _.a*1000+_.b*100+_.c*10+_.d;
           	  	if(!mp[tmp]) continue;
           	  	_.t = v.t+1;
           	  	if(!vis[tmp])
           	  	{
           	  		q.push(_);
           	  		vis[tmp] = 1;
           	  	}
           	  }
           }
       }
       else 
       {
           for(int i =0;i<=9;i++)
           {
           	  if(i != v.d)
           	  {
           	  	_ = v;
           	  	_.d = i;
           	  	int tmp = _.a*1000+_.b*100+_.c*10+_.d;
           	  	if(!mp[tmp]) continue;
           	  	_.t = v.t+1;
           	  	if(!vis[tmp])
           	  	{
           	  		q.push(_);
           	  		vis[tmp] = 1;
           	  	}
           	  }
           }
         }
       }
	}
	cout<<"Impossible"<<endl;
}
int main ()
{
	int t;
	read(t);
	init();
	while(t--)
	{
        read(a);
        read(b);
        node tmp;
        tmp.a = a / 1000;
        tmp.b = a / 100%10;
        tmp.c = a / 10 % 10;
        tmp.d = a % 10;
        bfs(tmp);
	}
	return 0 ;
}