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
const int N = 10010;
int fa[N];
struct rec
{
	int x;
	int y;
	double z;
};
bool operator <(rec a, rec b) {
	return a.z < b.z;
}

std::vector<rec> v;

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void merge(int root1, int root2) {
	int fr1 = get(root1);
	int fr2 = get(root2);
	fa[fr1] = fr2;
	get(root1);
	get(root2);
}

double x[N], y[N];

double dis(int p, int q) {
	double xx = x[p] - x[q];
	double yy = y[p] - y[q];
	return sqrt(xx * xx + yy * yy);
}

int main ()
{
	int t;
	read(t);
	while (t--)
	{
		int n;
		read(n);
		v.clear();
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
			for (int j = 1; j < i; j++) {
				v.push_back( (rec) {j, i, dis(i, j)} );
			}
		}
		sort(v.begin(), v.end());
		int m ;
		read(m);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			read(a);
			read(b);
			merge(a,b);
		}
		int flag = 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (get(v[i].x) != get(v[i].y))
			{
				flag = 0;
			    merge(v[i].x,v[i].y);
				printf("%d %d\n", v[i].x, v[i].y);
			}
		}
		if (flag) printf("No new highways need\n");
		if (t) printf("\n");
	}
	return 0 ;
}
