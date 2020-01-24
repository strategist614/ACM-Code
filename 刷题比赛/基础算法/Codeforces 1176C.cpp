/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
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
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
priority_queue<int,vector<int>,greater<int> > q1,q2,q3,q4,q5,q6;
int a[500005];
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i <= n;i++) cin>>a[i];
	for(int i =1;i <= n;i++){
		if(a[i] == 4)
		{
           q1.push(i);
		} 
		else if(a[i] == 8)
		{
           q2.push(i);
		}
		else if(a[i] == 15)
		{
           q3.push(i);
		}
		else if(a[i] == 16)
		{
           q4.push(i);
		}
		else if(a[i] == 23)
		{
			q5.push(i);
		}
		else q6.push(i);
	}
	int ans = 0;
	while(q1.size() && q2.size() && q3.size() && q4.size() && q5.size() && q6.size()){
         int x1 = q1.top();
         int x2 = q2.top();
         int x3 = q3.top();
         int x4 = q4.top();
         int x5 = q5.top();
         int x6 = q6.top();
         if(x1 >= x2) {q2.pop();continue;}
         else if(x2 >= x3) {q3.pop();continue;}
         else if(x3 >= x4) {q4.pop();continue;}
         else if(x4 >= x5) {q5.pop();continue;}
         else if(x5 >= x6) {q6.pop();continue;}
         else {
         	q1.pop();
         	q2.pop();
         	q3.pop();
         	q4.pop();
         	q5.pop();
         	q6.pop();
         	ans ++;
         }
	} 
	cout<<n - 6 * ans <<endl;
	return 0 ;
} 