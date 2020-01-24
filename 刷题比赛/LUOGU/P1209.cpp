/*不对
#include<bits/stdc++.h>
using namespace std;
int a[205];
std::vector<int> v;
map<int,pair<int,int>> mp;
std::vector<int> ansv;
int main ()
{
	int m,s,c;
	cin>>m>>s>>c;
	for(int i = 1;i<=c;i++) cin>>a[i];
	sort(a+1,a+c+1);
    if(m > c)
    {
    	cout<<c<<endl;
    	return 0 ;
    }
    for(int i = 1;i <= c-1;i++)
    {
    	v.push_back(a[i+1]-a[i]);
    	mp[(a[i+1]-a[i])] = make_pair(a[i],a[i+1]);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i = 0;i < m-1;i++)
    {
        ansv.push_back(mp[v[i]].first);
        ansv.push_back(mp[v[i]].second);
    } 
    ansv.push_back(a[1]);
    ansv.push_back(a[c]);
    sort(ansv.begin(),ansv.end());
    int ans = 0;
    for(int i = 0;i<ansv.size()-1;i+= 2)
    {
       ans += ansv[i+1]-ansv[i] + 1;
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int a[205];
int b[205];
bool cmp(int x,int y)
{
	return x > y ;
}
int main ()
{
	int m,s,c;
	cin>>m>>s>>c;
	for(int i =1;i<=c;i++) cin>>a[i];
	 if(m>c) { 
        printf("%d\n",c);
        return 0;
    }
	sort(a+1,a+c+1);
    int ans = a[c]-a[1]+1;
    int tot = 0;
    for(int i= 1;i<=c-1;i++) b[++tot] = a[i+1]-a[i];
    sort(b+1,b+tot+1,cmp);
    //for(int i= 1;i<=tot;i++) cout<<b[i]<<" ";
    for(int i =1;i<=m-1;i++)
    	ans = ans - b[i] + 1;
    cout<<ans<<endl;
	return 0 ;
}
/*
此题的算法是这样的，首先用一块木板从第一个牛的位置覆盖到最后一个牛的位置。

然后反复调用“增加block过程”，直到所使用的木板数达到题目给出的限制，或空白全部被填满。

这样得到的状态S(ｐ)就是最优状态。［ｐ等于给出的可用木板数与空白数的较小值］

这个一个贪心算法，下面使用一个循环不变式证明它的正确性，这里假设没有两个空白具有相同的长度

(因为当最长的空白有多个时可以选择任意一个，所以这种假设是可行的)。

循环不变式：在首先用一块木板从第一个牛的位置覆盖到最后一个牛的位置后

(得到状态S(1))，每次调用“增加block过程”后得到的状态S(ｉ)均是最优的

。 初始：容易看出S(1)是最优的。

中间：假设S(k)是最优的，则使用“增加block过程”后S(k+1)也是最优的，

下面用反证法来证明。 如果S(k+1)不是最优的，则存在S'(k+1)最优，

使得 |S'(k+1)| < |S(k+1)|，且S'(k+1)不等于S(k+1) 设在S(k)到S(k+1)的转变中我们去掉的那个最长的空白为b,

则有 |S(k+1)| = |S(k)| - |b|， 又因为|S'(k+1)| < |S(k+1)|， 所以有|S'(k+1)| <　|S(k)| - |b|，即　|S(k)|　> |S'(k+1)| + |b|　＜１式＞， 当S'(k+1)没有覆盖ｂ时， 我们可以把ｂ两头的木板连起来覆盖ｂ得到S'(k),且有 |S'(k)| = |S'(k+1)| + |b|， 根据＜１式＞有 |S(k)| > |S'(k)|　，这与假设S(k)最优矛盾。 当S'(k+1)覆盖了ｂ时，因为ｂ是S(k)中最长的空白，则S'(k+1)中一定存在一个没有覆盖的空白d,使得 |d| < |b|， 这是因为如果ｄ不存在的话表明前ｋ次删除空白时我们删除了最长的ｋ个空白(b是第ｋ长的) ，这意味着S'(k+1)等于S(k+1)，别忘了我们假设没有两个空白具有相同的长度。 因此S'(k+1)覆盖了ｂ时ｄ一定存在，此时如果在S'(k+1)中交换ｂ、ｄ（不覆盖ｂ，而覆盖ｄ），则可得S(k+1)， 又因为 |d| < |b| ， 所以 |S(k+1)| < |S'(k+1)|，这与S'(k+1)最优矛盾。 由此可知S(k+1)是最优的，即算法正确。
*/