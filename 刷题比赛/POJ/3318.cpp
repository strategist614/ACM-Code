#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int a[505][505],b[505][505],c[505][505];
int main()
{
	srand((unsigned)time(0));
	int n;
	scanf("%d",&n);
    for(int i= 1;i <= n;i++)
       for(int j= 1;j<=n;j++)
       	 scanf("%d",&a[i][j]);
    for(int i= 1;i <= n;i++)
    	for(int j= 1;j<=n;j++)
    	 scanf("%d",&b[i][j]);
    for(int i= 1;i<=n;i++)
        for(int j= 1;j<=n;j++)
         scanf("%d",&c[i][j]);
    int flag = 1;
    for(int i= 1;i<=100001&&flag;i++)
    {
         int x,y;
         x = rand()%n+1;
         y = rand()%n+1;
         int tmp = 0;
         for(int k = 1;k<=n;k++)
            tmp += a[x][k] * b[k][y];
         if(tmp != c[x][y]) flag = 0;  
    }	
    if(flag) puts("YES");
    else puts("NO");
    return 0 ;
}