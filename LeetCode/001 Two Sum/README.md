难度:
	- ?

思路：
	- 要考虑在一次遍历中做更多的事情
	- 此题答案很巧妙的是，没遍历一个数便将其另一半保存（和当前下标一起）在map中
	- 这样在向下遍历时，搜索map若发现其值则返回。