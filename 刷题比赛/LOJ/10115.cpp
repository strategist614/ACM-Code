#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
int n,m;
int L[N];
int R[N];
void add(int t[],int x,int y)
{
    for(;x <= N;x += x&-x) t[x] += y;
}
int ask(int t[],int x)
{
    int ans = 0;
    for(;x;x -= x&-x) ans += t[x];
    return ans; 
}
int main ()
{
    scanf("%d %d",&n,&m);
    for(int i= 1;i<=m;i++)
    {
        int k,x,y;
        scanf("%d %d %d",&k,&x,&y);
        if(k == 1)
        {
           add(L,x,1);
           add(R,y,1);           
        }
        else 
        {
           cout<<ask(L,y) - ask(R,x-1)<<endl;
        }
    } 
    return 0 ;
}
/*
这题看起来和树状数组没什么关系，不过我们通过一定的转化，可以利用树状数组很好地解决这个问题。

我们不妨把所有线段的端点看成括号序列，即把询问的区间[lq,rq]看成在横坐标lq处的一个‘[’和rq处的‘]’,把插入的线段[li,ri]看成在横坐标li处的一个‘(’和ri处的‘)’。

稍作分析(分析不出来)，我们不难发现，最后的答案等于‘]’左边‘(’的个数减去‘[’左边‘)’的个数。

那么我们现在做的就是对某个点做修改，对某个前缀求和。我们就可以很容易想到树状数组的做法：

1.建立两个树状数T1和T2，分别维护‘(’和‘)’。

2.若K=1，读入li,ri，plusT1(li,1)，plusT2(ri,1)。

3.若K=2，读入lq,rq，sumT1(rq)-sumT2(lq-1)
*/