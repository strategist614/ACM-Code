#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x1,x2,x3;
    int y1,y2,y3;
    cin>>x1>>x2>>x3>>y1>>y2>>y3;
    int ans1 = 0,ans2 = 0,ans3 = 0;
    ans1 = min(x1,y2);
    ans2 = min(x2,y3);
    ans3 = min(x3,y1);
    cout<<ans1+ans2+ans3<<endl;
    return 0 ;
}
