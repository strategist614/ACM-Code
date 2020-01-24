#### CodeForces 13E

* 题目

  [13E](https://cn.vjudge.net/problem/CodeForces-13E)

* 分析

  分块：预处理当前块当中每个数需要多少次跳出当前块以及这个数最后到了下一个块中的哪个位置或者跳出去了。

  注意：预处理当前块的值，就是只考虑当前块的答案。。。因为要求跳出之前在哪里跳出的，所以 $i + a[i] > n$ 情况是要给一个 $-1$ 标记的，又因为 $i$ 位置之前的能够跳到 $i$ 位置 $to[j]$ 会继承 $to[i] = -1$ 显然出现断点，所以要在最近的能跳到 $i$ 位置的 $j$ 位置判断一下 $to[i + a[i]] == -1$ .因为有 $-1$ 的存在所以统计答案时少统计最后跳出的一次，所以最后要加一次。

* 代码

  ```c++
  const int N = 1e5 + 5;
  int L[N], R[N];
  int a[N], to[N], cs[N], pos[N];
  int n, m;
  void solve(int i)
  {
  	if (a[i] + i > n) // 当前数下一个就要跳出范围了
  	{
  		to[i] = -1;
  		cs[i] = 1;
  	}
  	else if (pos[i] != pos[i + a[i]] || to[i + a[i]] == -1) // 跳到下一个块中
   	{
  		to[i] = i + a[i]; 
  		cs[i] = 1;
  	}
  	else
  	{
  		to[i] = to[i + a[i]];
  		cs[i] = cs[i + a[i]] + 1;
  	}
  }
  int main ()
  {
  	//freopen("input.in", "r", stdin);
  	//freopen("test.out", "w", stdout);
  	cin >> n >> m;
  	int t = sqrt(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= t; i++)
  	{
  		L[i] = (i - 1) * sqrt(n) + 1;
  		R[i] = i * sqrt(n);
  	}
  	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
  	for (int i =  1; i <= t; i++)
  		for (int j = L[i]; j <= R[i]; j++)
  		{
  			pos[j] = i;
  		}
  	for (int i = t; i >= 1; i--)
  	{
  		for (int j = R[i]; j >= L[i]; j --){
  			solve(j);
  		}
  	}
  	while (m--)
  	{
  		int op;
  		read(op);
  		if (op == 0)
  		{
  			int x, y;
  			read(x);
  			read(y);
  			a[x] = y;
  			for (int i = x; pos[x] == pos[i]; i--) solve(i);
  		}
  		else
  		{
  			int x;
  			read(x);
  			int ans = 0;
  			for (; to[x] != -1; x = to[x])
  				ans += cs[x];
  			printf("%d %d\n", x,ans + 1);
  		}
  	}
  	return 0 ;
  }
  ```

  

* 题型

  分块