#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans;
int a[100010];
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int tot = 0 ;
int main() {
	int t;
	read(t);
	while (t--) {
		tot = 0;
		ans = 0;
		int n;
		read(n);
		int sum = 0;
		for (int i = 1; i <= n; i++) {read(a[i]);sum += a[i];}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				int tmp;
				read(tmp);
				edge[++tot].x = i;
				edge[tot].y = j;
				edge[tot].z = tmp+a[i]+a[j];
			}
		sort(edge + 1, edge + tot + 1);
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= tot; i++) {
			int x = get(edge[i].x);
			int y = get(edge[i].y);
			if (x == y) continue;
			fa[x] = y;
			ans += edge[i].z;
		}
		cout << ans << endl;
	}
	return 0;
}
