#include<bits/stdc++.h>
using namespace std;
struct s
{
    char name[30];
    int qmcj;
    int bjcj;
    char gb;
    char xb;
    int lw;
    int m;
    int id;
}a[105];
int solve(s a)
{
    int ans = 0 ;
    if(a.qmcj > 80 && a.lw >= 1) ans += 8000;
    if(a.qmcj > 85 && a.bjcj > 80) ans += 4000;
    if(a.qmcj > 90) ans += 2000;
    if(a.qmcj > 85 && a.xb == 'Y') ans += 1000;
    if(a.bjcj> 80 && a.gb == 'Y') ans += 850;
    return ans ; 
}
bool cmp(s a,s b)
{
   if(a.m == b.m) return a.id < b.id;
   return a.m > b.m;
}
int main ()
{
	int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
    {
       cin>>a[i].name>>a[i].qmcj>>a[i].bjcj>>a[i].gb>>a[i].xb>>a[i].lw;
       a[i].id = i;
    }
    int money = 0;
    for(int i= 1;i<=n;i++)
    {
        a[i].m = solve(a[i]);
        money += a[i].m;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1].name<<endl;
    cout<<a[1].m<<endl;
    cout<<money<<endl;
	return 0 ;
}