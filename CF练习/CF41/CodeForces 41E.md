#### CodeForces 41E

* 题目

  [41E](https://codeforces.com/contest/41/problem/E)

* 分析

  看一下维基的结论：By [Turán's theorem](https://en.wikipedia.org/wiki/Turán's_theorem), the *n*-vertex triangle-free graph with the maximum number of edges is a [complete bipartite graph](https://en.wikipedia.org/wiki/Complete_bipartite_graph) in which the numbers of vertices on each side of the bipartition are as equal as possible。

  $as \,equal\, as \,possible$ 提示 答案就是 $\lfloor\frac{n}{2}\rfloor \times \lceil\frac{n}{2}\rceil$ 

  方案就是： 左部点： $1\sim \lfloor\frac{n}{2}\rfloor$ 

  ​                    右部点： $\lfloor\frac{n}{2}\rfloor + 1 \sim n$ 

* 代码

  ```c++
  int a[2000];
  int ans[2000];
  int main ()
  {
  	//freopen("input.in", "r", stdin);
  	//freopen("test.out", "w", stdout);
  	int n;
  	cin >> n;
  	ans[4] = 4;
  	for(int i = 5;i <= 100;i++)
  	{
          int tmp = i * (i - 1) / 2;
          ans[i] = tmp - ans[i - 1];
  	}
  	if (n == 1)
  	{
  		cout << 0 << endl;
  	}
  	else if (n == 2)
  	{
  		cout << 1 << endl;
  		cout << 1 << ' ' << 2 << endl;
  	}
  	else if (n == 3)
  	{
  		cout << 2 << endl;
  		cout << 1 << ' ' << 2 << endl;
  		cout << 1 << ' ' << 3 << endl;
  	}
  	else
  	{
  		cout << ans[n] << endl;
  		for(int i = 1;i <= n / 2;i ++)
  		{
  			for(int j = n / 2 + 1;j <= n;j++)
  				cout << i <<" " << j << endl;
  		}
  	}
  	return 0 ;
  }
  ```

  

* 题型

  结论