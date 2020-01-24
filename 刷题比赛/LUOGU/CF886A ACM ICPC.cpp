#include<bits/stdc++.h>
using namespace std;
int a[7];
int ans = 0;
int vis[7];
int main ()
{
    for(int i =1;i<=6;i++){cin>>a[i];ans+=a[i];}
    if(ans % 2)cout<<"NO"<<endl;
    else 
    {
        ans /= 2;
        for(int i =1;i<=4;i++)
            for(int j= i+1;j<=5;j++)
                for(int k=j+1;k<=6;k++)
                {
                    if(a[i]+a[j]+a[k] == ans)
                    {
                        cout<<"YES"<<endl;
                        return 0;
                    }
                }
        cout<<"NO"<<endl;
    }
    return 0 ;
}