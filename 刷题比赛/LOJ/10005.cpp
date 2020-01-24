#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
priority_queue<int> qmax;
priority_queue<int,vector<int>,greater<int> > qmin;
int main ()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
    {
    	int a;
    	scanf("%d",&a);
    	qmax.push(a);
    	qmin.push(a);
    }
    int mx = 0;
    int mn = 0;	
    while(qmax.size()>1)
    {
        int x = qmax.top();
        qmax.pop();
        int y = qmax.top();
        qmax.pop();
        qmax.push(x*y+1);
    }
    while(qmin.size()>1)
    {
        int x = qmin.top();
        qmin.pop();
        int y = qmin.top();
        qmin.pop();
        qmin.push(x*y+1);
    } 
    mx = qmax.top();
    mn = qmin.top();
    printf("%d\n",abs(mx-mn));
	return 0 ;
} 