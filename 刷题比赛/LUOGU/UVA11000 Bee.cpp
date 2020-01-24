/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 90+5;
unsigned long long a[N],b[N];
int main ()
{
	int n;
	a[0] = 0;
	b[0] = 1;
	for(int i= 1;i<=N;i++)
	{
       a[i] = b[i-1];
       b[i] = b[i-1] + a[i-1]+1;
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n == -1) break;
        cout<<a[n]<<" "<<b[n]<<endl;
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 90+5;
ull a[N];
ull b[N];
int main ()
{
    int n;
    a[1] = 1;
    a[2] = 2;
    for(int i =3;i<=N;i++)
        a[i] = a[i-1]+a[i-2];
    b[1] = 1;
    for(int i = 2;i<=N;i++)
       b[i] = b[i-1]+a[i-1];
    while(scanf("%d",&n)!=EOF)
    {
        if(n == -1) break;
        cout<<b[n]<<" "<<b[n+1]<<endl;
    }
    return 0 ;
}