#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n, m;
    cin >> n >> m;
    int cnt = n;
    for (int i = 1;;i ++){
        cnt--;
        if(i % m == 0)
            cnt++;
        if (cnt == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}