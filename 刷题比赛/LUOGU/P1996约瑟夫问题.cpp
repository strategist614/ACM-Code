#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i= 1;i<=n;i++) q.push(i);
	int cnt = 1;
	while(!q.empty())
	{
        if(cnt == m)
        {
        	cout<<q.front()<<" ";
        	q.pop();
        	cnt = 1;
        }
        else 
        {
        	q.push(q.front());
        	q.pop();
        	cnt++;
        }
	}
	cout<<endl;
	return 0 ;
}