#include<bits/stdc++.h>
using namespace std;
map<char,double>mass;
double solve(string s)
{
	double ans = 0.0;
    for(int i= 0;i<s.size();i++)
	{
       if(mass[s[i]])
       {
       	  if(s[i+1] > '9' || s[i+1] < '0')
       	  {
       	  	ans += mass[s[i]];
       	  }
       	  else 
       	  {
       	  	 int size = 0,pos = i+1;
       	  	 while(s[pos] <= '9' && s[pos] >= '0')
       	  	 {
       	  	 	size = size * 10 + s[pos]-'0';
       	  	 	pos++;
       	  	 }
       	  	 ans += mass[s[i]] * size;
       	  }
       }    
	}	
	return ans ;
}
int main ()
{
	int n;
	cin>>n;
	getchar();
	mass['O'] = 16.00;
	mass['H'] = 1.008;
	mass['C'] = 12.01;
	mass['N'] = 14.01;
	for(int i =1;i<=n;i++)
	{
		string s;
		getline(cin,s);
        printf("%.3lf\n",solve(s));
	}
	return 0 ;
}