/*
#include<bits/stdc++.h>
using namespace std;
char s[6][6];
int a[6][6],b[6][6];
const int ans = 7;
void dj(int i,int j)
{
	b[i][j] ^= 1;
	if(i > 0) b[i-1][j] ^= 1;
	if(i + 1 < 5) b[i+1][j] ^= 1;
	if(j > 1) b[i][j-1] ^= 1;
	if(j + 1 < 5) b[i][j+1] ^= 1;
}
int pd(int p)
{
	int k = 0;
	memcpy(b,a,sizeof(a));
	for(int i = 0;i < 5;i++)
	{
		if(p & (1<<i))
		{
		   k++;
           dj(0,i);
		}
	}
    for(int i = 1;i < 5;i++)
    	for(int j = 0;j < 5;j++)
    	{
    	     if(b[i-1][j] == 0)
    	     {
    	     	if(++k >= ans) return ans;
    	     	dj(i,j);
    	     }	
    	}
    for(int i= 0;i<5;i++)
        if(b[4][i] == 0) return ans;
    return k;
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
	   int step = 1e9;
       for(int i =0;i<5;i++)
       	for(int j=0;j<5;j++)
       	{
       		cin>>s[i][j];
       		a[i][j] = s[i][j]-'0';
       	}
       for(int i =0;i<32;i++) 
       {
       	   int tmp = pd(i);
           if(tmp < step)
           	step = tmp; 
       }
       if(step < ans) printf("%d\n",step);
       else printf("-1\n");
	}
	return 0 ;
}
*/
/*
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#define Inf 0x3f3f3f
#define ll long long
using namespace std;
int t;
int ans;
int a[10][10];
int b[10][10];
int check(int cnt)//判断第一行的条件是否成立
{
    int sum=cnt;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            b[i][j]=a[i][j];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(!b[i][j])
            {
                sum++;
                b[i][j]=!b[i][j];
                b[i+1][j]=!b[i+1][j];
                b[i+1][j-1]=!b[i+1][j-1];
                b[i+1][j+1]=!b[i+1][j+1];
                b[i+2][j]=!b[i+2][j];
 
            }
        }
 
    }
    for(int i=1;i<=5;i++)
        if(!b[5][i])return Inf;
 
    return sum;
 
 
}
int dfs(int cnt,int k)
{
    if(cnt>5)
    {
        ans=min(ans,check(k));
        return 0;
    }
    a[1][cnt]=!a[1][cnt];
    a[1][cnt-1]=!a[1][cnt-1];
    a[1][cnt+1]=!a[1][cnt+1];
    a[2][cnt]=!a[2][cnt];
 
    dfs(cnt+1,k+1);//按下这个开关
 
    a[1][cnt]=!a[1][cnt];
    a[1][cnt-1]=!a[1][cnt-1];
    a[1][cnt+1]=!a[1][cnt+1];
    a[2][cnt]=!a[2][cnt];
 
    dfs(cnt+1,k);//不按下这个开关
}
int main()
{
    scanf("%d",&t);
 
    while(t--)
    {
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                scanf("%1d",&a[i][j]);
        ans=Inf;
        dfs(1,0);
 
        if(ans<7)printf("%d\n",ans);
        else printf("-1\n");
    }
 
    return 0;
}

*/
//Author:XuHt
#include <cstring>
#include <iostream>
using namespace std;
const int N = 6;
int a[N], ans, aa[N];
char s[N];

void dj(int x, int y) {
	aa[x] ^= (1 << y);
	if (x != 1) aa[x-1] ^= (1 << y);
	if (x != 5) aa[x+1] ^= (1 << y);
	if (y != 0) aa[x] ^= (1 << (y - 1));
	if (y != 4) aa[x] ^= (1 << (y + 1));
}

void pd(int p) {
	int k = 0;
	memcpy(aa, a, sizeof(a));
	for (int i = 0; i < 5; i++)
		if (!((p >> i) & 1)) {
			dj(1, i);
			if (++k >= ans) return;
		}
	for (int x = 1; x < 5; x++)
		for (int y = 0; y < 5; y++)
			if (!((aa[x] >> y) & 1)) {
				dj(x + 1, y);
				if (++k >= ans) return;
			}
	if (aa[5] == 31) ans = k;
}

void abc() {
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= 5; i++) {
		cin >> (s + 1);
		for (int j = 1; j <= 5; j++) a[i] = a[i] * 2 + (s[j] - '0');
	}
	ans = 7;
	for (int p = 0; p < (1 << 5); p++) pd(p);
	if (ans == 7) cout << "-1" << endl;
	else cout << ans << endl;
}

int main() {
	int n;
	cin >> n;
	while (n--) abc();
	return 0;
}