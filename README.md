## 难度符号说明（仅代表个人）：

 - 注释，*代表没什么思路，？多次思考可以尝试解决 #代表思路顺畅，可以解决
 - 具体的思路，请看每道题目对应的README

## 说明

- 此部分包括Leetcode部分习题
- 剑指offer的部分习题
- 左神算法课程的练习
- 使用C++实现的

## 已学习到的知识总结

### 左神算法课

#### L00 04
- 反转单向链表和双向链表   用curr，prev，next注意不要断链
- 在行和列都排好序的矩阵中找数，从右上角开始
- 打印两个单链表的相交的问题，注意还要考虑有环没有。
	- 如何找到入环的节点？
		- 当快慢指针相遇时，把快指针指向头节点，快指针和慢指针都逐步更改，再次相遇的结点就是入环结点，可以数学证明
	- 两个无环，一个有环一个无环，两个有环
	- 两个有环的，还要细分
		- 在入环节点之前就相交
		- 在入环节点后相交
		- 不相交 
- 基于链表的荷兰国旗问题，可以考虑将链表放在vector中，或者将链表拆开，分为小于，等于，大于

#### L00 05
- 实现二叉树的前中后遍历，非递归版本。注意先序遍历借助栈实现时，入栈顺序是根右左；而另一种版本的后序遍历，可以将将中右左遍历的结果存在另一个栈中，再次遍历就是后序的结果。
- 二叉树的序列化和反序列化，一般在oj中使用，可以用来构建树，也可以用来判断两颗树是否相同。 注意序列化的时候，如果为空节点，需要添加特殊的符号占位，如'#\_'。 
	- 在反序列化时，注意string的split ，可以使用substr函数来实现。也可以使用istringstream使用默认的分隔符空格。
- 折纸问题，实际就是树的中序遍历，注意输出up或down。
- 判断一棵树是否是平衡二叉树，注意在求解树的问题，递归比较简单，递归函数会三次经历同一个节点。左神版本，返回两个信息，一个是子树是否是平衡的，还有子树的高度。
- 判断一棵树是否是二分搜索树，可以根据中序遍历的序列是有序的来判断。
- 判断一棵树是否是完全二叉树，左神提供的给出了是否已经访问到叶子节点的重要判断。用的是层次遍历。
- 求完全二叉树的节点个数：
	- //右子树高度是树高度-1，那么左子树节点个数是2^(H-L)，在递归求右子树
	- //右子树高度是树高度-2，那么右子树节点个数是2^(H-L-1)，在递归求左子树 

#### L00 06
- hash表的扩容，成倍扩容，logN。扩容的代价平均下来后很小。也有很多优化的技巧，如离线扩容。jvm中的hash实现一个桶中放的是红黑树。

- 注意hash函数的性质，**相同的字符串**hash后的值一定相同，不同的会混匀分布。假如处理100T的数据，找出其中相同的字符串？可以考虑将100T均匀下放到1000？台机器上，再分别处理，注意相同的一定是在一起的。

- **布隆过滤器**，存在失误率（会错杀，没有问题的可能会报错）。其是按位处理的。URL经过k个相互独立的hash函数，结果标记为1.  判断URL是否在黑名单中？如果该URL经过k个hash后的结果都被标记为1，那么它就在黑名单中。可以调整k和比特类型数组长度大小，改变失误率。
  $$
  m = - \frac{n * lnP} {(\ln2)^{2}}
  \\注：m:比特数组大小 n：样本量 P:0.0001，预期失误率
  \\k = \ln2 * \frac{m}{n} 
  \\注：k是hash函数的个数
  \\P' = (1- e^{- \frac{n * K}{m}})^{k}
  \\调整后的失误率
  $$
- **一致性hash** 

