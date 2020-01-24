//Author:XuHt
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 106, INF = 0x3f3f3f3f;
char c[N];
int a[N], fmax[N][N], fmin[N][N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		cin >> a[i];
	}
	for (int i = n + 1; i <= (n << 1); i++) {
		c[i] = c[i-n];
		a[i] = a[i-n];
	}
	memset(fmax, 0xcf, sizeof(fmax));
	memset(fmin, 0x3f, sizeof(fmin));
	for (int i = 1; i <= (n << 1); i++) fmax[i][i] = fmin[i][i] = a[i];
	for (int len = 2; len <= n; len++)
		for (int l = 1; l + len - 1 <= (n << 1); l++) {
			int r = l + len - 1;
			for (int k = l + 1; k <= r; k++)
				if (c[k] == 't') {
					fmax[l][r] = max(fmax[l][r], fmax[l][k-1] + fmax[k][r]);
					fmin[l][r] = min(fmin[l][r], fmin[l][k-1] + fmin[k][r]);
				} else {
					fmax[l][r] = max(fmax[l][r], max(fmax[l][k-1] * fmax[k][r], fmin[l][k-1] * fmin[k][r]));
					fmin[l][r] = min(fmin[l][r], min(fmax[l][k-1] * fmax[k][r], min(fmin[l][k-1] * fmin[k][r], min(fmax[l][k-1] * fmin[k][r], fmin[l][k-1] * fmax[k][r]))));
				}
		}
	int ans = -INF;
	for (int i = 1; i <= n; i++) ans = max(ans, fmax[i][i+n-1]);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if (ans == fmax[i][i+n-1])
			cout << i << " ";
	return 0;
}
/*
#include <cstdio>
#include <memory.h>
#include <climits>
#include <algorithm>
using namespace std;
const int MAX = 122;
 
char edg[MAX][2];
int vet[MAX];
int dp1[MAX / 2][MAX / 2], dp2[MAX / 2][MAX / 2];
int final[MAX];
int N;
 
int main(int argc, char const *argv[]){
	int ans_max = INT_MIN, N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s %d", edg[i], &vet[i]);
		edg[i + N][0] = edg[i][0];
		vet[i + N] = vet[i];
	}
 
	//enumerate every cutting point
	for(int k = 0; k < N; ++k){
		//base cases
		for(int i = 0; i < N; ++i){
			dp1[i][i] = vet[k + i];
			dp2[i][i] = vet[k + i]; 
		}
		//do DP for every line after cutting
		for(int i = 1; i < N; ++i){
			for(int j = 0; j + i< N; ++j){
				int maxv = INT_MIN, minv = INT_MAX;
				for(int p = j; p < j + i; ++p){
					if(edg[p + k + 1][0] == 't'){
						maxv = max(maxv, dp1[j][p] + dp1[p + 1][j + i]);
						minv = min(minv, dp2[j][p] + dp2[p + 1][j + i]);
					}else{
						//minimum times minimum might result in maximum
						maxv = max(maxv, dp1[j][p] * dp1[p + 1][j + i]);
						maxv = max(maxv, dp1[j][p] * dp2[p + 1][j + i]);
						maxv = max(maxv, dp2[j][p] * dp1[p + 1][j + i]);
						maxv = max(maxv, dp2[j][p] * dp2[p + 1][j + i]);
						//vice versa
						minv = min(minv, dp1[j][p] * dp1[p + 1][j + i]);
						minv = min(minv, dp1[j][p] * dp2[p + 1][j + i]);
						minv = min(minv, dp2[j][p] * dp1[p + 1][j + i]);
						minv = min(minv, dp2[j][p] * dp2[p + 1][j + i]);
					}
				}
				dp1[j][j + i] = maxv;
				dp2[j][j + i] = minv;
			}
		}
		ans_max = max(ans_max, dp1[0][N - 1]);
		final[k] = dp1[0][N - 1];
	}
	printf("%d\n", ans_max);
	for(int i = 0; i < N; ++i){
		if(final[i] == ans_max){
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	return 0;
}
*/