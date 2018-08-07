难度：

	- #代表思路顺畅，可以解决

思路：

- 自己实现的比较麻烦，借助了map，其中对substr参数不熟悉

  ```
  string substr (size_t pos = 0, size_t len = npos) const;
  ```

  记住其返回string，就算npos=1，也是。C++11规定，string后面跟着\0

- 也可以逆向分析，如果大于某值，遇到特殊的（其值比当前值小）再减去