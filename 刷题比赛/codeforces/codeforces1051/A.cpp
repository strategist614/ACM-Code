/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
int fun1(int x)
{
  return -x+d;
}
int fun2(int x)
{
  return x-d;
}
int fun3(int x)
{
  return x+d;
}
int fun4(int x)
{
  return -x + 2*n-d;
}
int main ()
{
  //int n,d;
  cin>>n>>d;
  int m;
  cin>>m;
  while(m--)
  {
    int x,y;
    cin>>x>>y;
    if(d < n - d)
   {
    if(x <= d)
      {
        int y1 = fun1(x);
        int y3 = fun3(x);
        if(y<=y3 && y >= y1)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
      else if(x > d && x <= n-d)
      {
        int y2 = fun2(x);
        int y3 = fun3(x);
        if(y <= y3 && y >= y2)
        {

          cout<<"YES"<<endl;
        }
        else
         cout<<"NO"<<endl;
      }
      else
      {
        int y2 = fun2(x);
        int y4 = fun4(x);
        if(y<=y4 && y>=y2)
        {
          cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
      }
    }
    else if(d == n-d)
    {
      if(x <= d)
      {
        int y1 = fun1(x);
        int y3 = fun3(x);
        if(y >= y1 && y <= y3)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
      else
      {
        int y4 = fun4(x);
        int y2 = fun2(x);
        if(y >= y2 && y<=y4)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
    }
    else
    {
      if(x <= n - d)
      {
        int y1 = fun1(x);
        int y3 = fun3(x);
        if(y <= y3 && y >= y1)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
      else if(x > n-d && x<=d)
      {
        int y4 = fun4(x);
        int y1 = fun1(x);
        if(y<=y4 && y>=y1)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
      else
      {
        int y2 = fun2(x);
        int y4 = fun4(x);
        if(y <= y4 && y >= y2)
        {
          cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
      }
    }
  }
  return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1000+10;
int  mp[N];
int t,tp;
int dfs(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=mp[i];
		if(cnt==x)
		{
			cnt=0;
		}
		else if(cnt>x)
		{
			return 0;
		}
	}
	if(cnt==0)return 1;
	else return 0;
}
int main()
{
	cin>>n;
	char a;
	int flag=0;
//1	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='1')
		{
			mp[i]=1;
			t+=mp[i];
		}
		else if(a=='2')
		{
			mp[i]=2;
			t+=mp[i];
		}
		else if(a=='3')
		{
			mp[i]=3;
			t+=mp[i];
		}
		else if(a=='4')
		{
			mp[i]=4;
			t+=mp[i];
		}
		else if(a=='5')
		{
			mp[i]=5;
			t+=mp[i];
		}
		else if(a=='6')
		{
			mp[i]=6;
			t+=mp[i];
		}
		else if(a=='7')
		{
			mp[i]=7;
			t+=mp[i];
		}
		else if(a=='8')
		{
			mp[i]=8;
			t+=mp[i];
		}
		else if(a=='9')
		{
			mp[i]=9;
			t+=mp[i];
		}
		else if(a=='0')
		{
			mp[i]=0;
			t+=mp[i];
		}
	}
	if(t==0){
		cout<<"YES"<<endl;
		return 0;
	}
	else for(int i=1;i<t;i++)
	{
		if(t%i==0&&t/i<=n)
		{
			if(dfs(i)==1)
			{
				flag=1;
			}
		}
		if(flag==1) break;
	}
	if(flag==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
