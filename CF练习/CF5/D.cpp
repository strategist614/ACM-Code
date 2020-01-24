#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//solve a*x^2 + bx + c = 0; get its positive solution
double solve_equ(double a, double b, double c) {
	return (sqrt(b * b - 4 * a * c) - b ) / 2 / a;
}

//initial speed is v0, max v is maxv
//acceleration is a, distance is s
//get the mininum time
double solve(double v0, double maxv, double a, double s) {
	double acs = (maxv * maxv - v0 * v0) / a / 2;
	if (acs > s) return solve_equ(a / 2, v0, -s);

	return ((maxv - v0) / a + (s - acs) / maxv);
}

int main() {
	double a, v, l, d, w;
	scanf("%lf %lf %lf %lf %lf", &a, &v, &l, &d, &w);

	double ans = 0;
	if (v <= w) {
NO_LIMIT:
		ans = solve(0, v, a, l);
	} else {
		double start = (2 * v * v - w * w) / 2 / a;
		if (start < d) {
			ans += ((2 * v - w) / a); // v/a + (v-w)/a
			ans += ((d - start) / v); // move with constant speed
		} else {
			if (w * w / a / 2 < d) {
				ans += w / a + 2 * solve_equ(a, 2 * w, w * w / 2 / a - d);//time to get d
			} else {
				goto NO_LIMIT;
			}
		}
		ans += solve(w, v, a, l - d); // time after d
	}

	printf("%.5lf\n", ans);
	return 0;
}