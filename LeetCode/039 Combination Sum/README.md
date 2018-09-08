难度符号说明（仅代表个人）：

 - ？多次思考可以尝试解决

思路：

- 难在如何写出DFS搜索算法。  回溯法很重要。

  ```cpp
  // 从 2 开始, 因为允许重复摘取，所以先不断重复 2
  2,2,2 // 到这里 sum = 6，如果再取 2，则为 8，已经超过了目标值 7.
  // 既然 2不行，那么开始往后寻找 3，6，7 等，显然，都不符合。
  // 于是我们退一步，重复两遍 2 ，然后第三个数从 3 开始
  2,2,3 // 这时 sum = 7, 恰好为我们的目标值，这个数组便是我们想要的一组。
  // 后续可以尝试 6，7，显然都不符合。
  // 继续我们的思路，从 一个 2 开始。
  2,3 // 这时 sum = 5, 如果再取 3 ，则为8， 超过目标值 7.
  // 重复 3 不行，后续呢，6，7，显然超了。
  // 仍然继续
  3,3 // 此刻 sum = 6, 再来 3 一定不行。后面的6，7 显然也不行。
  // 再来的话，就是6 开头，显然没戏。
  7 // 此刻 sum = 7, 再次符合咱们的要求。 记录之。
  ```