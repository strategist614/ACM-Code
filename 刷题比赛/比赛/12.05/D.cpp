#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int solve(string s)
{
	int ans = 0;
	for(int i= 0;i<s.size();)
	{ 
		if(s[i] == 'O')
		{
			int tmp = 0;
			for(int j = i;j<=s.size();j++)
              {
              	  if(s[j] == 'O') {tmp++;continue;}
              	  else break;
              }
            ans += (1+tmp)*tmp/2;
            i += tmp;
		}
		else i++;
	}
	return ans ;
}
int main ()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		string s;
		getline(cin,s);
        cout<<solve(s)<<endl;
	}
	return 0 ;
}
