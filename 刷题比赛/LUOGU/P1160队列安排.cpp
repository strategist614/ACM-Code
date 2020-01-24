#include<bits/stdc++.h>
using namespace std;
using it = list<int>::iterator;
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
list<int> l;
it pos[N]; 
int vis[N];
int main ()
{
	int n;
	read(n);
	l.push_back(1);
    pos[1] = l.begin();
    for(int i= 2;i<=n;i++) 
    {
    	int k,p;
    	read(k);
    	read(p);
    	if(p == 0)
    	{
    		pos[i] = l.insert(pos[k],i);
    	}
    	else 
    	{
    		auto it = next(pos[k]);
    		pos[i] = l.insert(it,i);
    	}
    }   
    int m;
    cin>>m;
    for(int i= 1;i<=m;i++)
    {
    	int x;
    	read(x);
    	if(!vis[x])
    		l.erase(pos[x]);
        vis[x]++;
    }
    for(auto it = l.begin();it != l.end();it++)
    	cout<<(*it)<<" ";
	return 0 ;
}

/*
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
struct tree
{
	int l;
	int r;
	int v;
}t[N];
void dfs(int x)
{
	if(x == -1) return ;
	dfs(t[x].l);
	if(t[x].v == 0) printf("%d ",x);
	dfs(t[x].r);
}
int main ()
{
    int n;
    cin>>n;
    t[1].l = t[1].r = -1;
    t[1].v = 0;
    for(int i= 2;i<=n;i++) 
    {
    	int x,k;
    	cin>>x>>k;
    	t[i].l = t[i].r = -1;
    	t[i].v = 0;
    	if(k == 0)
    	{
           if(t[x].l != 0)
           {
           	  t[i].l = t[x].l;
           	  t[x].l = i;
           } 
           else t[x].l = i;
    	}
    	else 
    	{
           if(t[x].r != 0)
           {
           	 t[i].r = t[x].r;
           	 t[x].r = i;
           }
           else t[x].r = i;
    	}
    }
    int m;
    read(m);
    for(int i= 1;i<=m;i++)
    {
    	int x;
    	read(x);
    	t[x].v = 1;
    }
    dfs(1);
	return 0 ;
}
*/
