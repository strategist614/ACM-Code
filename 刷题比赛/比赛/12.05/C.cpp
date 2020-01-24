/*
#include<bits/stdc++.h>
using namespace std;
int solve(char s[])
{
	int size = strlen(s);
	for(int k,i= 1;i<=size;i++)
		{
			if(size % i == 0)
			{
			for(k = i;k<size;k++)
			{
				if(s[k] != s[k % i])
					break;
			}
			if(k == size)
			{
				return i;
			}
		  }
		}
}
int main ()
{
	  int n;
	  scanf("%d",&n);
	  while(n--)
	  {
		char op[100];
		scanf("%s",op);
		printf("%d\n",solve(op));
		if(n) printf("\n");
	  } 
	return 0 ;
}
*/
