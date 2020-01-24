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
                cout<<s[1] + i <<" ";
                for (int k = 0; k < len[j]; ++k) {
                    if (ext[j][k] > cnt)cnt = ext[j][k];
                   // cout<<ext[j][k]<<" ";
                }
                cout<<endl;
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