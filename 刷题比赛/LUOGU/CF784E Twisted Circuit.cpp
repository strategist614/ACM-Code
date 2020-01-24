#include <bits/stdc++.h>
using namespace std;
int main(){
    bool a,b,c,d;
    cin>>a>>b>>c>>d;
    bool ans=((a^b)&(c|d)^(b&c)|(a^d));
    cout<<(int)ans;
}