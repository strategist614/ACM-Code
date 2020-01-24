//扫描线
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
const int N = 5005;
const int inf = 0x3f3f3f3f;
int sum[N][N];
short A[N][N];
int main()
{
	int n,m;
	read(n);
	read(m);
	int r ,c;
	r = c = m;
	for(int i = 1;i<=n;i++)
	{
		int x,y,w;
		read(x);
		read(y);
		read(w);
		x++;
		y++;
        A[x][y] = w;
        r = max(r,x);
        c = max(c,y);
	}
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++)
		{
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+A[i][j];
		}
	int ans = -inf;
	for(int i= m;i<=r;i++)
		for(int j = m;j<=c;j++)
		{
		    int tmp = sum[i][j] - sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m];
		    ans = max(ans,tmp);
		}
	cout<<ans<<endl;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int sum[5005][5005];
int main ()
{
    int n,r;
    cin>>n>>r;
    for(int i = 1;i<=n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	x++;
    	y++;
    	int a;
    	cin>>a;
        sum[x][y] += a;
    }
    for(int i = 1;i<=5001;i++)
    	for(int j = 1;j<=5001;j++)
    		sum[i][j] += sum[i-1][j];
    for(int i = 1;i<=5001;i++)
    	for(int j= 1;j<=5001;j++)
    		sum[i][j] += sum[i][j-1];
    int ans = -inf;
    for(int i= r;i<=5001;i++)
    	for(int j= r;j<=5001;j++)
    	{
    	    int tmp = sum[i][j] - sum[i-r][j]-sum[i][j-r]+sum[i-r][j-r];
		    ans = max(ans,tmp);
    	}
    cout<<ans<<endl;
	return 0 ;
}