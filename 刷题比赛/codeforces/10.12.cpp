/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	ll L,v,l,r;
    	cin>>L>>v>>l>>r;
    	ll ans = 0;
    	ll tmp1 = r/v;
    	ll tmp2 = (l-1)/v;
    	ll tmp3 = L/v;
    	//cout<<tmp3<<endl;
    	cout<<(tmp3)-(tmp1-tmp2)<<endl;
    }
	return 0 ;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005];
int vis[1005];
//int v[1005];
vector<int> v;
int main ()
{
    int n,r;
    cin>>n>>r;
    for(int i =1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i =1;i<=n;i++)
    {
    	if(a[i] == 1) v.push_back(i);
    }
    for(int i = 1;i<=n;i++)
    {
       if(a[i] == 1 && !vis[i] ) 
       {
       	   ans++;
       	   for(int j = i;j <= i+r-1;j++) {if(j > n) break; vis[j] = 1;}
       	   for(int j = i;j >= i-r+1;j--) {if(j < 1) break; vis[j] = 1;}
       }
    }	
  //  for(int i= 0;i<v.size();i++) cout<<v[i]<<" ";
    int ll = 0;
    int lll = 0;
     for(int i =1;i<=n;i++)
     {
         if(!vis[i])
         {
         	if(a[i] == 0) 
         	{
              lll = 0;
         	  int tmp1 = 0;
         	  int tmp2 = 0;
              for(int j = 0;j<v.size();j++)
              {
              	  if(i < v[j])  {tmp1 = v[j-1];break;}
              }
              for(int j = 0;j<v.size();j++)
              {
              	  if(i < v[j]) {tmp2 = v[j];break;}
              }
              int cnt1 = i - tmp1;
              int cnt2 = tmp2 - i;
              int cnt = min(cnt1,cnt2);
              if(cnt <= r-1) ll++; 
         	}
         }
     }
     if(ans+ll == n)
     {
        cout<<-1<<endl;
        return 0;
     }
     if(lll > ll) 
     {
     	cout<<-1<<endl;
     	return 0;
     }
     cout<<ans+ll<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
list<int> l;
int main ()
{
    int q;
    scanf("%d",&q);
    list<int>::iterator it;

    while(q--)
    {
    	char op[20];
    	scanf("%s",op);
    	if(op[0] == 'L')
    	{
    		int x;
    		scanf("%d",&x);
            l.push_front(x); 
    	}
    	else if(op[0] == 'R') 
    	{
    		int x;
    		scanf("%d",&x);
            l.push_back(x);-
    	}
    	else 
    	{
             int x;
             scanf("%d",&x);
             it = find(l.begin(),l.end(),x);
             int size = l.size();
             int ans = 0;
             printf("%d\n",it);
    	}
    }    
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{

	return 0 ;
}
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
/*#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
*/	
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	int last = -1;
	while (last < n - 1) {
		int pos = -1;
		for (int i = n - 1; i > max(-1, last - r + 1); --i) {
			if (a[i] == 1 && i - r <= last) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			cout << -1 << "\n";
			return 0;
		}
		++ans;
		last = pos + r - 1;
	}
	
	cout << ans << "\n";
	
	return 0;
}