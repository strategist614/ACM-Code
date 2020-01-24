#include<iostream>
#include<queue>
using namespace std;
const int N = 1e5;
struct node
{
	int x;
	int s;
};
int vis[N];
int n,k;
int ans = 1e9;
void bfs()
{ 
   queue<node> q;
   node tmp;
   tmp.x = n;
   tmp.s = 0;
   vis[tmp.x] = 1;
   q.push(tmp);
   while(q.size())
   {
   	  tmp = q.front();
   	  q.pop();
   	  for(int i =1;i<=3;i++)
   	  {
   	  	node _;
   	  	if(i == 1)_.x = tmp.x+1;
   	  	else if(i == 2) _.x = tmp.x-1;
   	  	else _.x = tmp.x*2;
   	  	if(_.x > N || _.x < 0) continue;
   	  	if(!vis[_.x])
   	  	{
   	  		vis[_.x] = 1;
   	  		_.s = tmp.s+1;
   	  		q.push(_);
   	  	}
   	  	if(_.x == k) 
   	  	{
   	  		cout<<_.s<<endl;
   	  		return ;
   	  	}  
   	  }
   }
}
int main ()
{
	cin>>n>>k;
   if(n >= k) cout<<n-k<<endl;
	else 
	bfs();
	return 0 ;
}
