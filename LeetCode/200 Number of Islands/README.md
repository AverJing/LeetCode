难度符号说明（仅代表个人）：

 - ？多次思考可以尝试解决

思路：

- 此题和79题类似。
- dfs执行的是
  - 1.每访问到1，将其置为*，表示该节点已访问过。
  - 2.然后分别向上下左右递归搜索，如果上下左右递归搜索时，发现都存在0，也即res1234都是1时，表明存在。 递增count

