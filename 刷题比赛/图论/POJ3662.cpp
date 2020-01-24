#include <bits/stdc++.h>
using namespace std;
int sum[1000100];
int n, m, a[500100], ans, wfl, wfr;
inline int read()
{
	int X = 0; char ch = 0;
	while (ch < 48 || ch > 57)ch = getchar();
	while (ch >= 48 && ch <= 57)X = X * 10 + (ch ^ 48), ch = getchar();
	return X;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)a[i] = read();
	scanf("%d", &m);
	register int l = 1, r = 0;
	//两个指针一开始指向一个空区间
	for (int i = 1; i <= m; ++i) {
		wfl = read(); wfr = read();
		while (l < wfl) {
			ans -= !(--sum[a[l]]);
			l++;
			//左边太多了,砍掉一些
		} while (l > wfl) {
			l--;
			ans += !(sum[a[l]]++);
			//左边太少了,加入一些
		} while (r > wfr) {
			ans -= !(--sum[a[r]]);
			r--;
		} while (r < wfr) {
			++r;
			ans += !(sum[a[r]]++);
		}//r指针同理;
		//想学莫队,先得搞清楚c++和++c的(返回值)区别
		for(int i= 1; i <= 6;i++)
			cout << sum[i] << endl;
		//printf("%d\n", ans);
	} return 0;
}