#### CodeForces 17D

* 题目

  [17D](https://codeforces.com/contest/17/problem/D)

* 分析

  $b$ 进制下 $n$ 位数有多少个，每一页能放 $c$ 个，最后一页有多少个。。。

  $b$ 进制下每一位能放的数字是 $0 \sim b - 1$ ,因为第一个数不能放 $0$ 所以第一位数可以放 $1 \sim b - 1$,剩余 $n - 1$ 位可以放 $b$ 个数，所以答案就是 $(b - 1) \times b^{n - 1} \pmod c$ 

  这里$n$ 非常大，所以可以使用欧拉降幂，题目时限没有给 $java$ 放，所以不要想着偷鸡了。。。（没偷成功的我。。

* 代码 

  ```c++
  ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
  ll ksm(ll a, ll b, ll mod)
  {
  	ll ans = 1 % mod;
  	while (b)
  	{
  		if (b & 1) ans = ans * a % mod;
  		a = a * a % mod;
  		b >>= 1;
  	}
  	return ans % mod;
  }
  
  ll phi(ll n) {
  	ll ans = n;
  	for (int i = 2; i * i <= n; i++) {
  		if (n % i == 0) { // i是质数
  			ans = ans / i * (i - 1);
  			while (n % i == 0) n /= i;
  		}
  	}
  	if (n > 1) // n是质数
  		ans = ans / n * (n - 1);
  	return ans;
  }
  
  ll cal(string s, ll mod)
  {
  	ll ans = 0;
  	for (int i = 0; i < s.size(); i++)
  	{
  		ans = ans * 10 + s[i] - '0';
  		ans %= mod;
  	}
  	return ans;
  }
  
  int main ()
  {
  	//freopen("input.in", "r", stdin);
  	//freopen("test.out", "w", stdout);
  	string b, n;
  	ll c;
  	cin >> b >> n >> c;
  	ll p = phi(c);
  	ll bb = cal(b, c);
  	ll nn = 0;
  	int vis = 0;
  	for(int i = 0;i < n.size();i++)
  	{
  		nn = nn * 10 + n[i] - '0';
  		if(nn - 1 >= p)
  		{
  			vis = 1;
  			nn %= p;
  		}
  	}
  	if(vis) nn += p; // 广义欧拉降幂
  	ll ans = (ksm(bb,nn - 1,c) * (bb - 1) + c) % c;
  	if(ans) printf("%lld\n",ans);
  	else printf("%lld\n",c); 
  	return 0 ;
  }
  ```

  

* 题型

  欧拉降幂