#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char S[maxn];
char F[maxn];
char T[maxn];
int N;
int miniexpress(char* s) {
    int p = 0, q = 1;
    while (p < N && q < N) {
        int i;
        for (i = 0; i < N; i++) {
            if (s[(p+i)%N] != s[(q+i)%N])
                break;
        }

        if (s[(p+i)%N] > s[(q+i)%N])
            p = p + i + 1;
        else
            q = q + i + 1;

        if (p == q)
            q++;
    }
    return min(p, q) + 1;
}

void solve () {
    char tmp[maxn];
    memset(tmp, 0, sizeof(tmp));
    int pos = miniexpress(T) - 1;

    for (int i = 0; i < N; i++)
        tmp[i] = T[(pos + i) % N];
    if (strcmp(F, tmp) > 0)
        strcpy(F, tmp);
}
int main ()
{
	scanf("%d %s",&N,S);
	strcpy(F,S);
	for(int i = 0;i < 10;i++)
	{
		for(int j = 0;j<N;j++)
			T[j] = '0'+(S[j]-'0'+ i)%10;
		solve();
	}
	printf("%s\n",F);
	return 0 ;
}
/*

#include<bits/stdc++.h>
using namespace std;
int miniexpress(char* s) {
    int n = strlen(s+1);
    for(int i =1;i<=n;i++) s[n+i] = s[i];
    int i = 1,j = 2,ans,k;
    while(i <= n && j <= n)
    {                                                                                
    	for(k = 0;k <= n && s[i+k] == s[j+k];k++);
    	if(k == n) break;
        if(s[i+k] > s[j+k])
        {
        	i = i+k+1;
        	if(i == j) i++;
        }
        else 
        {
        	j = j+k+1;
        	if(i == j) j++;
        }
    }
    ans = min(i,j);
    return ans;
}
int main ()
{
	char s[100];
	scanf("%s",s+1);
    cout<<miniexpress(s)<<endl;
	return 0 ;
}

*/