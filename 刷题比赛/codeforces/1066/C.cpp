#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int pos[N];
int main()
{
	int q;
	scanf("%d",&q);
	int cntl = 0;
	int cntr = 0;
 	for(int i = 1;i<=q;i++)
	{
		char op[20];
		scanf("%s",op);
		int id;
		scanf("%d",&id);
		if(i == 1)
        {
          pos[id] = cntl;
          cntl--;
          cntr++;
        }
        
        else 
        {
		 if(op[0]=='L')
		 { 
		 	pos[id] = cntl;
		 	cntl--;
		}
		else if(op[0] == 'R')
		{
		    pos[id] = cntr;
		    cntr++;
		}
		else 
		{
            int ans = 0;
            ans = min(abs(pos[id]-cntl),abs(pos[id]-cntr));
            cout<<ans-1<<endl;               
		}
	}
	}
	return 0;
}