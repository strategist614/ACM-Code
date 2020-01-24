/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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
const int N = 205;
int ex[N], Next[N];

string s[4005];
std::vector<string> v;

bool cmp(string a,string b)
{
   if(a.size() == b.size()) return a < b;
   return a.size() > b.size();
}

void getNext(string str)
{
    int i = 0, j, po, len = str.size();
    Next[0] = len;
    while (str[i] == str[i + 1] && i + 1 < len)
        i++;
    Next[1] = i;
    po = 1;
    for (i = 2; i < len; i++)
    {
        if (Next[i - po] + i < Next[po] + po)
            Next[i] = Next[i - po];
        else
        {
            j = Next[po] + po - i;
            if (j < 0)j = 0;
            while (i + j < len && str[j] == str[j + i])
                j++;
            Next[i] = j;
            po = i;
        }
    }
}

void ExKmp(string s1, string s2)
{
    int i = 0, j, po, len = s1.size(), l2 = s2.size();
    getNext(s2);
    while (s1[i] == s2[i] && i < l2 && i < len)
        i++;
    ex[0] = i;
    po = 0;
    for (i = 1; i < len; i++)
    {
        if (Next[i - po] + i < ex[po] + po)
            ex[i] = Next[i - po];
        else
        {
            j = ex[po] + po - i;
            if (j < 0)j = 0;
            while (i + j < len && j < l2 && s1[j + i] == s2[j])
                j++;
            ex[i] = j;
            po = i;
        }
    }
}

int main ()
{
    int n;
    while(scanf("%d",&n) != EOF && n)
    {

    }
	return 0 ;
}
aaaabba
aaaa
*/
/*
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 205;
int nxt[4005][maxn], ext[4005][maxn];
char s[4005][maxn];
int len[4005], ans[maxn];

void EKMP(char s[], char t[], int lens, int lent, int c) {
    int i, j, p, l, k;
    nxt[c][0] = lent; j = 0;
    while (j + 1 < lent && t[j] == t[j + 1])j++;
    nxt[c][1] = j;
    k = 1;
    for (i = 2; i < lent; i++) {
        p = nxt[c][k] + k - 1;
        l = nxt[c][i - k];
        if (i + l < p + 1)nxt[c][i] = l;
        else {
            j = max(0, p - i + 1);
            while (i + j < lent && t[i + j] == t[j])j++;
            nxt[c][i] = j;
            k = i;
        }
    }

    j = 0;
    while (j < lens && j < lent && s[j] == t[j])j++;
    ext[c][0] = j; k = 0;
    for (i = 1; i < lens; i++) {
        p = ext[c][k] + k - 1;
        l = nxt[c][i - k];
        if (l + i < p + 1)ext[c][i] = l;
        else {
            j = max(0, p - i + 1);
            while (i + j < lens && j < lent && s[i + j] == t[j])j++;
            ext[c][i] = j;
            k = i;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        memset(ans, 0x3f, sizeof(ans));
        for (int i = 1; i <= n; ++i)scanf("%s", s[i]);
        for (int i = 1; i <= n; ++i)len[i] = strlen(s[i]);
        int maxx = 0;
        for (int i = 0; i < len[1]; ++i) {
            for (int j = 2; j <= n; ++j) {
                int cnt = 0;
                EKMP(s[j], s[1] + i, len[j], len[1] - i, j);
                for (int k = 0; k < len[j]; ++k) {
                    if (ext[j][k] > cnt)cnt = ext[j][k];
                }
                if (cnt < ans[i])ans[i] = cnt;
            }
            if (ans[i] > maxx)maxx = ans[i];
        }
        if (!maxx)printf("IDENTITY LOST\n");
        else {
            string str[205];
            int cnt = 0;
            for (int i = 0; i < len[1]; ++i)if (ans[i] == maxx) {
                    str[++cnt] = string(s[1] + i, ans[i]);
                }
            sort(str + 1, str + cnt + 1);
            cout << str[1] << endl;
        }
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 4005;
const int M = 205;

int n, m, len, jump[M];
char s[N][M], str[M];

void getJump () {
	int p = 0;
	for (int i = 2; i <= m; i++) {
		while (p > 0 && str[p + 1] != str[i])
			p = jump[p];

		if (str[p + 1] == str[i])
			p++;

		jump[i] = p;
	}
}

int KMP (int j) {
	int ans = 0, p = 0;
	for (int i = 1; i <= len; i++) {
		while (p > 0 && str[p + 1] != s[j][i])
			p = jump[p];

		if (str[p + 1] == s[j][i])
			p++;

		ans = max(p, ans);
		if (p == m) break;
	}
	return ans;
}

bool judge (int p, int q, int k) {
	for (int i = 0; i < k; i++) {
		if (s[0][p + i] != s[0][q + i])
			return s[0][p + i] < s[0][q + i];
	}
	return true;
}

void solve () {
	int ans = 0, rec = 0;
	len = strlen(s[0] + 1);

	for (int i = 1; i < len; i++) {

		strcpy (str + 1, s[0] + i);

		m = strlen (str + 1);

		getJump ();

		int tmp = len;
		for (int j = 1; j < n; j++)
			tmp = min(tmp, KMP(j));

		if (tmp > ans || (tmp == ans && judge (i, rec, ans))) {
			ans = tmp;
			rec = i;
		}
	}

	if (ans) {
		for (int i = 0; i < ans; i++)
			printf("%c", s[0][rec + i]);
		printf("\n");
	} else {
		printf("IDENTITY LOST\n");
	}
}

int main () {
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)
			scanf("%s", s[i] + 1);
		solve ();
	}
	return 0;
}