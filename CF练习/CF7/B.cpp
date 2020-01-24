/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int a[105];
unordered_map<int, pair<int, int>> mp;
int n;
int num;
void debug()
{
	for(int i =1;i <= n;i++)
				cout << a[i] << endl;
}
void add()
{
	int d; 
	read(d);
	int flag = -1;
	for(int i= 1;i <= n;i++)
	{
        int p = 0;
        for(int j = i;j <= i + d - 1 && j <= n;j++)
        	if(a[j] == 0) p++;
        if(p == d)
        {
        	flag = i;
        	break;
        }
	}
	if(flag != -1)
	{
		num++;
        for(int i = flag;i <= flag + d - 1;i++)
        	a[i] = num;
        printf("%d\n",num);
	}
	else 
	{
		printf("NULL\n");
		return ;
	}
}
void del()
{
	int d;
	read(d);
	if(d <= 0){printf("ILLEGAL_ERASE_ARGUMENT\n");return;}
	int flag = -1;
	for(int i = 1;i <= n;i++)
	{
        if(a[i] == d)
        {
        	flag = 1;
        	a[i] = 0;
        } 
	}
	if(flag == -1)
	{
		printf("ILLEGAL_ERASE_ARGUMENT\n");
	}
}
void d()
{
	int j = 0;
	for(int i = 1;i <= n;i++) if(a[i]) {a[++j] = a[i];}
	j++;
	for(;j <= n;j++) a[j] = 0;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	read(q);
	read(n);
	int cnt = 0;
	while (q--)
	{
		char s[20];
		scanf("%s",s);
		int x;
		if (s[0] == 'a')
		{
			add();
		}
		else if (s[0] == 'e')
		{
			del();
		}
		else
		{
			d();
		}
	}
	return 0 ;
}
/*
14 100
alloc 99  1
alloc 1   2
alloc 1   NULL
erase 2   
alloc 1   3
erase 4   ILLEGAL_ERASE_ARGUMENT
erase 1   
alloc 100  NULL
alloc 1    4
alloc 99   NULL
defragment  
erase 4  
alloc 100  NULL
alloc 99   NULL


1
2
NULL
3
ILLEGAL_ERASE_ARGUMENT
NULL
4
NULL
NULL
NULL
*/