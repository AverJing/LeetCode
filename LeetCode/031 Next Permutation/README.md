难度：

	- *代表没什么思路，

思路：

 - 首先把题意理解到位
    - Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
    - 意味着新的排列要大于源排列，例子如下 abcd->abdc->acbd->acdb->adbc->adcb->...依次往下
    - If such arrangement is not possible, it must rearrange it as the lowest possible order
    - 意味着如果不存在上述排列，则按从小到大的顺序（其实就是逆置源序列）

- 先写几个例子，寻找排列之间的特征。