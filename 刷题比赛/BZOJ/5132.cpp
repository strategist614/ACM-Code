#include<bits/stdc++.h>
#define pb(a,b) (stree){a,b}
using namespace std;
const int N = 100010;

inline char gc(){
    static char now[1<<16], *S, *T;
    if(S==T){T=(S=now)+fread(now, 1, 1<<16, stdin); if(S==T)return EOF;}
    return *S++;
}
inline int read(){
    int x=0; char ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=gc();}
    return x;
}


int w[N],sum[N<<2];
deque<int> d[N];

struct stree
{
	int x;
	int id;
};

inline bool operator>(stree a, stree b){return a.x>b.x;}

void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

inline void insert(int rt,int x,int l,int r)
{
    if(l == r)
    {
    	sum[rt]++;
    	return;
    }
	int mid = (l+r)>>1;
	if(x <= mid) insert(rt<<1,x,l,mid);
	else insert(rt<<1|1,x,mid+1,r);
	pushup(rt);
}

inline int search(int rt,int l,int r)
{
	if(!sum[rt]) return 0;
	sum[rt]--;
  if(l == r) 
    return l;
  int mid = (l+r)>>1;
	if(sum[rt<<1]) return search(rt<<1,l,mid);
	else return search(rt<<1|1,mid+1,r);
	pushup(rt);
}

inline int check(int rt,int x,int l,int r)
{
   if(!sum[rt]) return 0;
   if(l == r)
   {
     sum[rt]--;
     return 1;
   }
   int mid = (l+r)>>1;
   int s ;
   if(x <= mid) s = check(rt<<1,x,l,mid);
   else s = check(rt<<1|1,x,mid+1,r);
   sum[rt] -= s;
   return s;
   pushup(rt);
}

inline int query(int rt,int L,int R,int l,int r)
{
  if(L <= l && r <= R) return sum[rt];
  int ans = 0;
  int mid = (l+r)>>1;
  if(L <= mid) ans += query(rt<<1,L,R,l,mid);
  if(R > mid) ans += query(rt<<1|1,L,R,mid+1,r);
  return ans;
}

int n,m,l,r,y,x,op,t;
int main ()
{
  t = read();
  for(int owo = 1;owo<=t;owo++)
  {
  	n = read();
  	for(int i = 1;i<=n;i++) w[i] = read();
    for(int i = 1;i<=n;i++) d[i].clear();
    priority_queue<stree, vector<stree>, greater<stree> > q;
    memset(sum,0,sizeof(sum));
    m = read();
    for(int i = 1;i <= m;i++)
    {
       x = read();
       op = read();
       while(q.size() && q.top().x <= x)
       {
       	 y = q.top().id;
       	 insert(1,y,1,n);
       	 d[y].pop_front();
       	 q.pop();
       }
       if(op == 0)
       {
         y = read();
         d[y].push_back(w[y] + x);
         q.push(pb(w[y] + x,y));
       }
      if(op == 1)
       {
          if(!sum[1])
          {
            printf("Yazid is angry.\n");
            continue;
          }
          printf("%d\n",search(1,1,n));
       }
      if(op == 2)
       {
          y = read();
          if(check(1,y,1,n))
          {
          	printf("Succeeded!\n");
          	continue;
          }
          if(d[y].size())
          {
          	printf("%d\n",d[y].front() - x);
            continue;
          }
          printf("YJQQQAQ is angry.\n");
       }
       if(op == 3)
       {
       	 l = read();
       	 r = read();
       	 printf("%d\n",query(1,l,r,1,n));
       }
    }
  }
  return 0 ;
}
/*
1
2
1 100
10
1 0 2
2 0 1
3 2 1
4 2 2
5 2 1
200 0 1
201 3 1 2
202 1
203 1
204 1
*/
