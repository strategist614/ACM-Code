/*
独立思考
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
const int N = 1e6 + 6;
bool Isprime[N]; 
int prime[N];
int t, tot = 0;
ll ab, b;
void Prime()
{
    //k = 0;
    memset(Isprime, true, sizeof(Isprime));
    Isprime[1] = false;
    for(int i = 2 ; i < N ; i++)
    {
        if(Isprime[i])
        {
            prime[++tot] = i;
            for(int j = 2 ; i * j < N ; j++)
                Isprime[i * j] = false;
        }
    }
}//素数筛选

ll solve(ll x)
{
	ll ans = 1;
	for (int i = 1; i <= tot && prime[i]*prime[i] <= x; i++)
	{
		ll tmp = 0;
		if (x % prime[i] == 0)
		{
			while (x % prime[i] == 0)
			{
				tmp++;
				x /= prime[i];
			}
			ans *= (tmp + 1);
		}
	}
	if (x > 1)
		ans *= 2;
	return ans;
}

int main ()
{
	Prime();
	scanf("%d", &t);
	int flag = 0;
	while (t--)
	{
		scanf("%lld %lld", &ab, &b);
		if (ab < b * b)
		{
			printf("Case %d: 0\n", ++flag);
			continue;
		}
		ll ans = solve(ab);
		ans /= 2;
		for (ll i = 1; i < b; i++)
		{
			if (ab  % i == 0)
				ans--;
		}
		printf("Case %d: %lld\n", ++flag, ans);
	}
	return 0 ;
}
*/
/*
独立思考
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
const int N = 1e6 + 6;
int prime[N], is_prime[N];
int t, tot = 0;
ll ab, b;
void seive()
{
	for (int i = 0; i <= N; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = 2 * i; j <= N; j += i) is_prime[j] = 0;
		}
	}
}

ll solve(ll x)
{
	ll ans = 1;
	for (int i = 1; i <= tot && prime[i]*prime[i] <= x; i++)
	{
		ll tmp = 0;
		if (x % prime[i] == 0)
		{
			while (x % prime[i] == 0)
			{
				tmp++;
				x /= prime[i];
			}
			ans *= (tmp + 1);
		}
	}
	if (x > 1)
		ans *= 2;
	return ans;
}

int main ()
{
	seive();
	scanf("%d", &t);
	int flag = 0;
	while (t--)
	{
		scanf("%lld %lld", &ab, &b);
		if (ab < b * b)
		{
			printf("Case %d: 0\n", ++flag);
			continue;
		}
		ll ans = solve(ab);
		ans /= 2;
		for (ll i = 1; i < b; i++)
		{
			if (ab  % i == 0)
				ans--;
		}
		printf("Case %d: %lld\n", ++flag, ans);
	}
	return 0 ;
}
