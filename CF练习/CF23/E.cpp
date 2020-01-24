//package demo;
import java.math.*;
import java.util.*;
public class Main {
	static int [] head = new int[705];
	static int [] Next = new int[10000];
	static int [] ver = new int[10000];
	static int [] size = new int[705];
	static int n;
	static int tot = 0;
	static BigInteger [][] dp = new BigInteger[705][705];
	static void add(int x,int y)
	{ 
		    ver[++tot]=y;
	        Next[tot]=head[x];
	        head[x]=tot;	 
	}
	static void init()
	{
		for(int i = 0;i <= 704;i++) head[i] = 0;
		tot = 0;
	}
	static void dfs(int x,int fa)
	{
		size[x] = 1;
		for(int i = 0;i <= n;i++) dp[x][i] = BigInteger.valueOf(1); 
		for(int i = head[x];i != 0;i = Next[i])
		{
			int y = ver[i];
			if(y == fa) continue;
			dfs(y,x);
			for(int j = size[x];j >= 0;j--)
			{
				for(int k = size[y];k >= 0;k--)
					dp[x][j + k] = dp[x][j + k].max(dp[y][k].multiply(dp[x][j]));
			}
			size[x] += size[y];
		}
		for(int i = 1;i <= size[x];i++)
			dp[x][0] = dp[x][0].max(dp[x][i].multiply(BigInteger.valueOf(i)));
	}
    public static void main(String args[]) {
          Scanner cin = new Scanner(System.in);
          n = cin.nextInt();
          init();
          for(int i = 1;i <= n - 1;i++)
          {
        	  int u = cin.nextInt();
        	  int v = cin.nextInt();
        	  add(u,v);
        	  add(v,u);
          }
          dfs(1,-1);
          System.out.println(dp[1][0]);
    }
}
 
