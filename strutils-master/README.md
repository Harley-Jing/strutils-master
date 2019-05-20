# strutils
为 std::string 添加一些字符串处理的常用函数

Add some common extension functions to std::string

* SFormat()   //格式化字符串
* split()     //分割字符串
* SErase()    //删除父串中所有子串
* trim()      //删除字符串前后空格
* toUpper()   //将字符串转化为大写
* toLower()   //将字符串转化为小写
* ......


## sformat
这是一个超级轻量级的 C++ String Format 实现

This is a super lightweight C++ String Format implementation


示例：

//  c++ code

auto str = SFormat("hello world, {0}, {0}, {1}, {2}, {3}", 123, 1.23, "123", std::string("123"));

//  output:

hello world, 123, 123, 1.23, 123, 123

