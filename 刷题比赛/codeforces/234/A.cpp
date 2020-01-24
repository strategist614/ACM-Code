	#include<bits/stdc++.h>
	using namespace std;
	int check(int x,char s[])
	{
		int flag = 0;
		for(int i = 1;i<= x;i++)
		{
		   int cnt =  0;
		   if(s[i] == 'X')
		   {
           for(int j = i;j<=12;j+=x)
                {
                    if(s[j] == 'X')  cnt++;              	
                }
            if(cnt > 12/x) {flag = 1,break;} 
		}
     	}
	if(flag) return 1;
	else return 0;
	}
	int main ()
	{
		int t;
		cin>>t;
		while(t--)
		{
			char s[13];
			scanf("%s",s+1);
		    std::vector<int> ans;
		    int cnt = 0;
		    for(int i = 1;i<=12;i++)
		    {
		    	if(s[i] == 'X') cnt++;
		    }
		    if(cnt == 0) {
		    	cout<<0<<endl;
		    }
		    else 
		    {
		       ans.push_back(12);
		       if(check(6,s)) ans.push_back(6);
		       if(check(4,s)) ans.push_back(4);
		       if(check(3,s)) ans.push_back(3);
		       if(check(2,s)) ans.push_back(2);
	           if(cnt == 12) ans.push_back(1);
	           cout<<ans.size()<<" ";
	           for(int i =0;i<ans.size();i++)
	           	 cout<<12/ans[i]<<"x"<<ans[i]<<" ";
	           cout<<endl;
		    } 
		}
		return 0 ;
	}