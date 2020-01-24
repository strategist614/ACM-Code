/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<int> v[30];
int ord[30];
int a,b,_a,_b;
string tmp;
void move_onto()
{
	int posa = 0,posb = 0 ,len = 0;
	for(int i= 0;i<v[_a].size();i++)
      {
           if(v[_a][i] == a)
           {
                posa = i;
                for(int j= i+1;j<v[_a].size();j++)
                  {
                    v[v[_a][j]].push_back(v[_a][j]);
                    ord[v[_a][j]] = v[_a][j];
                  }
                     break;
                  }
       }
     len = v[_a].size();
    for(int i= posa;i<len;i++) v[_a].pop_back();
    for(int i = 0;i<v[_b].size();i++)
    {
       if(v[_b][i] == b)
       {
           posb = i+1;
           for(int j= i+1;j<v[_b].size();j++)
           {
           	 v[v[_b][j]].push_back(v[_b][j]);
           	 ord[v[_b][j]] = v[_b][j];
           }
           break;
       }
    }
    len = v[_b].size();
    for(int i = posb;i<len;i++) v[_b].pop_back();
    v[_b].push_back(a);
    ord[a] = _b;
}
void move_over()
{
	int posa = 0;
    int len = 0;
    for(int i= 0;i<v[_a].size();i++)
    {
    	if(v[_a][i] == a)
    	{
    		posa = i;
    		for(int j= i+1;j<v[_a].size();j++)
    		{
    			v[v[_a][j]].push_back(v[_a][j]);
    			ord[v[_a][j]] = v[_a][j];
    		}
    		break;
    	}
    }
    len = v[_a].size();
    for(int i= posa;i<len;i++) v[_a].pop_back();
    v[_b].push_back(a);
    ord[a] = _b;
}
void pile_onto()
{
    int posb = 0,len = 0,posa = 0;
    for(int i= 0;i<v[_b].size();i++)
    {
    	if(v[_b][i] == b)
    	{
    		posb = i+1;
    		for(int j= i+1;j<v[_b].size();j++)
    		{
                v[v[_b][j]].push_back(v[_b][j]);
                ord[v[_b][j]] = v[_b][j]; 
    		}
    	}
    }
    len = v[_b].size();
    for(int i= posb;i<len;i++) v[_b].pop_back();
    for(int i= 0;i<v[_a].size();i++)
    {
        if(v[_a][i] == a)
        {
        	posa = i;
        	for(int j = i;j<v[_a].size();j++)
        	{
        		v[_b].push_back(v[_a][j]);
        		ord[v[_a][j]] = _b;
        	}
        }
    }
    len = v[_a].size();
    for(int i= posa;i<len;i++) v[_a].pop_back();
}
void pile_over()
{
   int posa = 0,len = 0;
   for(int i = 0;i<v[_a].size();i++)
   {
   	 if(v[_a][i] == a)
   	 {
   	 	posa = i;
   	 	for(int j = i;j<v[_a].size();j++)
   	 	{
   	 		v[_b].push_back(v[_a][j]);
   	 		ord[v[_a][j]] = _b;
   	 	}
   	 }
   }
   len = v[_a].size();
   for(int i = posa;i<len;i++) v[_a].pop_back();
}
int main ()
{
	int n;
	cin>>n;
	string s;
	for(int i= 0;i<n;i++)
	{
		v[i].push_back(i);
        ord[i] = i;
	}
	while(cin>>s && s != "quit")
	{
		if(s == "move")
		{
           cin>>a>>tmp>>b;
           if(tmp == "onto")
           {
              _a = ord[a];
              _b = ord[b];
              if(_a == _b) continue;
              move_onto();
            }
           else 
           {
              _a = ord[a];
              _b = ord[b];
             if(_a == _b) continue;
             move_over();
           }  
		}
		else 
		{
          cin>>a>>tmp>>b;
          if(tmp == "onto")
          {
            _a = ord[a];
            _b = ord[b];
            if(_a == _b) continue;
            pile_onto();   
          }
          else 
          {
            _a = ord[a];
            _b = ord[b];
            if(_a == _b) continue;
            pile_over();   
          }
		}
	}
	 for(int i= 0;i<n;i++){
	        cout<<i<<":";
	    	for(int j= 0;j< v[i].size();j++)
	    		{
	    			cout<<" "<<v[i][j];
	    		}
	        cout<<endl;
	    }
	return 0 ;
}
