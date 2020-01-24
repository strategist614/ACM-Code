#include <iostream>
#include <cstring>
using namespace std;
const int N = 20;
int n,m;
int a[N][N],b[N][N],f[N][N];
int ans[N][N];
int anum = 10000,fnum = 0;
void dj(int i,int j)
{
	f[i][j] = 1;
	b[i][j] ^= 1;
	fnum++;
	b[i-1][j] ^= 1;
	b[i+1][j] ^= 1;
	b[i][j-1] ^= 1;
	b[i][j+1] ^= 1;
}
void record()
{
	anum = fnum;
	for(int i= 1;i<=n;i++)
		for(int j= 1;j<=m;j++)
			ans[i][j] = f[i][j];
}
int main ()
{
    cin>>n>>m;
    for(int i= 1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		cin>>a[i][j];
    for(int i= 0;i<(1<<m);i++)
    {
    	memcpy(b,a,sizeof(a));
    	fnum = 0;
    	memset(f,0,sizeof(f));
      int mo = i;
    	for(int j= 1;j<=m;j++)
    	{
    		if(mo & 1) dj(1,j);
    		mo >>= 1;
    	}
    	for(int i= 2;i<=n;i++)
    		for(int j =1;j <= m;j++)
    			{
    				if(b[i-1][j]) dj(i,j);
    			}
        int j;
        for( j = 1;j<=m;j++)
        {
        	if(b[n][j])break;
        }
        if(j == m+1 && fnum < anum) record();
    }
    if(anum == 10000) cout << "IMPOSSIBLE" << endl;
    else 
    {`
    	for(int i = 1; i <= n; i ++){
        cout << ans[i][1];
        for(int j = 2; j <= m; j ++){
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    }
	return 0 ;
}