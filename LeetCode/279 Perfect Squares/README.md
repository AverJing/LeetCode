难度符号说明（仅代表个人）：

	- ？多次思考可以尝试解决

思路：

- [解释](https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics))

- 第一种提交方案
  - cntPerfectSquares中保存的每个值的最少平方数和的个数
  - 将求的值的解，来自于它前边数的解。
- 第二种提交方案，是把vector设定为static，看下边评论，之所以快，是因为每一个案例都公用一个vector不涉及到重新分配，速度当然快。但是只能称为一个trick。注意不能直接将第一种方案的直接设置成static，因为n的值是不固定的。
- 第三种更为强大，用到了四平方和三平方定理。以后再看