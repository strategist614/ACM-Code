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
const int N = 105;
const int mod = 1e9+7;
struct mat
{
	ll a[N][N];
};
ll n,k;
mat ans,e;
mat mul(mat x,mat y) //矩阵乘 
{
    mat c;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        c.a[i][j]=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
        {
            c.a[i][j]=c.a[i][j]%mod+x.a[i][k]*y.a[k][j]%mod;
          }
    return c; 
}
mat ksm(mat x,ll y)
{
	mat ans = e;
	while(y)
	{
		if(y & 1) {
			ans = mul(ans,x);
		}
		x = mul(x,x);
		y >>= 1; 
	}
	return ans;
}
int main ()
{
	cin>>n>>k;
	for(int i= 1;i<=n;i++)
		for(int j =1;j<=n;j++)
			cin>>ans.a[i][j];
    for(int i= 1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		e.a[i][i] = 1;
    mat tmp = ksm(ans,k);
    for(int i= 1;i<=n;i++){
    	for(int j=1;j<=n;j++)
            cout<<tmp.a[i][j]%mod<<" ";
        cout<<endl;
    }
	return 0 ;
}

/*
#include<iostream>
#include<cstring>
#define mod 1000000007
#define ll long long
using namespace std;
struct Mat{
    ll m[101][101];
};//结构体存矩阵 
Mat a,e;//a是输入的矩阵，e是单位矩阵 
ll n,p;
Mat Mul(Mat x,Mat y) //矩阵乘 
{
    Mat c;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        c.m[i][j]=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
        {
            c.m[i][j]=c.m[i][j]%mod+x.m[i][k]*y.m[k][j]%mod;
          }
    return c; 
}
Mat pow(Mat x,ll y) //矩阵快速幂 
{
    Mat ans=e;
    while(y)
    {
        if(y&1)
        { ans=Mul(ans,x); 
          //cout<<1<<endl;

        } 
        x=Mul(x,x);
        y>>=1;
    }
    return ans;
}

int main()
{
    //输入 
    cin>>n>>p;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>a.m[i][j];
     //算法核心     
    for(int i=1;i<=n;i++)
        e.m[i][i]=1;    
    Mat ans=pow(a,p);
    //输出 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
          cout<<ans.m[i][j]%mod<<" ";
        cout<<endl;
    }  

    return 0;
}
*/