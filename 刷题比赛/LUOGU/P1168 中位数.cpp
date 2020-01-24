/*
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int a[N],mid = 0;
priority_queue<int> qmax;
priority_queue<int,vector<int>,greater<int> > qmin;
void update()
{
	int szx = qmax.size();
	int szn = qmin.size();
    if(szx - szn > 1)
    {
    	while(szx != szn)
    	{
    		int tmp = qmax.top();
    		qmax.pop();
    		qmin.push(tmp);
    		szx = qmax.size();
    		szn = qmin.size();
    	}
    }
    if(szn - szx > 1)
    {
    	while(szx != szn)
    	{
    		int tmp = qmin.top();
    		qmin.pop();
    		qmax.push(tmp);
    	    szx = qmax.size();
    	    szn = qmin.size();
    	}
    }
   if(szn - szx == 1) mid = qmin.top();
   if(szx - szn == 1) mid = qmax.top();
}	
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i];
	int len = (n+1)/2;
    len *= 2;
    len -= 1;
	for(int i= 1;i<=len;i++)
	{
        if(a[i] <= mid) qmax.push(a[i]);
        else qmin.push(a[i]);
        update();
        cout<<mid<<endl;
        if(i % 2)
        {
           //cout<<mid<<endl;
        }
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
priority_queue<int> qmax;
priority_queue<int,vector<int>,greater<int> > qmin;
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i];
	int len = (n+1)/2;
    len *= 2;
    len -= 1;
    qmin.push(a[1]);
    cout<<a[1]<<endl;
    for(int i= 2;i<=len;i++)
    {
       if(a[i] < qmin.top()) qmax.push(a[i]);
       else qmin.push(a[i]);
       if((int)qmax.size() > i/2) 
       {
       	  qmin.push(qmax.top());
       	  qmax.pop();
       }
       if((int)qmax.size() < i/2)
       {
       	 qmax.push(qmin.top());
       	 qmin.pop();
       }
       if(i % 2)
       	cout<<qmin.top()<<endl;
    }
	return 0 ;
}