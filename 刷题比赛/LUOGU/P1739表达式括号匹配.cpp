#include<bits/stdc++.h>
using namespace std;
char a[400];
stack<char> s;
int main ()
{
    scanf("%s",a+1);
    int size = strlen(a+1);
    for(int i= 1;i<=size;i++)
    {
    	if(a[i] == '(') s.push('(');
    	else if(a[i] == ')') 
    	{
    		if(s.size() == 0) 
    		{
    			cout<<"NO"<<endl;
    		    return 0;
    		 }
            s.pop();
    	}
    }
    if(s.size() != 0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
	return 0 ;
}