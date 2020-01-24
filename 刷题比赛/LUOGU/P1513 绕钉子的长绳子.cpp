#include<iostream>
#include<cmath>
#define maxn 235
using namespace std;
const double PI = acos(-1);
double a[maxn][2];
int main()
{
	double sum = 0;
	int n;
	double r;
	scanf("%d %lf",&n,&r);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i][0] == a[i + 1][0])
			sum = sum + abs(a[i][1] - a[i + 1][1]);
		else if (a[i][1] == a[i + 1][1])
			sum = sum + abs(a[i][0] - a[i + 1][0]);
		else if (i == n)
			sum = sum + sqrt((a[i][1] - a[1][1]) * (a[i][1] - a[1][1]) + (a[i][0] - a[1][0]) * (a[i][0] - a[1][0]));
		else
			sum = sum + sqrt((a[i][1] - a[i + 1][1]) * (a[i][1] - a[i + 1][1]) + (a[i][0] - a[i + 1][0]) * (a[i][0] - a[i + 1][0]));

	}
	sum += 2.0*r*PI;
	printf("%.2f\n",sum);
	return 0 ;
}
