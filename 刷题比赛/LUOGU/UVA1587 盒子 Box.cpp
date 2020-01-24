/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
struct node
{
	int x;
	int y;
}a[10];
bool cmp(node a,node b)
{
    if(a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}
int judge()
{
	if((a[1].x == a[2].x) && (a[3].x == a[4].x) && (a[2].x == a[3].x) && (a[1].y == a[2].y) && (a[5].x == a[6].x) && (a[2].y == a[5].x) && (a[4].y == a[3].y)&& (a[5].y == a[6].y) && (a[4].y == a[5].y)) return 1;
	return 0;
}		
int main ()
{
	while(scanf("%d %d",&a[1].x,&a[1].y) != EOF)
	{
		for(int i= 2;i<=6;i++) 
		{
			read(a[i].x);
			read(a[i].y);
		}
		for(int i= 1;i<=6;i++)
		{
           if(a[i].x < a[i].y) swap(a[i].x,a[i].y);
		}
		sort(a+1,a+1+6,cmp);
		/*
		  for(int i= 1;i<=6;i++)
			cout<<a[i].w<<" "<<a[i].h<<endl;
	    */
        if(judge()) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0 ;
}
 