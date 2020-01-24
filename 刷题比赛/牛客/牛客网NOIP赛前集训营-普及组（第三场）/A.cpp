#include<bits/stdc++.h>
using namespace std;
const double PI = std::atan(1.0)*4;
int main ()
{
    int n;
    scanf("%d",&n);
    double ans = 0.0;
    ans = 17.0*(double)n*(double)n*(double)sin(PI*2/17)/2.0;
    printf("%.6f\n",ans);
    return 0 ;
}