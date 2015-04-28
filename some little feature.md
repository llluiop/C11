#Little Feature#

**外部模版**

> 标准C++中，只要在编译单元内遇到完整定义的模版，编译器都必须将其实例化。这会大大增加编译时间，特别是模版在许多编译单元内使用相同的 参数实例化。

> C++ 11将会引入外部模版这一概念，C++已经有了强制编译器在特定位置开始实例化的语法：

	template class std::vector<MyClass>;

> 而C++所缺乏的是阻止编译器在某个编译单元内实例化模版的能力，C++ 11扩充如下：

	extern template class std::vector<MyClass>;
	std::vector<MyClass> myClassVar; //Instantiation will appear in elsewhere(实例化的代码在别的编译单元中)

	
**空指针**

> C++ 11引入了新的关键字代表空指针常数：*nullptr*，将空指针和0分开。nullptr的类型为nullptr_t,可以转换为任何指针或者成员指针的类型，也能和它们进行相等或者不等的比较。不可以转换为整数，也不能和整数比较：

	char* pc = nullptr;
	int i = nullptr; //error
	
**角括号**

> 标准C++的剖析器一律将">>"视为右移运算符。但在模板定义式中，绝大多数的场合其实都代表两个连续右角括号。为了避免剖析器误判，撰码时不能把右角括号连着写。C++11变更了剖析器的解读规则；当遇到连续的右角括号时，优先解析右角括号为模板引用的退出符号。

	template<bool Test> SomeType;
	std::vector<SomeType<1>2>> x1;  // as SomeType<true> 2>, error
	std::vector<SomeType<(1>2)>> x1; //as SomeType<false> , ok