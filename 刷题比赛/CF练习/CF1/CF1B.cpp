#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 
const int INF = 1 << 29;

void solve1(string s, int b){
    int tem = 0;
    string ans;
    for(int i = b+1; i < s.size(); i++){
        tem = tem * 10 + s[i] - '0';
    }
    vector<char> v;
    while(tem > 0){
        tem --;
        v.push_back((tem%26) + 'A');
        tem /= 26;
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++){
        cout << v[i];
    }
    for(int i = 1; i < b; i ++){
        cout << s[i];
    }
    cout << endl;
}
void solve2(string s){
    int b = INF;
    cout << "R";
    int ans = 0;
    for(int i = 0; i <s.size(); i ++){
        if(isdigit(s[i])) {
            cout << s[i];
            b = min(b, i);  
        }
    }
    for(int i = 0; i < b; i ++){
        ans *= 26;
        ans += (s[i] - 'A' + 1);
    }
    cout << "C" << ans << endl;
}
void solve(string s){
    for(int i = 1; i < s.size(); i ++){
        if(s[i] == 'C' && isdigit(s[i-1])){
            solve1(s, i);
            return ;
        }
    }
    solve2(s);
    return ;
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        solve(s);
    }
    return 0;
}