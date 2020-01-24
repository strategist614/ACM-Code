#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<math.h>
using namespace std;
const int N = 301;
const int INF = 0x3f3f3f3f;
double a[301][301];
double d[301];
bool v[301];
int n, m;
struct sppp
{
	int x;
	int y;
} Point[N];
double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

int main() {
	int n;
	int flag = 0;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 1; i <= n; i++) a[i][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &Point[i].x, &Point[i].y);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				double dx = dis(Point[i].x, Point[i].y, Point[j].x, Point[j].y);
				a[i][j] = dx;
				a[j][i] = dx;
			}
		}
		for (int i = 2; i <= n; i++) d[i] = a[1][i];
		memset(v, 0, sizeof(v));
		d[1] = 0.0;
		for (int i = 1; i < n; i++) {
			int x = 0;
			double minn = INF;
			for (int j = 1; j <= n; j++)
			{
				if (!v[j] && d[j] < minn)
				{
					minn = d[j];
					x = j;
				}
			}
			v[x] = 1;
			for (int y = 1; y <= n; y++)
			{
				if (!v[y] && d[y] > max(d[x], a[x][y]))
				{
					d[y] = max(d[x], a[x][y]);
				}
			}
		}
		printf("Scenario #%d\n", ++flag);
		printf("Frog Distance = %.3f\n\n", d[2]);
	}
	return 0;
}
