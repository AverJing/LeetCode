难度符号说明（仅代表个人）：

 - ？多次思考可以尝试解决

思路：

- 思路上没有障碍，关键在如何优化。
- 还有就是关于sort的compare参数，设置自定义比较运算
  - 用lambda可以运算（用类函数调用符号、更快）
  - 用函数名出错-还不知道原因
- 还有当把比较符从 < 改为 <=会超时

- 注意若要在类内使用自定义比较运算，需要将函数变成static
- [解释](https://stackoverflow.com/questions/1902311/problem-sorting-using-member-function-as-comparator)

- 此处也可以使用bind