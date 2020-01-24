#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int p[N];
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}
int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    int _ = m;
    int tot = 0;
    ll ans = ksm(m, n);
    for (int i = 2; i <= sqrt(_); i++)
    {
        if (_ % i == 0)
        {
            p[++tot] = i;
            while (_ % i == 0)
                _ /= i;
        }
    }
    if (_ > 1)
        p[++tot] = _;
    int l = 1 << tot;
    for (int x = 1; x < l; x++)
    {
        ll prod = 1;
        int cnt = 0;
        for (int j = 1; j <= tot; j++)
        {
            if (x >> (j - 1) & 1)
            {
                prod *= p[j];
                cnt++;
            }
        }
        if (cnt & 1)
            ans -= ksm(m / prod, n);
        else
            ans += ksm(m / prod, n);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
//package demo;
import java.math.*;
import java.util.*;
public class Main {
    public static void main(String args[]) {
          Scanner cin = new Scanner(System.in);
          int n,m;
          n = cin.nextInt();
          m = cin.nextInt();
          int p[] = new int[100000];
          int x = m;
          int tot = 0;
          for(int i= 2;i <= x;i++)
          {
        	  if(x % i == 0)
        	  {
        		  p[++tot] = i;
        		  while(x % i == 0) x /= i;
        	  }
          }
          if(x > 1) p[++tot] = x;
          int l = 1 << tot;
          BigInteger ans = BigInteger.valueOf(m).pow(n);
          for(int i = 1;i < l;i++)
          {
        	  BigInteger prod = BigInteger.ONE;
        	  int cnt = 0;
        	  for(int j = 1;j <= tot;j++)
        	  {
        		  if(((i >> (j - 1)) & 1) == 1)
        		  {
        			  cnt ++;
        			  prod = prod.multiply(BigInteger.valueOf(p[j]));
        		  }
        	  }
        	  if((cnt & 1) == 1) 
        		  ans = ans.subtract((BigInteger.valueOf(m).divide(prod)).pow(n));
        	  else ans = ans.add((BigInteger.valueOf(m).divide(prod)).pow(n));
          }
          System.out.println(ans);
    }
}
*/