/*#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int d;
	long long r,t;
	cin>>d>>r>>t;
	long long  sum = 0;
	int ans = 0;
    for(int i = 0;i<=1000;i++)
    {
    	sum = 0 ;
       for(int j = 4;j<=i;j++)
       	sum = (long long)sum + (long long)j;
       sum = (long long)sum * 2;
       for(int j = i+1;j<=i+d;j++)
        sum  = (long long)sum + (long long)j;
       sum += 3; 
       if(sum == r+t)
       {
       	 ans = i;
       	 break;
       }
    }
    ///cout<<sum<<endl;
    long long cnt = 0 ;
    for(int i = 3; i <= ans ; i ++)
    {
    	cnt += i ;
    }
    cout << cnt - t << endl; 
	return 0 ;
}
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
const int N = 1e5+5;
int fa[N];
void init(int n)
{
	for(int i= 1;i<=n;i++)
		fa[i] = i;
}
int find(int x)
{
   if(x == fa[x]) return x;
   return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
  fa[find(x)] = find(y);
}
struct node
{
	int x;
	int y;
	int z;
};
map<pair<int,pair<int,int>>,int>mp;
int main ()
{
	int n;
	read(n);
	init(n);
	int flag = 0;
	for(int i = 1;i<=n;i++)
	{
       int x1,y1,z1;
       int x2,y2,z2;
       read(x1);
       read(y1);
       read(z1);
       read(x2);
       read(y2);
       read(z2);
       if(!mp[make_pair(x1,make_pair(y1,z1))]) 
         mp[make_pair(x1,make_pair(y1,z1))] = ++flag;
       if(!mp[make_pair(x2,make_pair(y2,z2))])
       		mp[make_pair(x2,make_pair(y2,z2))] = ++flag;
       if(find(mp[make_pair(x1,make_pair(y1,z1))]) != find(mp[make_pair(x2,make_pair(y2,z2))]))
      	{
       		merge(mp[make_pair(x1,make_pair(y1,z1))],mp[make_pair(x2,make_pair(y2,z2))]);
 		}
 	}
 	int ans = 0;
    for(int i = 1;i<=n;i++) if(fa[i] != i) ans++;
    
	return 0; 
}