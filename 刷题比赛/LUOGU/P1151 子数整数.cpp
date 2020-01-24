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
std::vector<int> v;
int main ()
{
	int k;
	cin>>k;
	for(int i= 10000;i<=30000;i++)
     {
     	int a1 = i/10000;
     	int a2 = i/1000%10;
     	int a3 = i/100%10;
     	int a4 = i/10%10;
     	int a5 = i%10;
     	int sub1 = a1*100+a2*10+a3;
     	int sub2 = a2*100+a3*10+a4;
     	int sub3 = a3*100+a4*10+a5;
     	if(sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) v.push_back(i);
     }
     if(v.size() == 0) {cout<<"No"<<endl;return 0;}
     for(int i= 0;i<v.size();i++)
     	cout<<v[i]<<endl;
	return 0 ;
}