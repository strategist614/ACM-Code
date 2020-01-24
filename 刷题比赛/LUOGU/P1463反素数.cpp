/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e9;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29};
void solve()
{
	int maxn = 0;
	for(int i = 2;i<=N;i++)
	{
        int tmp = i,ans = 1;
		for(int j = 1;j <= 10;j++)
		{
			int cnt = 0;
			while(tmp % prime[j] == 0)
			{
               tmp /= prime[j];
               cnt++;
			}
			ans *= (cnt+1);
			if(tmp == 1) break;
		}
		if(ans > maxn)
		{
			cout<<i<<endl;
			maxn = ans ;
		}
	}
}
int main ()
{
    solve();
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int a[] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,
332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,
4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600,32432400,
36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600,245044800,294053760,367567200,551350800,735134400,1102701600
,1396755360};
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=67;i++)
    {
       if(n < a[i]) 
       {
       	  cout<<a[i-1]<<endl;
       	  //cout<<1;
       	  return 0;
       }
    }
    cout<<a[66]<<endl;
	return 0 ;
}
*/
/*
void dfs(ll num,int k,int sum,int limit)
{//num: 当前枚举到的数 k:枚举到的第k大的质因子 sum:该数的约数个数 limit：质因子个数上限(重要剪枝)
    if(sum>maxsum)       //约数个数更多
    {
        maxsum=sum;
        ans=num;
    }
    if(sum==maxsum&&ans>num)  //约数个数相同，把最优解更新为较小值
    {
        ans=num;
    }
    if(k>16)                     //这里k>x; x至少满足prime[1]*prime[2]*prime[3]*...*prime[x]>x ,当x=16时，数据已超过10^18
        return;                  //当x=10时，数据已超过10^9
    ll temp=num;
    for(int i=1;i<=limit;i++)  //枚举每个质因子的个数
    {
        if(n/prime[k]<temp)    //n为上限,用除法防止溢出
            return;
        temp*=prime[k];
        dfs(temp,k+1,sum*(i+1),i);  //把limit置为i的原因见性质第二条
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31};
int maxsum = 0;
int ans = 0;
int n;
void dfs(int now,int sum,int k)
{
	if(sum > maxsum)//当前因子个数大于最大值时，更新最大值见性质1
	{
		maxsum = sum;
		ans = now;
	}
	if(sum == maxsum && ans > now) ans = now;//因子个数相等时，使此时的数尽量小见性质2 
	if(k > 11) return ;//深度大于11时 return
    for(int i =1;i<=31;i++)//2^31大于2e9
    {
    	if(n / prime[k] < now) return ;//当前值乘上因子的值比n大 return
    	dfs(now*=prime[k],sum*(i+1),k+1);//搜索下一个状态
    }
}
int main ()
{
    cin>>n;
    dfs(1,1,1);
    cout<<ans<<endl;
	return 0 ;
}