#### Link-cut-tree

##### 问题引入

* 维护一棵树，支持如下操作。
* 修改两点间路径权值。
* 查询两点间路径权值和。
* 修改某点子树权值。
* 查询某点子树权值和。 唔，看上去是一道树剖模版题。

现在加一个操作

* 断开并连接一些边，保证仍是一棵树。

**动态树问题**

- 维护一个**森林**, 支持删除某条边，加⼊某条边，并保证加边，删边之后仍是森林。我们要维护这个森林的一些信息。
- 一般的操作有两点连通性，两点路径权值和，连接两点和切断某条边、修改信息等。

##### 实链剖分

- 对于⼀个点连向它所有⼉子的边 , 我们⾃己选择⼀条边进行剖分，我们称被选择的边为实边，其他边则为虚边。
- 对于实边，我们称它所连接的⼉子为实⼉子。
- 对于⼀条由实边组成的链，我们同样称之为实链。
- 请记住我们选择实链剖分的最重要的原因：它是我们选择的，灵活且可变。
- 正是它的这种灵活可变性，我们采用 Splay Tree 来维护这些实链。

性质：

$LCT$ 维护的则是**实边**和**虚边**。

什么是实边？

我们选择一个节点与其一个儿子的连边为实边，与其他儿子的连边为虚边，这里的实边是可以随时变化的。

连续的若干条实边构成了**实链**

用每个 $splay$ 维护每条实链，可以保证，每个 $Splay$ 中维护的节点按**中序遍历得到的顺序**在原树中**深度依次增加1** 

虚边就是将这些 $splay$ 给链接起来：

- 找到该 $Splay$ 中在原树中深度最小的节点，记其为 $k$ 。（具体代码实现时是无需求出这个 $k$ 的，这里只是方便理解）
- 如果 $k$ 是原树中的根节点，则无需连边。
- 否则，我们找到 $fa_k$，将该 $Splay$ 的根节点与 $fa_k$之间连一条边。这类父亲链接与通常 Splay 的父亲链接区别在于儿子认父亲，而父亲不认儿子，对应原树的一条 **虚边** 。因此，每个联通块恰好有一个点的父亲节点为空。



变量声明：

$ch[][2]$ 左右儿子

$f[]$ 父亲指向

$sum[]$ 路径权值和

$val[]$ 点权

$tag[]$ 翻转标记

$laz[]$ 权值标记

$siz[]$ 辅助树上子树大小

##### ⼀般数据结构函数

$pushdown(x)$ 

$pushup(x)$ 

##### Splay 系函数

$Get(x)$ 获得 $x$ 是父亲的哪个儿子

$Splay(x)$ 通过和 $rotate$ 把 $x$ 旋转到当前 $splay$ 的根

$roatate(x)$ 把 $x$ 向上旋转一层

##### 新操作

##### `Access(x)` 把从根到 $x$ 的所有点放在⼀条实链里，使根到 $x$ 成为一条实路径，并且在同一棵 Splay 里。 **只有此操作是必须实现的，其他操作视题目而实现。**

`IsRoot(x)` 判断 $x$ 是否是所在树的根。

`Update(x)` 在 `Access` 操作之后，递归地从上到下 `Pushdown` 更新信息。

`MakeRoot(x)` 使 $x$ 点成为其所在树的根。

`Link(x, y)` 在 $x,y$ 两点间连一条边。

`Cut(x, y)` 把 $x,y$ 两点间边删掉。

`Find(x)` 找到 $x$ 所在树的根节点编号。

`Fix(x, v)` 修改 $x$ 的点权为 $v$ 。

`Split(x, y)` 提取出 $x, y$ 间的路径，方便做区间操作。

##### 宏定义

- `#define ls ch[p][0]`
- `#define rs ch[p][1]`

$pushup$

```c++
inline void PushUp(int p) {
  // maintain other variables
  siz[p] = siz[ls] + siz[rs];
}
```

$pushdown$

```c++
inline void PushDown(int p) {
  if (tag[p] != std_tag) {
    // pushdown the tag
    tag[p] = std_tag;
  }
}
```

$splay$ $rotate$

