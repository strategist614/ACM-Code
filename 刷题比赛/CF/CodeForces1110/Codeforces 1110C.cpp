#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
map<int,int> mp;
int main ()
{
	int q;
	cin>>q;
    mp[1] = 0;
    mp[3] = 1;
    mp[7] = 1;
    mp[15] = 5;
    mp[31] = 1;
    mp[63] = 21;
    mp[127] = 1;
    mp[255] = 85;
    mp[511] = 73;
    mp[1023] = 341;
    mp[2047] = 89;
    mp[4095] = 1365;
    mp[8191] = 1;
    mp[16383] = 5461;
    mp[32767] = 4681;
    mp[65535] = 21845;
    mp[131071] = 1;
    mp[262143] = 87381;
    mp[524287] = 1;
    mp[1048575] = 349525;
    mp[2097151] = 299593;
    mp[4194303] = 1398101;
    mp[8388607] = 178481;
    mp[16777215] = 5592405;
    mp[33554431] = 1082401;
	while(q--)
	{
		int x;
		cin>>x;
        int cnt = 0;
        if(x == 1)
        { 
            cout<<0<<endl;
            continue;	
        }
        if(mp[x] != 0) 
        {
        	cout<<mp[x]<<endl;
        }
        else 
        {
	     while(x)
	     {
            x /= 2;
            cnt++;
	     }
	     int ans = 0;
	     for(int i = 0;i < cnt;i++)
	     {
           ans += powmod(2,i);
	     }
	    cout<<ans<<endl;
	  }
	}
	return 0  ;
}