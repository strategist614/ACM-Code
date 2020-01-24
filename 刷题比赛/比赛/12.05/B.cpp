#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char a[N];
char b[N];
int main()
{
    while(scanf("%s %s",a,b) != EOF)
    {
    	int sizea = strlen(a);
    	int sizeb = strlen(b);
    	if(sizea > sizeb) {cout<<"No"<<endl;continue;}
        int cnt = 0;
        for(int i =0 ;i<sizeb;i++)
        {
          if(cnt == sizea) break;
          if(b[i] == a[cnt]) cnt++;
        }
        if(cnt == sizea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
	return 0 ;
}