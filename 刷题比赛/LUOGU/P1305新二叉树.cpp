#include<bits/stdc++.h>
using namespace std;
struct node
{
	int fa;
	int l;
	int r;
}t[28];
void dfs(int x)
{
	char c = x+96;
	printf("%c",c);
	if(t[x].l != 0) dfs(t[x].l);
	if(t[x].r != 0) dfs(t[x].r);
}
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
	{
		string s;
		cin>>s;
	    if(s[1] != '*') {
	    	t[s[0]-96].l = s[1]-96;
	    	t[s[1]-96].fa = s[0]-96; 
	    }
	    if(s[2] != '*')
	    {
	    	t[s[0]-96].r = s[2]-96;
	    	t[s[2]-96].fa = s[0]-96;
	    }
	}
	int root = 0;
    for(int i= 1;i<=26;i++) if(t[i].fa == 0) {
          root = i;
          break;
    }
    dfs(root);
	return 0 ;
}