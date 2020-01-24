#### CodeForces 9E

* 题目
* [9E]()
* 分析
  题目要求只能有一个环，并且这个环是从 $1 \sim n$ 的。。。这条件对于解题目至关重要。。。从环开始分析：成环要求每个点的度数不小于 $2$ 。题目中要求的是一个环，那么开始每个点的度数不大于 $2$.否则如果度数不满足要求则连好边后会出现多个环的情况。。所以按照以下步骤解题：
  * 先连不在一个联通块的度数不大于 $2$ 的点，合并两个点到一个集合（成环要求所有点的度数等于 $2$，小于等于 $2$ 的点必须相连。
  * 再把同一个联通块的点首尾相连 $example:$ $1 \rightarrow 2 \rightarrow 3 \rightarrow  4$ ,$1，2，3，4$ 在一个联通块中，成环还要把 $4$ 和 $1$ 相连。。
  * 再判断一个点的情况，自己和自己相连。。
  * 最后判断所有点是否在一个联通块中，在就是 $YES$,不在就是 $NO$。
* 代码 

  ```c++
  const int N = 2505;
  int deg[N];
  struct node
  {
  	int x;
  	int y;
  };
  std::vector<node> v;
  int fa[N];
  bool cmp(node a, node b)
  {
  	if (a.x == b.x) return a.y < b.y;
  	return a.x < b.x;
  }
  int get(int x) {
  	if (x == fa[x]) return x;
  	return fa[x] = get(fa[x]);
  }
  
  void merge(int x, int y) {
  	fa[get(x)] = get(y);
  }
  
  int main ()
  {
  	//freopen("input.in", "r", stdin);
  	//freopen("test.out", "w", stdout);
  	int n, m;
  	read(n);
  	read(m);
  	for (int i = 1; i <= n; i++) fa[i] = i;
  	for (int i = 1; i <= m; i++)
  	{
  		int u, v;
  		read(u);
  		read(v);
  		deg[u]++;
  		deg[v]++;
  		merge(u, v);
  	}
  	for (int i = 1; i <= n; i++)
  	{
  		if (deg[i] >= 3)
  		{
  			puts("NO");
  			return 0;
  		}
  	}
  	// 不同联通块相连
  	for (int i = 2; i <= n; i++)
  	{
  		for (int j = 1; j < i; j++)
  		{
  			if (deg[i] != 2 && deg[j] != 2 && get(i) != get(j))
  			{
  				merge(i, j);
  				deg[i]++;
  				deg[j]++;
  				v.push_back(node{j, i});
  			}
  		}
  	}
  	//同一个联通块首尾相连
  	for (int i = 2; i <= n; i++)
  	{
  		if (deg[i] == 2) continue;
  		for (int j = 1; j < i; j++)
  		{
  			if (deg[j] <= 1)
  			{
  				merge(j, i);
  				deg[i] ++;
  				deg[j] ++;
  				v.push_back(node{j, i});
  			}
  		}
  	}
  	// 一个点成自环
  	for (int i = 1; i <= n; i++)
  		if (!deg[i]) v.push_back(node{i, i});
  	int r = get(1);
  	for (int i = 1; i <= n; i++)
  	{
  		if (get(i) != r) {
  			puts("NO");
  			return 0;
  		}
  	}
  	puts("YES");
  	cout << v.size() << endl;
  	sort(v.begin(), v.end(), cmp);
  	for (int i = 0; i < v.size(); i++)
  		cout << v[i].x << ' ' << v[i].y << endl;
  	return 0 ;
  }
  ```

  

* 题型

  并查集