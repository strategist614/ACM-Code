#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[20][20];
int b[20][20];
int main ()
{ 
    memset(b,-1,sizeof(b));
    for(int i = 1;i<=4;i++)
    	for(int j = 1;j<=4;j++)
    		cin>>a[i][j];
    int flag = 0;
    for(int i = 1;i<=4;i++)
    {
       if(flag) break;
       for(int j  =1;j<=4;j++)
       {
       	  if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j])
       	  {
       	  	 if(a[i][j] == '#' || a[i][j] == '.')
       	  	 {
       	  	  puts("YES");
       	  	  flag = 1;
       	  	  break;
       	  }
       	}
       	  if(a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1])
       	   {
       	   	 if(a[i][j] == '#' || a[i][j] == '.')
       	   	 {
       	   	 	puts("YES");
       	  	 flag = 2;
       	   	 break;
       	   }
       	}
       	   if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j+1])
       	   {
       	   	 if(a[i][j] == '#' || a[i][j] == '.')
       	     { 
       	     	puts("YES");
       	  	  flag = 3;
       	   	break;
       	   }
       	}
       	if(a[i][j+1]==a[i+1][j] && a[i][j+1]==a[i+1][j+1])
       	{
       		  if(a[i][j+1] == '#' || a[i][j+1] == '.')
       	  	 { 
                puts("YES");
       	  	 	flag = 4;
       		break;
       	}
       }
       }
    }
    if(!flag) puts("NO");
	return 0 ;
}
