#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	int n,i,j,k;
	int cnt;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		while(n!=1)
		{
			if(n&1)
				cnt+=2;
			else
				cnt++;
			n/=2;
		}
		printf("%d\n",cnt);
	}
	return 0;
}