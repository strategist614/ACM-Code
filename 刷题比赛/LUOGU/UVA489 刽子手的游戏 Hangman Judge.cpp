#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int chance = 7,le = 0;
int win,lose;
int t;
void guess(char ch)
{
	int bad = 1;
	for(int i= 0;i<s1.size();i++)
    {
    	if(ch == s1[i])
    	{
    		s1[i] = ' ';
    		le--;
    		bad = 0;
    	}
    }
    if(bad) --chance;
    if(!le) win = 1;
    if(!chance) lose = 1; 
}
int main ()
{
	int n;

	while(scanf("%d",&n)!=EOF)
	{
		if(n == -1) break;
        win = lose = 0;
        cin>>s1>>s2;
        chance = 7;
        le = s1.size();
        for(int i = 0;i<s2.size();i++)
        {
        	guess(s2[i]);
        	if(win || lose)
        		break;
        }
        printf("Round %d\n",n);
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
	} 
	return 0 ;
} 