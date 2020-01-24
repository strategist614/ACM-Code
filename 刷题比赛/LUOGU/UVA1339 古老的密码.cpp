#include<bits/stdc++.h>
using namespace std;
int a[27],b[27];
int main ()
{
	char s1[105],s2[105];
	while(scanf("%s %s",s1,s2)!=EOF)
	{
	  memset(a,0,sizeof(a));
	  memset(b,0,sizeof(b));
	  int len = strlen(s1);
	  for(int i = 0;i<len;i++)
	  {
        a[s1[i]-'A']++;
	    b[s2[i]-'A']++;
	  }
	  sort(a,a+26);
	  sort(b,b+26);
	  int flag = 0;
	  for(int i = 0;i < 26;i++)
	  {
		if(a[i] != b[i]) 
		{
			flag = 1;
		} 
	}
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
	return 0 ;
}