#### L00 07
- 岛问题，上下左右遍历，第一次访问到1，结果加1，已访问过的标记为2。
- 并查集，如果两个节点的代表节点（根节点）相同则在同一个集合。初始化时将每个节点看作每个独立的集合。两个集合合并，将集合元素少的合并到集合元素数量多的。注意在找head节点的过程中，将所有的子节点都直接指向head。
- 前缀树。将字母转化为下标，相当于多叉的链表。

#### L00 08

- 哈夫曼编码问题，借助于小根堆实现。
- 项目收益问题，k个项目串行，w为初始资金。先生成以cost为代价的小根堆，然后再根据生成的小根堆生成以利润为依据的大根堆（注意cost要小于初始资金）。
- 只要递归没有后效性，都可以改写动态规划


#### L01

- KMP中的next数组，以及用它如何加速匹配的
- Manacher算法 P501（左）
- BFPRT
  - 分组，5个一组
  - 组内有序
  - 中位拿出来组成新的数组，找到新数组的中位数
  - 利用新中位数划分，满足条件退出，否则在划分结果左边或右边找
- 窗口，找最大最小
  - 如题，给定一个数组，找子数组中最大值和最小值差小于等于某值的总共个数 	
  - 利用窗口记录最大和最小值，从L出发，找到第一个不满足条件的R。这样就找到了以L为中心的所有满足条件的子数组。  核心
  - [LeetCode习题](https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem)
- 单调栈
  -  可以找某个数左边和右边离他最近比他大的数
  -  过程，将下标和当前值压入栈。注意如果有相同值，把两个相同值的下标放在一起，入栈。
  -  例子：根据一个数组建立MaxTree，注意此题限制不能重复；   求最大子矩阵的大小
  -  这里边最难的就是那个  山峰问题。
- Morris遍历，步骤如下：
  - 来到的当前节点记为cur。如果cur没有左孩子，那么cur向右移动
  - 如果cur有左孩子，找到cur左子树最右边的孩子，记为mostright
    - 如果mostright的right指针为空，让它指向cur，cur向左移
    - 如果mostright的right指针指向cur，让它指向空，cur向右移动

##### L01 04
- AVL树，掌握四种调整方式，LL，LR，RL，RR
- [轮廓线](https://leetcode.com/problems/the-skyline-problem/description/)。 	
	- 将建筑起始高度分别拆开，分为上true，下false。按建筑从前到后排序。
	- hMap保存当前遍历到的节点之前的高度，rMap保存结果。

- 最长子数组
	- 记录累加和，每次从记录中找sum-aim是否在记录中存在，最后返回最长的
	- 变型题，求奇数和偶数相等的最长子数组，可以考虑把奇数=1，偶数=-1

- 求异或和为0的子数组最多分法
	- 把握住，如果[k,i]=[k,j]+[j,i] XOR = XOR ^ 0.必然存在一段为0的子数组。

#### L01 05
- 给定一颗二叉树的头节点head，请返回最大搜索二叉子树的大小。
	- **重要**  ，二叉树的题目基本上就是遍历改写递归。
	- 此题，每次整合需要以下信息
		- 左（右）边BST的头，节点个数，该树的节点最小值和最大值 

	- **递归写的时候，不妨先写一个黑盒子，假设其完成你想要的功能，想办法把得到的信息整合出新的结果。**

- 一个公司上下级关系是一棵多叉树，如果一个员工的直接上级到场，这个员工肯定不会来。返回最大的活跃值
	- 分析所有的可能性。难点在如何使用DP改进。最大的改进就是已经计算好了，就不再重复计算。

- 判断一棵树是否是平衡二叉树
- LRU

### LeetCode题目简单思路
- 007 反转整数，先将**整数转化为字符串**（标准库to_string，将各个位上的数字转化为字符，通过取余和/10运算。），再将转换后的字符串变成整数，可以通过stringstream。注意负数的处理。
- 206 反转单链表，首先判断链表是否为空，用prev，curr，next来保存位置。
- 025 按k个元素为一组，组内翻转
