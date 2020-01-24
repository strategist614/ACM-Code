#include<bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
struct node
{
	char f;
	char l;
	char r;
}t[10];
int lenb = 0;
int lena = 0;
int find(char c)
{
	for(int i= 0;i<lena;i++)
		if(a[i] == c)
			return i;
}
void dfs(int l1,int r1,int l2,int r2)
{
	int m = find(b[r2]);
	cout<<b[r2];
	if(m > l1) dfs(l1,m-1,l2,r2-r1+m-1);
	if(m < r1) dfs(m+1,r1,l2+m-l1,r2-1);
}
int main ()
{
    scanf("%s",a);
    scanf("%s",b);
    lena = strlen(a);
    lenb = strlen(b);
    dfs(0,lena-1,0,lenb-1);
	return 0 ;
}