/*
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 3010, L = 1000;
 
int n, m;
int a[N][N], b[N][N], c[N][N], d[N][N];
 
void up(int x, int y, int l)
{
    a[x - l / 2][y] ++, b[x - l / 2][y + 1] -- ;
    a[x + 1][y - l / 2 - 1] --, b[x + 1][y + l / 2 + 2] ++ ;
}
 
void down(int x, int y, int l)
{
    c[x + 1][y - l / 2 + 1] ++, d[x + 1][y + l / 2] -- ;
    c[x + l / 2 + 1][y + 1] --, d[x + l / 2 + 1][y] ++ ;
}
 
int main()
{
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < q; i ++ )
    {
        int opt, x, y, l;
        scanf("%d%d%d%d", &opt, &x, &y, &l);
        x += L, y += L;
        up(x, y, l);
        if (opt == 1) down(x, y, l);
    }
     
    int res = 0;
    for (int i = 1; i <= L * 2; i ++ )
    {
        int t = 0;
        for (int j = 1; j <= L * 2 + m; j ++ )
        {
            t += a[i][j] + b[i][j] + c[i][j] + d[i][j];
           // cout<<a[i][j]<<endl;
            if (i >= L + 1 && i <= L + n && j >= L + 1 && j <= L + m) 
            {
                 if(i == L+2 && j == L + 3) 
                 {
                    cout<<a[i][j]<<endl;
                    cout<<b[i][j]<<endl;
                    cout<<c[i][j]<<endl;
                    cout<<d[i][j]<<endl;
                    cout<<t<<endl;
                }
            }
            //if(i == 1002 && j == 1002) {cout<<a[i][j]<<a[i+1][j-1]<<endl;}
            a[i + 1][j - 1] += a[i][j];
            b[i + 1][j + 1] += b[i][j];
            c[i + 1][j + 1] += c[i][j];
            d[i + 1][j - 1] += d[i][j];
            //if(i == 1002 && j == 1002) {cout<<a[i][j]<<a[i+1][j-1]<<endl;}
        }
    }
     
    cout << res << endl;
     
    return 0;
}
/*
4 5 2
1 2 2 1
1 3 3 5
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 3010, L = 1000;
int n,m,q;
int a[N][N],b[N][N],c[N][N],d[N][N];

void up(int x,int y,int l)
{
   a[x-l/2][y]++;b[x-l/2][y+1]--;
   a[x+1][y-l/2-1]--;b[x+1][y+l/2+2]++;
}

void down(int x,int y,int l)
{
   c[x+1][y-l/2+1]++;d[x+1][y+l/2]--;
   c[x+l/2+1][y+1]--;d[x+l/2+1][y]++;
}

int main ()
{
    int n,m,q;
    cin>>n>>m>>q;
    while(q--)
    {
        int opt,x,y,l;
        scanf("%d %d %d %d",&opt,&x,&y,&l);
        x += L;y+=L;
        up(x,y,l);
        if(opt == 1) down(x,y,l);
    }
    int ans = 0;
    for(int i = 1;i<=2*L;i++)
    {
        int t = 0;
        for(int j = 1;j <= 2*L+m;j++)
        {
             t += a[i][j]+b[i][j]+c[i][j]+d[i][j];
             if(i >= L + 1 && i <= L + n && j >= L +1 && j <= L + m) {ans ^= t;}
             a[i+1][j-1]+=a[i][j];
             b[i+1][j+1]+=b[i][j];
             c[i+1][j+1]+=c[i][j];
             d[i+1][j-1]+=d[i][j];
        }
    }
    cout<<ans<<endl;
    return 0 ;
}