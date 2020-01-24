#### CodeForces 25C

* 题目

  [25C](https://codeforces.com/contest/25/problem/C)

* 分析

  考虑 $flyod$ 正常的 $flyod$ 复杂度是 $O(n^4)$ ，凉凉。。其实感觉可以枚举起点跑堆优化的 $dij$ 的，复杂度在 $O(n^3log(n))$ ，但是卡在了初始化上面。。。

  所以对 $flyod$ 优化，考虑 $flyod$ 更新问题，因为原图已经是最短路了，所以若是 $c$ 比 $d[a][b]$ 大的情况是一定不会更新答案的。先把这种情况判掉。而且在已经是最短路的情况下，想要距离变小只有经过 $a,b$ 两个点，所以以 $a,b$ 两个点为中间节点，松弛一下（不同于 $floyd$ 的状态递推）。

* 代码

  ```c++
  int d[305][305];
  int main ()
  {
  	//freopen("input.in", "r", stdin);
  	//freopen("test.out", "w", stdout);
  	int n;
  	cin>>n;
  	for(int i =1;i <= n;i++){
  		for(int j =1;j <= n;j++)
  		{
  			read(d[i][j]);
  		}
  	}
  	int m;
  	cin>>m;
  	while(m--)
  	{
  		int a,b,c;
  		read(a);
  		read(b);
  		read(c);
  		if(c <= d[a][b])
  		{
  			d[a][b] = c;
  			d[b][a] = c;
  			for(int i= 1;i <= n;i++){
  				for(int j = 1;j <= n;j++)
  					d[i][j] = min(d[i][j],d[i][a] + d[a][j]);
  			}
  			for(int i = 1;i <= n;i++)
  			{
  				for(int j =1;j <= n;j++)
  					d[i][j] = min(d[i][j],d[i][b] + d[b][j]);
  			}
  		}
  		ll ans = 0;
  		for(int i =1;i <= n;i++){
  			for(int j = i;j <= n;j++)
  				ans = ans + (ll)d[i][j];
  		}
  		printf("%lld\n", ans);
  	}
  	return 0 ;
  }
  ```

  

* 题型

  $flyod$