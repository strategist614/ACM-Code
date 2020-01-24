#include<bits/stdc++.h>
using namespace std;
map<char,char> mp;
char a[1005];
int main ()
{ 
    mp['A'] = 'A';
    mp['b'] = 'd';
    mp['d'] = 'b';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['o'] = 'o';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['v'] = 'v';
    mp['W'] = 'W';
    mp['w'] = 'w';
    mp['X'] = 'X';
    mp['x'] = 'x';
    mp['Y'] = 'Y';
    mp['q'] = 'p';
    mp['p'] = 'q';
    scanf("%s",a+1);
    int len = strlen(a+1);
    if(len % 2)
    {
      //cout<<1;	
      char ch = a[len/2+1];
      if(ch != mp[ch]) 
      {
      	cout<<"NIE"<<endl;
      	return 0;
      } 
      for(int i =1;i<=len/2;i++)
      {
         if(mp[a[i]] != a[len-i+1])
         {
         	cout<<"NIE"<<endl;
         	return 0;
         }  
      }
      cout<<"TAK"<<endl;
    }
    else 
    {
    	for(int i =1;i<=len;i++)
    	{
           if(mp[a[i]] != a[len-i+1]) 
           {
           	  cout<<"NIE"<<endl;
           	  return 0;
           } 
    	}
    	cout<<"TAK"<<endl;
    }	
    return 0 ;
}