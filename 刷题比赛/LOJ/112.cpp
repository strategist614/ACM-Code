/*
#include<bits/stdc++.h>
#define debug(x) std::cout << #x << " = " << x << std::endl;
using int_t = long long int;

using namespace std;

const int_t LARGE = 100000;

struct Query
{
    int_t pos[3];
    int_t mark;
    int_t *result = 0;
    int_t count = 0;
    int_t &operator[](int_t x)
    {
        return pos[x];
    }
    bool operator==(const Query &x)
    {
        for (int_t i = 0; i < 3; i++)
        {
            if (pos[i] != x.pos[i])
                return false;
        }
        return true;
    }
};
Query querys[LARGE + 1];
int_t n, k;
//第二个CDQ分治，对第三维坐标进行排序并统计答案
void process2(Query *querys, int_t left, int_t right)
{
    if (left == right)
        return;
    static Query temp[LARGE + 1];
    int_t mid = (left + right) / 2;
    process2(querys, left, mid);
    process2(querys, mid + 1, right);
    int_t uleft = left;
    int_t uright = mid + 1;
    int_t curr = 0;
    //这个for循环写的可能有点晦涩难懂
    //大概就是把普通归并排序合并有序表的三个过程直接结合起来了
    for (int_t i = left; i <= right; i++)
    {
        //uleft uright写成了left right
        //这种烂错误调了一晚上
        
        //能从左边序列中拿出一个元素的条件是左边序列的第一个元素较小或者右边序列已经为空
        if (((uright > right) || querys[uleft].pos[2] <= querys[uright].pos[2]) && uleft <= mid)
        {
            temp[i] = querys[uleft];
            uleft++;
            //之所以要加这个判断，是因为我们对第三维的排序打乱了原来的第二维的状态
            //所以我们设置了一个标记记录了原来第二维的有序性
            //这个标记就是mark，mark为true表示这个查询原来在左边
            if (temp[i].mark != 0)
            {
                //因为元素去重的原因，所以需要乘上元素个数
                curr += (temp[i].mark * temp[i].count);
            }
        }
        else
        {
            temp[i] = querys[uright];
            uright++;
            if (temp[i].mark == 0)
            {
                *temp[i].result += curr;
                // cout << "counting " << curr << " to " << temp[i] << endl;
            }
        }
    }
    std::copy(temp + left, temp + right + 1, querys + left);
}

void process1(Query *querys, int_t left, int_t right)
{
    if (left == right)
        return;
    static Query temp[LARGE + 1];
    int_t mid = (left + right) / 2;
    process1(querys, left, mid);
    process1(querys, mid + 1, right);
    int_t uleft = left;
    int_t uright = mid + 1;
    for (int_t i = left; i <= right; i++)
    {
        if (((uright > right) || querys[uleft].pos[1] <= querys[uright].pos[1]) && uleft <= mid)
        {
            temp[i] = querys[uleft];
            //需要做好这个标记，因为对第三维排序后第二维就无序了
            temp[i].mark = 1;
            uleft++;
        }
        else
        {
            temp[i] = querys[uright];
            //为了防止误统计答案，第二维在右边的需要把标记设置为0
            temp[i].mark = 0;
            uright++;
        }
    }
    std::copy(temp + left, temp + right + 1, querys + left);
    //递归处理第三维
    //注意不要把::querys传进去，因为我们process1的作用是对第二维进行排序，如果再调用process2给第三维排序，而且使用的还是同一个数组，那么我们就打乱了第二维的顺序
    process2(temp, left, right);
}

int main()
{
    int_t _n;
    cin >> n >> k;
    //保存一下n
    _n = n;
    //一个内存池，用来记录查询的答案
    static int_t results[LARGE + 1];
    for (int_t i = 1; i <= n; i++)
    {
        cin >> querys[i].pos[0] >> querys[i].pos[1] >> querys[i].pos[2];
    }
    //排序去重
    std::sort(querys + 1, querys + 1 + n, [](const Query &a, const Query &b) -> bool {
        if (a.pos[0] == b.pos[0])
        {
            if (a.pos[1] == b.pos[1])
            {
                return a.pos[2] < b.pos[2];
            }
            else
            {
                return a.pos[1] < b.pos[1];
            }
        }
        else
        {
            return a.pos[0] < b.pos[0];
        }
    });
    //去重
    int_t first = 1;
    querys[1].count++;
    for (int_t i = 2; i <= n; i++)
    {
        if (querys[i] == querys[first])
        {
            querys[first].count++;
        }
        else
        {
            first = i;
            querys[first].count++;
        }
    }
    n = std::remove_if(querys + 1, querys + 1 + n, [](const Query &x) -> bool { return x.count == 0; }) - querys - 1;
    //给去重后的每一个元素分配一个int指针用来保存结果，因为我们是在process2中统计结果的，而process2中无法对::querys数组做出修改
    for (int_t i = 1; i <= n; i++)
    {
        querys[i].result = results + i;
    }
    process1(querys, 1, n);
    //结果数组
    static int_t result[LARGE + 1];
    for (int_t i = 1; i <= n; i++)
    {
        //因为我们去过重，所以需要给每一个三元组加上这个三元组的个数-1，因为这些东西也对这个三元组的答案做出了贡献
        *querys[i].result += querys[i].count - 1;
        result[*querys[i].result] += querys[i].count;
    }
    for (int_t i = 0; i < _n; i++)
        cout << result[i] << endl;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node 
{
    int x;
    int y;
    int z;
    int ans;
    int cnt;
}a[N],b[N];
int c[N];
bool cmp(node a,node b)
{
    if(a.x == b.x) 
    {
       if(a.y == b.y) return a.z < b.z;
       else return a.y < b.y;
    }
    else return a.x < b.x;
}
struct treearray
{
    void add(int x,int y)
    {
        for(;x<=N;x+=x&-x) c[x]+=y;
    }
    int ask(int x)
    {
        int ans = 0;
        for(;x;x-=x&-x) ans+=c[x];
        return ans;
    }
}ta;
void CDQ(int l,int r)
{
    if(l == r) return ;
    int mid = (l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
    int i = l;
    int j = mid+1;
    for(int k = l;k <= r;;k++)
    {
       if(j > r || (b[i].y <= b[j].y && i<=mid))
       {
          ta.add(b[i].z,b[i].cnt);
          used[k]++;
          b[k] = a[i++]; 
       } 
       else 
       {
         
       }
    }
}
int main ()
{
    int n,k;
    cin>>n>>k;
    for(int i= 1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+n+1,cmp);
    
    return 0 ;
}