/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string str[1500];
map<string,int> mp;
std::vector<int> v;
void _north()
{
   int nor = mp["north"];
   int sou = mp["south"];
   int din = mp["ding"];
   int di = mp["di"];
   mp["di"] = nor;
   mp["north"] = din;
   mp["ding"] = sou;
   mp["south"] = di;
}
void _west()
{
  int we = mp["west"];
  int ea = mp["east"];
  int din = mp["ding"];
  int di = mp["di"];
  mp["di"] = we;
  mp["west"] = din;
  mp["ding"] = ea;
  mp["east"] = di;
}
void _east()
{
  int we = mp["west"];
  int ea = mp["east"];
  int din = mp["ding"];
  int di = mp["di"];
  mp["di"] = ea;
  mp["east"] = din;
  mp["ding"] = we;
  mp["west"] = di;
}
void _south()
{
   int nor = mp["north"];
   int sou = mp["south"];
   int din = mp["ding"];
   int di = mp["di"];
   mp["di"] = sou;
   mp["south"] = din;
   mp["ding"] = nor;
   mp["north"] = di;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0) break;
        for(int i =1;i<=n;i++) cin>>str[i];
        mp["ding"] = 1;
        mp["north"] = 2;
        mp["west"] = 3;
        mp["di"] = 6;
        mp["south"] = 5;
        mp["east"] =  4;
        for(int i= 1;i<=n;i++)
        { 
            if(str[i] == "north")
            {
            	_north();
            }
            else if(str[i] == "east")
            {
            	_east();
            }
            else if(str[i] == "west")
            {
            	_west();
            }
            else _south();
        }   
        cout<<mp["ding"]<<endl;	
	}
	return 0 ;
}
