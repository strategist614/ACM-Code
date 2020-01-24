#include<bits/stdc++.h>
using namespace std;
const int N = 53;
string word[N],card[N];
int order[N];
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
    	for(int i= 0;i<n;i++)
    	{
    		cin>>card[i]>>word[i];
    	    order[i] = -1;
    	}
    	for(int i= 0,j= 0;i<n;i++)
    	{
    		for(int k = word[i].size();;j = (j+1)%n)
    		{
    			if(order[j] == -1 && --k == 0)
    			{
    				break;
    			}

    		}
    		order[j] = i;//在j的位置输出i位置的值
    	}
    	for(int i= 0;i<n;i++)
    	{
    		if(i != n-1) cout<<card[order[i]]<<" ";
    		else cout<<card[order[i]]<<endl;
    	}
    }
	return 0 ;
}