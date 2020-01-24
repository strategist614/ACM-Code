#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
const int N = 5e5+5;
int a[N];
int b[N];
long long cnt = 0;
void merge(int l, int mid, int r) {
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
		if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i++];
		else b[k] = a[j++], cnt += mid - i + 1;
	for (int k = l; k <= r; k++) a[k] = b[k];
}
void mergesort(int l,int r)
{
	if(l < r)
	{
		int mid = (l+r)>>1;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
int main ()
{
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
    cnt = 0;
    for(int i = 1;i<=n;i++) read(a[i]);
    mergesort(1,n);
    out(cnt);
    puts("");
}
	return 0 ;
}