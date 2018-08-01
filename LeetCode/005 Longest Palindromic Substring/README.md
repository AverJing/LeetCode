直接思路：
- 写一个判断回文序列的函数（注意不是给一个字符串来判断，而是根据某个下标，找寻在当前下标下最大的回文序列，要分偶数和奇数的情况），并且记录当前序列的索引
- 主函数进行外层循环遍历整个字符串

但实际上还要更好的解决方案：
- https://articles.leetcode.com/longest-palindromic-substring-part-ii/
- https://www.felix021.com/blog/read.php?2040