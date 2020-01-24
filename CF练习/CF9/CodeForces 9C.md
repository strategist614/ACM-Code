#### CodeForces 9C

* 题目
  [9C](https://vjudge.net/problem/CodeForces-9C)
* 分析
 暴力算出 $1\sim8$ 位的只包含 $0,1$ 的数即可，注意要加上 $1000000000$,最后排个序，找一下  即可。复杂度：$O(2^8\times 8)$ 
* 代码
  ```c++
std::vector<string> v;
map<string , int> mp;
int a[1000];
void dfs(int x, int ed, string s)
{
	if (x == ed + 1)
	{
		if (!mp[s]) {
			v.push_back(s);
			mp[s] = 1;
		}
		return ;
	}
	s.push_back('1');
	dfs(x + 1, ed, s);
	s.pop_back();
	s.push_back('0');
	dfs(x + 1, ed, s);
	s.pop_back();
}
bool cmp(string a, string b)
{
	int x = 0, y = 0 ;
	for (int i = 1; i <= a.size(); i++)
		x = x * i + a[i - 1] - '0';
	for (int i = 1; i <= b.size(); i++)
		y = y * i + b[i - 1] - '0';
	return x < y;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	for (int i = 1; i <= 8; i++) {
		mp.clear();
		string s = "1";
		dfs(1, i, s);
	}
	v.push_back("1");
	v.push_back("1000000000");
	sort(v.begin(), v.end(), cmp);
	int tot = 0;
	for (int i = 0; i < v.size(); i++)
	{
		a[++tot] = atoi(v[i].c_str());
	}
	sort(a + 1, a + tot + 1);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= tot; i++)
	{
		if (n >= a[i]) ans++;
		else break;
	}
	cout << ans << endl;
	return 0 ;
}
  ```
* 题型
  暴力