#include<bits/stdc++.h>
using namespace std;
int vis[100005];
int main ()
{
	char s;
	int flag = 0;
	int q = 1;
	while((s = getchar()) != EOF)
	{
	   if(s == '"') {printf("%s",q ? "``" : "''" );q = !q;}
	   else printf("%c",s);
	}
	return 0 ;
}