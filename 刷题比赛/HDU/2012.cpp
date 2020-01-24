#include<bits/stdc++.h>
using namespace std;
int solve(int x)
{
	if(x == 1) return 0;
	else if(x == 2)return 1;
	for(int i = 2;i<=sqrt(x);i++)
	{
		if(x % i == 0) return 0;
	}
	return 1;
}
int main ()
{
	int x,y;
	while(scanf("%d %d",&x,&y) != EOF)
	{
      if(x == 0 && y == 0) break;
      int flag = 0;
      for(int i = x;i<=y;i++)
      {
      	int ans = i * i+i+41;
        if(!solve(ans)) flag = 1;
      } 
      if(flag) cout<<"Sorry"<<endl;
      else cout<<"OK"<<endl;
	}
	return 0 ;
}