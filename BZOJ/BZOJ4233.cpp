#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define RG register
#define MAX 1000100
inline int read()
{
    RG int x=0,t=1;RG char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
char ch[MAX];
ll ans;
int tot=1,last=1;
struct Node
{
    int son[26];
    int ff,len;
}t[MAX<<1];
void extend(int c)
{
    int p=last,np=++tot;last=np;
    t[np].len=t[p].len+1;
    while(p&&!t[p].son[c])t[p].son[c]=np,p=t[p].ff;
    if(!p)t[np].ff=1;
    else
    {
        int q=t[p].son[c];
        if(t[p].len+1==t[q].len)t[np].ff=q;
        else
        {
            int nq=++tot;
            t[nq]=t[q];t[nq].len=t[p].len+1;
            t[q].ff=t[np].ff=nq;
            while(p&&t[p].son[c]==q)t[p].son[c]=nq,p=t[p].ff;
        }
    }
}
int main()
{
    int T=read();
    while(T--)
    {
        scanf("%s",ch+1);
        ans=0;last=tot=1;memset(t,0,sizeof(t));
        for(int i=1,l=strlen(ch+1);i<=l;++i)extend(ch[i]-65);
        for(int i=1;i<=tot;++i)ans+=t[i].len-t[t[i].ff].len;
        printf("%lld\n",ans);
    }
    return 0;
}