#include<bits/stdc++.h>
using namespace std;
int fa[2010],a[2010],ans;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int find(int x)
{ return x==fa[x]? x:fa[x]=find(fa[x]);}
int main()
{
   int m,n;
   n=read(); m=read();
   for(int i=1;i<=n*2;i++) fa[i]=i;
   while(m--)
   {
       char c[11]; int x,y;
       scanf("%s",c); x=read(),y=read();
       if(c[0]=='F') fa[find(x)]=find(y);
       else {fa[find(x)]=find(y+n); fa[find(y)]=find(x+n);}
   }
   for(int i=1;i<=n;i++) a[i]=find(i);
   sort(a+1,a+1+n);
   for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) ans++;
   printf("%d",ans);
   return 0;
}
﻿