#include<bits/stdc++.h>
using namespace std;
int main ()
{
	string s;
	cin>>s;
	int ans = 0;
	int cntn = 0;
	int cnte = 0;
	int cnti = 0;
	int cntt = 0;
    for(int i= 0;i<s.size();i++)
    {
       if(s[i] == 'n') cntn++;
       if(s[i] == 'e') cnte++;
       if(s[i] == 'i') cnti++;
       if(s[i] == 't') cntt++;
       }
      if(cntn < 3 || cntt < 1 || cnti < 1 || cnte< 3) 
      {
      	cout<<0<<endl;
      	return 0 ;
      }
    int minn = 2e9;
    int tmp1 = cnte/3;
    int tmp2 = ceil((double)cntn/3);
    minn = min(tmp2,min(tmp1,min(cntt,cnti)));
    cout<<minn<<endl;
	return 0 ;
}