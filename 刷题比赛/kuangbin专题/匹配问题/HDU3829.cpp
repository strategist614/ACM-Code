/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int n, m, p;
const int N = 100005;
int head[N], ver[N], Next[N];
int tot = 0;
int v[N], match[N];
struct node
{
	string like;
	string dis;
};
node cat[N],dog[N];
int cat_num = 0,dog_num = 0;
void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

bool dfs(int x) {
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!v[y]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	string a,b;
	while (~scanf("%d %d %d", &n, &m, &p)) {
		cat_num = 0,dog_num = 0;
		tot = 0;
		memset(head,0,sizeof(head));
		memset(match,0,sizeof(match));
		for (int i = 1; i <= p; i++)
		{ 
              cin>>a>>b;
              if(a[0] == 'C'){
              	cat[++cat_num].like = a;
              	cat[cat_num].dis = b;
              } 
              if(a[0] == 'D'){
              	dog[++dog_num].like = a;
              	dog[dog_num].dis = b;
              }
		}
		for(int i = 1;i <= cat_num;i++)
		{
			for(int j = 1;j <= dog_num;j++){
				if(cat[i].like == dog[j].dis || cat[i].dis == dog[j].like)
				{
					add(i,j);
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= cat_num;i++){
			memset(v,0,sizeof(v));
			if(dfs(i)) ans++;
		}
        cout<<cat_num+dog_num - ans<<endl; 
	}
	return 0 ;
}