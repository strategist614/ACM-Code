#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node
{
   int num;
   int price;	
}a[N];
int main ()
{
	int pre = 0;
	cin>>pre;
	double minn = -1e9,maxn = 1e9;
	int t = 1;
    int x,y;
    cin>>x>>y;
    a[t].price = x;
    a[t].num = y;
    for(;;)
    {
    	if(x == -1 && y == -1) break;
    	cin>>x>>y;
        if(x - a[t].price == 1)
        {
        	t++;
            a[t].price = x;
            a[t].num = y;
        }    
        else 
        {
        	int tmp = (a[t].num - y) / (x-a[t].price);
        	while(a[t].price < x)
        	{
        		t++;
        		a[t].price = a[t-1].price+1;
        		a[t].num = a[t-1].num-tmp;
        	}
        }
    }
    int tmp_p = a[t].price,tmp_n = a[t].num;
    int kxy;
    cin>>kxy;
    while(tmp_n-kxy > 0)
    {
      t++;
      a[t].price = a[t-1].price+1;
      a[t].num = a[t-1].num - kxy;
      tmp_n -= kxy;
    }
    int flag = 0;
    for(int i= 1;i<=t;i++)
    {
    	if(a[i].price == pre) 
    	{
    		flag = i;
    		break;
    	}
    }
    if(!flag)
    {
    	cout<<"NO SOLUTION"<<endl;
    	return 0; 
    }
    for(int i= 1;i<flag;i++)
    {
    	if(((double)(a[flag].num * (a[flag].price-a[1].price)-a[i].num*(a[i].price-a[1].price)) / (double)(a[i].num-a[flag].num)) <= maxn)
        maxn = (double)(a[flag].num * (a[flag].price-a[1].price)-a[i].num*(a[i].price-a[1].price)) / (double)(a[i].num-a[flag].num);
    }
    for(int i = flag+1;i <= t;i++)
    {
    	if(((double)(a[i].num*(a[i].price-a[1].price)-a[flag].num*(a[flag].price-a[1].price)) / (double)(a[flag].num-a[i].num)) >= minn)
        minn = (double)(a[i].num * (a[i].price-a[1].price)-a[flag].num*(a[flag].price-a[1].price)) / (double)(a[flag].num-a[i].num);
    }
    if(minn > maxn)
    {
    	cout<<"NO SOLUTION"<<endl;
    }
    else if(minn > 0)
    {
    	if(fabs(minn-(int)minn) > 1e-6) minn = (int)minn+1;
    	else minn = (int)minn;
    	cout<<minn<<endl;
    }
    else if(maxn < 0)
    {
    	if(fabs((int)maxn-maxn) > 1e-6) maxn = (int)maxn - 1;
    	else maxn = (int)maxn;
    	cout<<maxn<<endl;
    }
    else cout<<0<<endl;
	return 0 ;
}