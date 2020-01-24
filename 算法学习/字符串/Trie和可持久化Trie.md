$Trie$ 和可持久化 $Trie$

##### $Tire$ 

* 字典树是一种用于是实现字符串快速检索的**多叉树**结构, $Trie$ 的每个节点都拥有若干个字符指针，若在插入或检索字符串时扫描到一个字符 $c$ ,就沿着当前节点的 $c$ 字符指针走向该指针指向的节点。

* 插入：

  ```c++
  void insert(char* str) {
  	int len = strlen(str), p = 1;
  	for (int k = 0; k < len; k++) {
  		int ch = str[k]-'a'; // 字符域
  		if (trie[p][ch] == 0) trie[p][ch] = ++tot; // 新建节点，更新当前指针
  		p = trie[p][ch]; // 指针向下指
  	}
  	end[p] = true; // 结尾打上标记
  }
  ```

* 检索：
  ```c++
  bool search(char* str) {
	int len = strlen(str), p = 1;
	for (int k = 0; k < len; k++) {
		p = trie[p][str[k]-'a']; 
		if (p == 0) return false; 
	}
	    return end[p];
  }
  ```

* 空间复杂度 ： $O(NC) $ 

* 例题：

  [UVA11362](https://cn.vjudge.net/problem/UVA-11362)

* 参考博客 : [lyd]() 
                         [dalao](https://www.luogu.org/blog/sdlang/Trie-study-text)

##### $01Trie$ 

