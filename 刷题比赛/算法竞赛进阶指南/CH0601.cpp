/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int sum[N];
int x,n,t,k = 0;
void multi()
{
   int p = 1,ans = 0;
   while(p > 0)
   {
   	  if(ans + sum[k+p]-sum[k] <= x && k + p <= n)
   	  {	
   	  	ans += sum[k+p]-sum[k];
        k += p;
        p *= 2;
      }
      else 
      {
      	 p /= 2;
      	 if(p == 0) break;
      }
   }
}
int main ()
{
	cin>>n>>t;
	for(int i= 1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i];}
	while(t--)
	{
		cin>>x;
        k = 0;
        multi();
        cout<<k<<endl;
	} 
	return 0 ;
}
*/
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
typedef long long ll;
const int N = 5e5+5;

ll a[N],b[N],c[N],k;
int n,m,w;

void merge_sort(int l,int mid,int r)
{
	int i = l;
	int j = mid+1;
	for(int k = l;k <= r;k++)
	{
		if(j > r || (i <= mid && b[i] <= b[j])) c[k] = b[i++];
		else c[k] = b[j++]; 
	}
}

ll f(int l,int r)
{
	if(r > n) r = n;
	int t = min(m,(r-l+1)>>1);
	for(int i = w+1;i<=r;i++) b[i] = a[i];
    sort(b+w+1,b+r+1);
	merge_sort(l,w,r);
	ll ans = 0;
	for(int i = 0;i < t;i++)
	ans += (c[r-i]-c[l+i]) * (c[r-i]-c[l+i]);
    return ans;
}

int genius_ACM()
{
   read(n);
   read(m);
   read(k);
   for(int i =1;i<=n;i++) read(a[i]);
   int p,l = 1,r = 1,ans = 0;
   w = 1;
   b[1] = a[1];
   while(l <= n)
   {
   	  p = 1;
      while(p)
      {
      	 ll tmp = f(l,r + p);
      	 if(tmp <= k)
      	 {
           w = r = min(r + p,n);
           for(int i = l;i<=r;i++) b[i] = c[i];
           if(r == n) break; 
           p <<= 1;
      	 }
         else p >>= 1;
      }
      l = r +1;
      ans++;
   }
   return ans;
}

int main ()
{
	int t;
	read(t);
	while(t--)
	{
       int ans = genius_ACM();
       out(ans);
       puts("");
	}
	return 0 ;
}
*/
#include <bits/stdc++.h>
using namespace std;
long long t,n,j,k,m,i,x,ans,l,r,p;
long long a[500005],b[500005],c[500005];
inline long long read(){
   long long s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){ch=getchar();}
   while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
   return s;
}
inline long long cmp(long long x,long long y)
{
	return x<y;
}
long long doit(long long l,long long r,long long p)
{
	long long num=0;
	int i;
	for (i=r+1;i<=r+p;i++)b[i]=a[i];
	sort(b+r+1,b+r+p+1,cmp);
	merge(b+r+1,b+r+p+1,b+l,b+r+1,c+l);
	for (i=l;i<l+m;i++)
	{
	  if (i>(l+r+p)/2)break;
	  num+=(c[i]-c[r+p-i+l])*(c[i]-c[r+p-i+l]);
	  if (num>k)break;
    }
    //printf("%lld %lld %lld-->%lld\n",l,r,p,num);
	return num;
}
int main()
{
	t=read();
	for (x=1;x<=t;x++)
	{
		n=read(),m=read(),k=read();
    for (i=1;i<=n;i++) a[i]=read();
    r=0;ans=0;l=1;
    while (l<=n)
    {
        p=1;r=l;b[l]=a[l];
    	while(p>0)
    	{
    		if(r+p<=n&&doit(l,r,p)<=k){ 
			  for (i=l;i<=r+p;i++)b[i]=c[i];
			  r=r+p;
			  p=p*2;
			   }else {p=p/2;}
		}
		ans++;l=r+1;
	}
	printf("%lld\n",ans);
    }  
	return 0;
}