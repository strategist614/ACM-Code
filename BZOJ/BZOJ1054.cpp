#include <bits/stdc++.h>
using namespace std;
char a[10][10], b[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
map<string, int> mp;
int tp[100][100];

void solve(string s)
{
    int p = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            tp[i][j] = s[p++] - '0';
        }
    }
}
string trans()
{
    string s = "";
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            s += tp[i][j] + '0';
    }
    return s;
}
struct node
{
    string str;
    int s;
};
bool judge(int x, int y)
{
    if (x < 1 || x > 4 || y < 1 || y > 4)
        return 1;
    else return 0;
}
int bfs(string st, string ed)
{
    node tmp;
    tmp.s = 0;
    tmp.str = st;
    queue<node> q;
    q.push(tmp);
    mp[tmp.str] = 1;
    while (q.size())
    {
        node _ = q.front();
        q.pop();
        if (_.str == ed)
        {
            return _.s;
        }
        solve(_.str);
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (tp[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (judge(x, y))
                            continue;
                        if (tp[x][y] == 0)
                        {
                            node nx;
                            nx.s = _.s + 1;
                            swap(tp[i][j], tp[x][y]);
                            nx.str = trans();
                            if (!mp[nx.str])
                            {
                                mp[nx.str] = 1;
                                q.push(nx);
                            }
                            swap(tp[i][j],tp[x][y]);
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    string st = "", ed = "";
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            cin >> a[i][j];
            st += a[i][j];
        }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            cin >> b[i][j];
            ed += b[i][j];
        }
    cout << bfs(st, ed) << endl;
    return 0;
}