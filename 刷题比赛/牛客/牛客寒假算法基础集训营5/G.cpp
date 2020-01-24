#include<bits/stdc++.h>
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
using namespace std;
int tmp[1000], cnt, rec[1000];
int prime[30] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39, 41, 43, 47};
double ans, LOG[30];

void DFS(int pos, int val, int MAX, double clog) {
    if (clog > ans) return;
    if (val == 1) {
        cnt = pos;
        ans = clog;
        for (int i = 1; i < pos; i++)
            rec[i] = tmp[i];
        return;
    }

    for (int i = 1; i * i <= val && i <= MAX; i++) {
        if (val % i == 0) {
            if (i != 1) {
                tmp[pos] = i;
                DFS(pos+1, val/i, i, clog + LOG[pos] * (i-1));
            }
            if (val / i <= MAX && val / i != i) {
                tmp[pos] = val/i;
                DFS(pos+1, i, val/i, clog + LOG[pos] * (val/i - 1));
            }
        }
    }
}
map<int,int> mp;
int main() {
       int N;
       for (int i = 0; i < 16; i++)
         LOG[i] = log((double)prime[i]);
       for(int N = 1;N <= 2000;N++)
       {
        ans = 0x3f3f3f3f;
        DFS(1, N, N, 0);
        long long M = 1;
        for (int i = 1; i < cnt; i++)
            for (int j = 1; j < rec[i]; j++)
                M *= prime[i];
        if(M > 1e6 || M <= 0) mp[N] = -1; 
        else mp[N] = M;
    }
    int t;
    cin>>t;
    while(t--)
    {
    	int x;
    	read(x);
    	if(x > 240) {
    		out(-1);
    		puts("");
    		continue;
    	}
        if(mp[x] != -1) {
        	int ans = mp[x];
        	out(ans);
        	puts("");
        }
        else {
        	out(-1);
        	puts("");
        }
   }
    return 0;
}
