#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N];
int f[N][N];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0xcf,sizeof(f));
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i= 1;i <= n;i++)
        {
            for(int j =1;j <= m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        f[1][1] = a[1][1];
        for(int i = 1;i <= n;i++)
        {
            for(int j =1;j <= m;j++)
            {
                f[i][j] = max(f[i][j],max(f[i - 1][j] + a[i][j],f[i][j - 1] + a[i][j]));
            }
        }
        printf("%d\n",f[n][m]);
    }
    return 0;
}