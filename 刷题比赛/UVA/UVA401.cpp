#include<bits/stdc++.h>
using namespace std;
const char *s = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char rev(char ch)
{
	if(isalpha(ch)) return s[ch-'A'];
	return s[ch - '0' + 25];
}
int len = 0;
int main ()
{
    char a[30];
    while(scanf("%s",a+1) == 1)
    {
       int _ = 1,__ = 1;
       int len = strlen(a+1);
       for(int i = 1;i<=len;i++)
       {
       	if(a[i] != a[len-i+1]) {_ = 0;break;}
       }
       for(int i =1;i<=len;i++)
       {
       	if(rev(a[i]) != a[len-i+1]) {__ = 0;break;} 
       }
       printf("%s -- ",a+1);
       if(_ == 1 && __ == 1) printf("is a mirrored palindrome.\n\n");
       if(_ == 0 && __ == 1) printf("is a mirrored string.\n\n");
       if(_ == 1 && __ == 0) printf("is a regular palindrome.\n\n");
       if(_ == 0 && __ == 0) printf("is not a palindrome.\n\n");	
    }
	return 0 ;
}