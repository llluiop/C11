#Auto关键字#

**auto的由来**

>When we write a program, it can be surprisingly difficult-and sometimes even impossible-to determine the type of and expression. Under C++ 0x, we can let the complier figure out the type for us by using the auto type specifier.
>
>By implication, a variable that uses auto as its type specifier must have an initializer:

	auto item = val1 + val2; //item initialized to the result of val1 + val2;
	
所以可以看到，可以要求编译器来为我们觉得变量的类型，这在很多时候都会有用：

* 迭代时：

		for (std::vector<int>::iterator iter = cont.begin(); iter != cont.end(); iter++){
		//...
		}
		
	此时我们是没有必要cont.begin()的类型是什么，它必然是一个迭代器，同时当vector改为list时，我们的代码也要改变，这违反了DRY原则。

* 在一些boost的库的使用时：

        	std::string s = boost::lexical_cast<std::string>(i);

	std::string出现了两次。
	
	
	
**害羞的语言推导系统**

>在C++里，`sizeof(arbitrarily complex expression)`可以获取任何表达式的结果的大小，所以C++语言引擎是可以推导出任何表达式的结果类型的，所以`sizeof`的背后存在了一个[类型推导系统.]([http://blog.csdn.net/pongba/article/details/1776255](http://blog.csdn.net/pongba/article/details/1776255))

>既然有，那么auto从语言层面就自然出现了。


**使用上的注意**
>When we use a reference as an initializer, the initializer is the corresponding object,The complier uses that object's type for auto's type deduction:

		int i = 0, &r = i;
		auto a = r; //a is an int
		
>auto ordinarily ignores top-level const. As usual in initializations. low-level const ,such as when an initializer is a pointer to const, are kept:

		cosnt int ci = i, &cr = ci;
		auto b = ci; // b is an int, top-level const in ci is dropped
		auto c = cr; // c is an int, top-level const in ci is dropped
		auto e = &ci; // e is const int*, & of a const object is low-level const
		
		// if we want the deduced type to have a top-level const, we must say so explicitly:
		const auto f= ci; // deduced type of ci is int; f has type const int
		
		// when we ask for a reference to an auto-deduced type, top-level const in the initializer are not ignored.
		auto &g = ci; // g is a const int&
		auto &h = 42; //error
		const auto &j = 42; //ok