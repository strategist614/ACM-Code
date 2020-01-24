#include<bits/stdc++.h>
using namespace std;
char a[1005];
stack<int> s;
int vis[1005];
int main ()
{
	scanf("%s",a+1);
	int size = strlen(a+1);
	for(int i= 1;i<=size-1;i++)
	{
		if(a[i] <= '9' && a[i] >= '0'&&!vis[i])
		{
			int x = 0;
			while(a[i] != '.')
			{
               x = x*10 + a[i]-'0';
               vis[i]++;
               i++;
			}
			s.push(x);
		}
		else 
		{
			if(a[i] == '+')
			{
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(x+y);
			}
			else if(a[i] == '-')
			{
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y-x);
			}
			else if(a[i] == '*')
			{
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(x*y);
			}
			else if(a[i] == '/')
			{
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y/x);
			}
		}
	}
    cout<<s.top()<<endl;
	return 0 ;
}