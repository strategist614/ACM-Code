#include<bits/stdc++.h>
using namespace std;
char a[] = "`1234567890-=QWERTYUIOP[]\\ASDDFGHJKL;'ZXCVBNM,./";
int main ()
{
	int c ,i;
	while((c = getchar()) != EOF)
	{
      for(i = 1;a[i] && a[i] != c;i++);//神奇的代码 从1开始找 找到的话就是 c 没找到就是 0 
	   if(a[i]) putchar(a[i-1]);
	    else putchar(c);	
	} 
	return 0 ;
}