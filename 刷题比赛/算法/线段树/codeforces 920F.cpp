#include<bits/stdc++.h>
using namespace std;
const int N = 300010;
int f(int x)
{
  int ans = 0;
  for(int i = 1;i<=sqrt(x);i++)
  {
    if(x % i == 0) ans +=2;
  }
  return ans;
}
/*struct stree
{
  int l;
  int r;
  int
}
*/
int main ()
{
  cout<<f(6)<<endl;
  return 0;
}
