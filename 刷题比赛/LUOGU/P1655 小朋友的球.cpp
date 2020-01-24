#include <stdio.h>
#include<iostream>
#include <string.h>
#include<stdlib.h>
#include<algorithm>
typedef long long ll;
using namespace std;
ll maxx(ll x, ll y) {
	if (x < y)return y;
	return x;
}
struct node {
	ll a[1000], len;
	node() {memset(a, 0, sizeof(a)); len = 0;}
};
node t[111][111];
node operator + (node c, node d) {
	node h; h.len = maxx(c.len, d.len);
	int i;
	for (i = 1; i <= h.len; i++) {
		h.a[i] += c.a[i] + d.a[i];
		if (h.a[i] >= 10) {
			h.a[i + 1] += h.a[i] / 10;
			h.a[i] %= 10;
			if (i == h.len)h.len++;
		}
	}
	return h;
}
node operator * (node c, ll u) {
	node h; h.len = c.len;
	int i;
	for (i = 1; i <= h.len; i++) {
		h.a[i] += c.a[i] * u;
		if (h.a[i] >= 10) {
			h.a[i + 1] += h.a[i] / 10;
			h.a[i] %= 10;
			if (i == h.len)h.len++;
		}
	}
	return h;
}

int main() {
	int n, m;
	for (int i = 1; i <= 100; i++) {
		t[i][0].a[1] = 0, t[i][i].a[1] = t[i][1].a[1] = 1, t[i][0].len = t[i][i].len = t[i][1].len = 1;
	}
	for (int i = 2; i <= 100; i++)
	{
		for (ll j = 2; j <= i - 1; j++)
			t[i][j] = t[i - 1][j - 1] + t[i - 1][j] * j;
	}	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m == 0 || m > n) {printf("0\n"); continue;}
		for (int i = t[n][m].len; i >= 1; i--) printf("%lld", t[n][m].a[i]);
		puts("");
	}
	return 0;
}