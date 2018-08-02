难度：
	-？
思路:
	- 第一次卡在，要求只丢弃开头的空格，考虑把排除查找的循环放在循环外边，对string搜索算法不熟悉，比如find,rfind, find_first_of,find_first_not_of, find_last_of, find_last_not_of也造成了一定的障碍
	- 还有就是难在溢出的判断，可以采取1.使用比int大的整型来判断溢出（可是若是案例大于所选类型还是会出错的） 2.看题解，感觉更合适