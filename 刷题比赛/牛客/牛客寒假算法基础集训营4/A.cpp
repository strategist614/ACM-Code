/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
	cout<<"Applese"<<endl;
	return 0 ;
}
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int fa[N];
int n,m;
void init()
{
	for(int i= 1;i <= 3*n;i++)
		fa[i] = i;
}
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)] = find(y);
}
int main ()
{
    cin>>n>>m;
    init();
    while(m--)
    {
    	int a,b;
    	cin>>a>>b;
    	int x1 = find(a),x2 = find(a+n),x3 = find(a+2*n);
        int y1 = find(b),y2 = find(b+n),y3 = find(b+2*n);
        merge(x2,y1);
        merge(x2,y2);
        merge(x1,y3);
        merge(y3,x3);
        if(y3 == x2 || y2 == x3 || y2 == x1 || y1 == x3 || y1 == x1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
	return 0 ;
}

/*
#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main ()
{
	int f1,f2,a;
	cin>>f1>>f2>>a;
    double ans = sqrt(f1*f1+f2*f2+2*f1*f2*cos(a*PI/180));
    printf("%.9f",ans);
	return 0 ;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll __int64
#define N 1000100
using namespace std;
char b[N];
ll p[N];
ll a, c;
ll quick(ll a, ll b){ //快速幂
    ll k = 1;
    while(b){
        if(b%2==1){
            k = k*a;
            k %=c;
        }
        a = a*a%c;
        b /=2;
    }
    return k;
}
void priem(){
    memset(p, 0, sizeof(p));
    ll i, j;
    p[1] = 1;
    for(i=2; i<=sqrt(N); i++){
        for(j=2; j<=N/i; j++)
            p[i*j] = 1;
    }
}
ll ola(ll n){ //欧拉函数
    ll i, j, r, aa;
    r = n;
    aa = n;
    for(i=2; i<=sqrt(n); i++){
        if(!p[i]){
            if(aa%i==0){
                r = r/i*(i-1);
                while(aa%i==0)
                    aa /= i;
            }
        }
    }
    if(aa>1)
        r = r/aa*(aa-1);
    return r;
}
int main(){
    ll d, i, j;
    priem();
    scanf("%s",b);
    string x;
    cin>>x;
    a = 2;
    //scanf("%s",b);
    ll l = strlen(b);
    ll B=0;
    c = 1e9+7;
    ll oc = ola(c);
        for(i=0; i<l; i++){
            B = B*10+b[i]-'0';
            if(B>oc)
                break;
        }
    if(i==l)
     d = quick(a,B);
        else{
            B=0;
            for(i=0; i<l; i++){ 
                B = (B*10+b[i]-'0')%oc;
            }
            d = quick(a,B);
        }
    printf("%lld\n",d);
    return 0;
}
*/
/*
#include <iostream>
#include <iomanip>
#include<string>
#include<algorithm>
#include <math.h>
#include<limits.h>
using namespace std;
 
bool huiwen(const string& s){
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}
int main(){
    string str;
    bool flag = false;
    while(cin >> str){
        if(str.size() <= 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        else
        {
            int len = str.size();
            bool flag = false;
            for(int i = 0; i < len; ++i)
            {
                string strTemp = str;
                strTemp.erase(strTemp.begin() + i);
                if(huiwen(strTemp))
                {
                    flag = true;
                    cout << "Yes" << endl;
                    break;
                }
            }
            if(!flag)
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
*/