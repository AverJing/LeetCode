难度符号说明（仅代表个人）：

 - 注释，*代表没什么思路

思路：

- [巧妙](https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems)

- 上述连接，还给出了解决这类问题的模板。

- 将vector用作hash，将字符作为下标。

- 外层循环好理解，精髓在内层

- ```cpp
  while (counter == 0) { //valid
  				if (end - begin < d)  d = end - (head = begin);
  				if (map[s[begin++]]++ == 0) counter++;  //make it invalid
  			}
  ```

  为什么要用循环？ 1.为了找到最小长度的子串 2.改变begin时，确保改变在t中的hash下标所保存的值（因为begin当前的位置可能保存着t中的字符）	