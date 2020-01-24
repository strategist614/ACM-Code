#### 一维 $RMQ$

* 前置：区间 $DP$ ,倍增

*  问题：给定长 $N$ 的数组 $A$ ,在 $O(nlog(n))$ 时间预处理，以 $O(1)$ 时间回答数列 $A$ 中下标在 $l\sim r$ 之间的数的最大值是多少。

*  设 $F[i,j]$ 表示数列 $A$ 中下标在子区间 $[i,i + 2^j-1]$ 里的数的最大值，则转移方程为 $F[i,j] = max(f[i,j -1],f[i + 2^{j-1},j-1])$ 即把区间分为左右长度各为 $2^{j-1}$ 的子区间的最大值中的最大的。

* 代码：预处理

  ```c++
  void ST_prework() {
  	for (int i = 1; i <= n; i++) f[i][0] = a[i];
  	int t = log(n) / log(2) + 1;
  	for (int j = 1; j < t; j++)
  		for (int i = 1; i <= n - (1<<j) + 1; i++)
  			f[i][j] = max(f[i][j-1], f[i + (1<<(j-1))][j-1]);
  }
  ```

  查询：

  ```c++
  int ST_query(int l, int r) {
  	int k = log(r - l + 1) / log(2);
  	return max(f[l][k], f[r - (1<<k) + 1][k]);
  }
  ```

  

#### 二维 $RMQ$

* 问题：问题拓展到二维，问一个矩阵中的最大值的查询。

* 算法：设 $F[i][j][k][l]$ 表示以 $i,j$ 为左上角，右下角为 $[i+2^k-1,j + 2^l - 1]$ ,预处理复杂度是 $O(nmlog(n)log(m))$ 。考虑转移方程，矩阵的情况和一维类似，现在由两个小矩阵的最大值转移。

  $f[i][j][k][l] = max\{f[i][j][k][l-1],f[i][j + 2^{l-1}][k][l-1]\}$ 

  $f[i][j][k][l] = max\{f[i][j][k-1][l],f[i + 2^{k-1}][j][k - 1][l]\}$  

  查询：

  查询要查四个矩阵：令 $p = log_2(x2 - x1 + 1),q = log_2(y2 - y1 + 1)$
  $$
  max\left\{
  \begin{aligned}
  f[x_1][y_1][p][q]\\
  f[x_2 - 2^p + 1][y_1][p][q] \\
  f[x_1][y_2 - 2 ^ q + 1] [p][q] \\
  f[x_2 - 2 ^ p + 1][y2 - 2 ^ p + 1][p][q]
  \end{aligned}
  \right.
  $$
  大佬的代码：

  ```C++
  const int Log=12;
  const int N=610;
  const int inf=1e9;
  int n,m,Q;
  int maxv[Log][Log][N][N];
  int pre[N],val[N][N]; 
  void init(){
  	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)maxv[0][0][i][j]=val[i][j];
  	pre[2]=pre[3]=1;
  	for(int i=4,up=max(n,m);i<=up;i++)pre[i]=pre[i>>1]+1;
  	int up1=pre[n]+1,up2=pre[m]+1;
  	for(int l1=0;l1<=up1;l1++){
  		for(int l2=0;l2<=up2;l2++){
  			if(!l1&&!l2) continue;
  			for(int i=1;(i+(1<<l1)-1)<=n;i++){
  				for(int j=1;(j+(1<<l2)-1)<=m;j++){
  					if(l2)maxv[l1][l2][i][j]=max(maxv[l1][l2-1][i][j],maxv[l1][l2-1][i][j+(1<<(l2-1))]);
  					else maxv[l1][l2][i][j]=max(maxv[l1-1][l2][i][j],maxv[l1-1][l2][i+(1<<(l1-1))][j]);
  				}
  			}
  		}
  	}
  }
  int query(int x1,int y1,int x2,int y2){
  	int p=pre[x2-x1+1],q=pre[y2-y1+1];
  	int ans=-inf;
  	ans=max(maxv[p][q][x1][y1],maxv[p][q][x1][y2-(1<<q)+1]);
  	ans=max(ans,max(maxv[p][q][x2-(1<<p)+1][y1],maxv[p][q][x2-(1<<p)+1][y2-(1<<q)+1]));
  	return ans;
  }
  int x1,x2,y1,y2;
  int main(){
  	scanf("%d%d%d",&n,&m,&Q);
  	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&val[i][j]);
  	init();
  	for(int i=1;i<=Q;i++){
  		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  		printf("%d\n",query(x1,y1,x2,y2));
  	}
  	return 0;
  }
  
  ```

  特殊写法：当查询的是一个正方形区间时，可以优化数组一维。。这样就那么容易 $MLE$ 了。

  $f[i][j][k]$ 表示以 $i,j$ 为左上角坐标，$k$ 为正方形边长的最大值。那就把矩形划分为四块。
  
  预处理：
  
  ```c++
  for (int k = 1; k <= 11; ++k)
  		for (int i = 1; i + (1 << k) - 1 <= a; ++i)
  			for (int j = 1; j + (1 << k) - 1 <= b; ++j)
  			{
  				maxv[i][j][k] = Max(maxv[i][j][k - 1], maxv[i + (1 << k - 1)][j][k - 1], maxv[i][j + (1 << k - 1)][k - 1], maxv[i + (1 << k - 1)][j + (1 << k - 1)][k - 1]);
  				minv[i][j][k] = Min(minv[i][j][k - 1], minv[i + (1 << k - 1)][j][k - 1], minv[i][j + (1 << k - 1)][k - 1], minv[i + (1 << k - 1)][j + (1 << k - 1)][k - 1]);
  			}
  ```
  
  查询：
  
  ```c++
  kk = (int)(log(n) / log(2));
  inline int query_max(int x, int y, int xx, int yy)
  {
  	int t1 = maxv[x][y][kk], t2 = maxv[xx - (1 << kk) + 1][y][kk], t3 = maxv[x][yy - (1 << kk) + 1][kk], t4 = maxv[xx - (1 << kk) + 1][yy - (1 << kk) + 1][kk];
  	return max(max(max(t1, t2), t3), t4);
  }
  inline int query_min(int x, int y, int xx, int yy)
  {
  	int t1 = minv[x][y][kk], t2 = minv[xx - (1 << kk) + 1][y][kk], t3 = minv[x][yy - (1 << kk) + 1][kk], t4 = minv[xx - (1 << kk) + 1][yy - (1 << kk) + 1][kk];
  	return min(min(min(t1, t2), t3), t4);
  }
  ```
  
  

#### 参考博客

[dalao1](https://blog.csdn.net/VictoryCzt/article/details/83684082)

[dalao2](https://www.luogu.org/blog/zhouziheng666/qian-tan-st-biao)

[dalao3](https://www.cnblogs.com/bullshit/p/9583359.html)

