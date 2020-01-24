#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
  int tt = 0;
	while(t--)
	{
		string str;
		cin >> str;
		int n = str.size();
		printf("Case #%d: ",++tt);
		if(n > 3)
		{
      cout<<317<<endl;
		}
    else
    {
      int ans = atoi(str.c_str());
      if(ans >= 317)
      {
        cout<<317<<endl;
     }
     else if(ans<317 && ans>=311)
     {
       cout<<311<<endl;
     }
     else if(ans < 311 && ans >= 173)
     {
       cout<<173<<endl;
     }
     else if(ans < 173 && ans >= 137)
     {
       cout<<137<<endl;
     }
     else if(ans < 137 && ans >= 131)
     {
       cout<<131<<endl;
     }
     else if(ans < 131 && ans >= 113)
     {
       cout<<113<<endl;
     }
    else if(ans < 113 && ans >= 73)
    {
      cout<<73<<endl;
    }
    else if(ans < 73 && ans >= 71)
    {
      cout<<71<<endl;
    }
    else if(ans < 71 && ans >=53)
    {
      cout<<53<<endl;
    }
    else if(ans < 53 && ans >=37)
    {
      cout<<37<<endl;
    }
    else if(ans < 37 && ans >= 31)
    {
       cout<<31<<endl;
    }
    else if(ans < 31 && ans >= 23)
    {
       cout<<23<<endl;
    }
    else if(ans < 23 && ans >= 17)
    {
       cout<<17<<endl;
    }
    else if(ans < 17 && ans >= 13)
    {
       cout<<13<<endl;
    }
    else if(ans < 13 && ans >= 11)
    {
       cout<<11<<endl;
    }
    else if(ans <11 &&ans >= 7)
    {
       cout<<7<<endl;
      }
    else if(ans < 7 && ans >= 5)
    {
       cout<<5<<endl;
    }
    else if(ans < 5&&ans >= 3)
    {
       cout<<3<<endl;
    }
    else if(ans < 3 &&ans >=2)
    {
       cout<<2<<endl;
    }
    }
	}
	return 0;
}
