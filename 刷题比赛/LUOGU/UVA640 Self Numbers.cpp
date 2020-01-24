#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int vis[N];
int d(int x)
{
   int ans = x;
   while(x)
   {
     ans += x %10;
     x /= 10;  
   }
   return ans;
}
std::vector<int> v;
int main()
{ 
    for(int i =1;i<=1e6;i++)
    {
    	vis[d(i)] = 1;
    }
    for(int i= 1;i<=1e6;i++)
    	if(!vis[i]) cout<<i<<endl;
	return 0 ;
}