```c++
#define Get(x) (ch[f[x]][1] == x)
inline void Rotate(int x) {
  int y = f[x], z = f[y], k = Get(x);
  if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
  // 上面这句一定要写在前面，普通的Splay是不用的，因为 isRoot  (后面会讲)
  ch[y][k] = ch[x][!k], f[ch[y][k]] = y;
  ch[x][!k] = y, f[y] = x, f[x] = z;
  PushUp(x), PushUp(y);
}
inline void Splay(int x) {
  Update(x);  // 马上就能看到啦。 在 Splay之前要把旋转会经过的路径上的点都PushDown
  for (int fa; fa = f[x], !isRoot(x); Rotate(x)) {
    if (!isRoot(fa)) Rotate(Get(fa) == Get(x) ? fa : x);
  }
}
```

$isroot$ : 

**在前面我们已经说过，LCT 具有 如果一个儿子不是实儿子，它的父亲找不到它的性质, 所以当一个点既不是它父亲的左儿子，又不是它父亲的右儿子，它就是当前 Splay 的根**

```C++
#define isRoot(x) (ch[f[x]][0] != x && ch[f[x]][1] != x)
```

$Access$

1. 把当前节点转到根。
2. 把当前点的儿子换成之前的节点。
3. 更新当前点的信息。
4. 把当前点换成当前点的父亲，继续操作。

```C++
inline int Access(int x) {
  int p;
  for (p = 0; x; p = x, x = f[x]) {
    Splay(x), ch[x][1] = p, PushUp(x);
  }
  return p;
}
```

这里提供的 Access 还有一个返回值。这个返回值相当于最后一次虚实链变换时虚边父亲节点的值。该值有两个含义：

- 连续两次 Access 操作时，第二次 Access 操作的返回值等于这两个节点的 LCA.
- 表示 $x$ 到根的链所在的 Splay 树的根。这个节点一定已经被旋转到了根节点，且父亲一定为空。

```c++
//旋转时对每个节点下放标记
void Update(int p) {
  if (!isRoot(p)) Update(f[p]);
  pushDown(p);
}
```

`makeroot(x)` 

使指定的点成为原树的根

设 `Access(x)` 的返回值是 `y` ,则此时 `x` 到当前根的路径恰好构成一个 $splay$ ,且该 $splay$ 的根为 $y$ .

根节点是 $splay$ 中中序遍历第一个的点，此时 $x$ 是 $splay$ 中序遍历最后得到的点，所以只用翻转以 $y$ 为根的 $splay$ 树进行区间翻转

```C++
void rev(int x)
{
    swap(ch[x][0],ch[x][1]);
    tag[x] ^= 1;
}
void makroot(int x)
{
    Access(x);
    splay(x);
    rev(x);
}
```

`findroot`

==根节点是深度最小的==

找`x`所在原树的树根，主要用来判断两点之间的连通性（`findroot(x)==findroot(y)` 表明 `x,y` 在同一棵树中）

先用 $Access $ 操作将 $x$ 和 $x$ 的根节点放在一个 $splay$ 执行完 $Access$ 操作后深度最大的是点 $x$ .

在将 $x$ $splay$ 到 根节点，不断的找左子节点（因为左子节点深度比当前节点要小），直到找到最小的。

```C++
inline int Find(int p) {
  Access(p), Splay(p);
  while (ls) pushDown(p), p = ls;
  return p;
}
```

`link(x)`  

$link$ 两个点，先 $makeroot(x)$ ,然后把 $x $ 的父亲指向 $y$ .显然，这个操作肯定不能发生在同一棵树内，所以记得先判一下。 

```c++
inline void link(int x,int y)
{
    makeroot(x);
    if(findroot(y) != x) f[x] = y; //连接一条虚边
}
```

`split(x,y)`

将 $x$ 到 $y$ 之间的路径放到一颗辅助树中 ，并且 这颗辅助树以 $y$ 为根。就是维护的是 $x$ 到 $y$ 的路径

$Splay$ 维护的是原树中的一条链，不能保证 $x,y$ 会在同一条链里。

先把 $x$ 变成原树的根节点，之后再 $Access(y)$ 就会将 $x$ 到 $y$ 之间的所有节点丢到一个 $Splay$ 中了

```c++
inline void split(int x,int y){
    makeroot(x);Access(y);Splay(y);
} 
```

`cut(x,y)`

将 $x-y$ 的边断开。

如果合法 $split(x,y)$ ，这时 $y$ 是根，$x$ 一定是它的左儿子，双向断开即可。

```c++
inline void Cut(int x, int p) {
 split(x,p), ls = f[x] = 0;
 pushup(p);
}
```

如果不一定合法，那么就是这样：

```c++
inline void cut(int x,int y){
    makeroot(x);
    if(findroot(y)==x&&f[x]==y&&!ch[x][1]){
        f[x]=ch[y][0]=0;
    }return;
}
```

