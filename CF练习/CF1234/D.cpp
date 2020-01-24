#include<bits/stdc++.h>
 
using namespace std;
 
void add(int x);
void del(int x);
void modify(int x, int ti); //这个函数会执行或回退修改ti（执行还是回退取决于是否执行过，具体通过swap实现），x表明当前的询问是x，即若修改了区间[q[x].l,q[x].r]便要更新答案
 
int m, B, cnt[1000010], a[100010], ans, ccnt, qcnt, now, out[100010];
char s[100010];
struct Change
{
	int p;
	int col;
} c[100010];
 
struct Query
{
	int l, r, t, id;
	bool operator<(Query& b)
	{
		return l / B == b.l / B ? (r / B == b.r / B ? t < b.t : r < b.r) : l < b.l;
	}
} q[50010];
 
int main()
{
	int i, l = 2, r = 1;
	char type[10];
 
	//cin>>n>>m;
	//B=pow(n,0.66666);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - 'a' + 1;
	cin >> m;
	B = pow(n, 0.66666);
 
	for (i = 1; i <= m; ++i)
	{
		int op;
		scanf("%d", &op);
		if (op == 2)
		{
			++qcnt;
			cin >> q[qcnt].l >> q[qcnt].r;
			q[qcnt].t = ccnt;
			q[qcnt].id = qcnt;
		}
		else
		{
			++ccnt;
			char x[20];
			cin >> c[ccnt].p >> x;
			c[ccnt].col = x[0] - 'a' + 1;
		}
	}
 
	sort(q + 1, q + qcnt + 1);
 
	for (i = 1; i <= qcnt; ++i)
	{
		while (l > q[i].l)
		{
			add(a[--l]);
		}
		while (r < q[i].r)
		{
			add(a[++r]);
		}
		while (l < q[i].l)
		{
			del(a[l++]);
		}
		while (r > q[i].r)
		{
			del(a[r--]);
		}
		while (now < q[i].t)
		{
			modify(i, ++now);
		}
		while (now > q[i].t)
		{
			modify(i, now--);
		}
		out[q[i].id] = ans;
	}
 
	for (i = 1; i <= qcnt; ++i)
	{
		cout << out[i] << endl;
	}
 
	return 0;
}
 
void add(int x)
{
	if (cnt[x]++ == 0)
	{
		++ans;
	}
}
 
void del(int x)
{
	if (--cnt[x] == 0)
	{
		--ans;
	}
}
 
void modify(int x, int ti)
{
	if (c[ti].p >= q[x].l && c[ti].p <= q[x].r)
	{
		del(a[c[ti].p]);
		add(c[ti].col);
	}
	swap(a[c[ti].p], c[ti].col); //下次执行时必定是回退这次操作，直接互换就可以了
}