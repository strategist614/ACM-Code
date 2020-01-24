#include <bits/stdc++.h>
using namespace std;
typedef long long lt;
#define IT set<node>::iterator
#define pir pair<lt, int>
#define mkp(x, y) make_pair(x, y)

lt read()
{
    lt f = 1, x = 0;
    char ss = getchar();
    while (ss < '0' || ss > '9')
    {
        if (ss == '-')
            f = -1;
        ss = getchar();
    }
    while (ss >= '0' && ss <= '9')
    {
        x = x * 10 + ss - '0';
        ss = getchar();
    }
    return f * x;
}

const int maxn = 100010;
int n, m;
lt a[maxn];
struct node
{
    int ll, rr;
    mutable int val;
    node(int L, int R = -1, int V = 0) : ll(L), rr(R), val(V) {}
    bool operator<(const node &tt) const { return ll < tt.ll; }
};
set<node> st;

IT split(int pos)
{
    IT it = st.lower_bound(node(pos));
    if (it != st.end() && it->ll == pos)
        return it;
    --it;
    int ll = it->ll, rr = it->rr;
    int val = it->val;
    st.erase(it);
    st.insert(node(ll, pos - 1, val));
    return st.insert(node(pos, rr, val)).first;
}

void assign(int ll, int rr, int val)
{
    IT itr = split(rr + 1), itl = split(ll);
    st.erase(itl, itr);
    st.insert(node(ll, rr, val));
}

void rev(int l, int r)
{
    IT itr = split(r + 1);
    IT itl = split(l);
    for (; itl != itr; itl++)
        itl->val ^= 1;
}

int ask(int l, int r)
{
    IT itr = split(r + 1);
    IT itl = split(l);
    int ans = 0;
    for (; itl != itr; itl++)
       ans += (itl->rr - itl->ll + 1) * itl->val;
    return ans;
}

int qmax(int l, int r)
{
    IT itr = split(r + 1);
    IT itl = split(l);
    int ans = 0, tt = 0;
    for (; itl != itr; itl++)
    {
        if (itl->val == 0)
            ans = max(ans, tt), tt = 0;
        else
            tt += itl->rr - itl->ll + 1;
    }
    return max(ans,tt);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        st.insert(node(i, i, a[i]));
    }
    while (m--)
    {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        a += 1;
        b += 1;
        if (op == 0)
        {
            assign(a, b, 0);
        }
        else if (op == 1)
        {
            assign(a, b, 1);
        }
        else if (op == 2)
        {
            rev(a, b);
        }
        else if (op == 3)
        {
            printf("%d\n", ask(a, b));
        }
        else
        {
            printf("%d\n", qmax(a, b));
        }
    }
    return 0;
}
