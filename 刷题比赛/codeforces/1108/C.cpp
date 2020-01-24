#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
map<int,string> mp;
int a[8];
int main ()
{
	int n;
	cin>>n;
    scanf("%s",s+1);
	if(n == 1)
	{
	   cout<<0<<endl;
       cout<<s[1]<<endl;
	}
	else if(n == 2)
	{
       if(s[1] == s[2])
       {
       	   cout<<1<<endl;
           if(s[1] == 'G') cout<<s[1]<<'R'<<endl;
           else if(s[1] == 'R') cout<<s[1]<<'B'<<endl;
           else cout<<s[1]<<'G'<<endl;
       } 
       else 
       {
       	  cout<<0<<endl;
       	  cout<<s[1]<<s[2]<<endl;
       }
	}
	else 
	{
		mp[1] = "RGB";
		mp[2] = "RBG";
		mp[3] = "BGR";
		mp[4] = "BRG";
		mp[5] = "GBR";
		mp[6] = "GRB";
        for(int i =1;i<=n;i++)
        {
           if(i % 3 == 1)
           {
              if(s[i] == 'G') {a[1]++;a[2]++;a[3]++;a[4]++;}
              else if(s[i] == 'B'){a[1]++;a[2]++;a[5]++;a[6]++;}
              else {a[3]++;a[4]++;a[5]++;a[6]++;} 
           }
           else if(i % 3 == 2)
           {
              if(s[i] == 'G'){a[2]++;a[4]++;a[5]++;a[6]++;}
              else if(s[i] == 'R'){a[1]++;a[2]++;a[3]++;a[5]++;}
              else {a[1]++;a[3]++;a[4]++;a[6]++;}
           }
           else 
           { 
              if(s[i] == 'G'){a[1]++;a[3]++;a[5]++;a[6]++;}
              else if(s[i] == 'B') {a[2]++;a[3]++;a[4]++;a[5]++;}
              else {a[1]++;a[2]++;a[4]++;a[6]++;}
           }
        }
        int flag = 0;
        int minn = 1e9;
        for(int i= 1;i<=6;i++)
        {
        	if(a[i] < minn)
        	{
        		minn = a[i];
        		flag = i;
        	}
        }
        string s  = mp[flag];
        cout<<minn<<endl;
        for(int i =1;i<=n;i++)
        {
        	if(i % 3 == 1) cout<<s[0];
        	else if(i %3 == 2) cout<<s[1];
        	else cout<<s[2];
        }
	}
	return 0 ;
}