难度符号说明（仅代表个人）：

 - 注释，*代表没什么思路

思路：

- [解释](https://github.com/pezy/LeetCode/tree/master/141.%20Linked%20List%20Cycle%20II)
- 关键是确定当快慢指针相遇时，慢指针在circle中走了几步，还需要多少步才能走的到circle起点。
  - 当快慢相遇时，先移动一次慢指针，在同步移动头指针和慢指针，相等即为所求。
- 解释的很好。 不太好理解。