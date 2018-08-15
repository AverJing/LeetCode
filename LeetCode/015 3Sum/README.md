难度：

	- ？多次思考可以尝试解决

思路：

- 方法是O(n^2)，
- [解释](https://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-a-given-number)
- 但是要考虑到特殊情况，比如空或者长度小于2时，否则会无限循环；还有记得不要用else包裹三元运算符，否则同样会无限循环。
- 可是有一个测试案例超时。。。。。稍等再调整
- [对算法进行优化](https://www.cnblogs.com/grandyang/p/4481576.html)
- 优化的部分在代码进行了注释
- 此题和016类似，下题将采用迭代器方式实现