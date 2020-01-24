#include<bits/stdc++.h>
using namespace std;
char a;
string s;
//int j;
int main ()
{
	long long w = 0,l = 0,i = 0;
    while(cin>>a && a != 'E')
    {   
        if(a == 'W') {w++,s+=a;}
        if(a == 'L') {l++,s+=a;}
        if((w >= 11 || l >= 11) && (w-l>=2 || l - w >= 2))
        {
        	cout<<w<<":"<<l<<endl;
        	w = 0;
        	l = 0;
        }
        i++;
    }
    cout<<w<<":"<<l<<endl<<endl;
    w = 0,l = 0;
    for(int j= 0;j<=i;j++)
    {
    	if(s[j] == 'W') w++;
        if(s[j] == 'L') l++;
         if((w >= 21 || l >= 21) && (w-l>=2 || l - w >= 2))
        {
        	cout<<w<<":"<<l<<endl;
        	w = 0;
        	l = 0;
        }
    }
    cout<<w<<":"<<l<<endl;
	return 0 ;
}