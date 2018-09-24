难度符号说明（仅代表个人）：

 - ？多次思考可以尝试解决

思路：

- 提交的结果，用的是拓扑排序
- outdegree保存的是某顶点的出度，graph保存的是指向当前顶点的集合， queue中保存的是出度为0的顶点
- 队列不空，则依次减少某个节点的出度，如果出度为0，进队，继续。
- 循环结束，如果outdegree中出度全为0则该图无环，否则有环。