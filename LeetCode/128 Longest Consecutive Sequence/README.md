难度符号说明（仅代表个人）：

 - 注释，*代表没什么思路

思路：

- 提交的方案是用空间交换时间，
- [解释](https://github.com/pezy/LeetCode/tree/master/127.%20Longest%20Consecutive%20Sequence)
  - 难点就在于更新连续序列，如何找到连续序列的边界呢。
  - 着重理解map[e - map[e-1]] = map[e + map[e+1]] = map[e]; 这句解决了上边的问题。