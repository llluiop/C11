#static_assert简介#

**未曾在C++ Primer 5th中找到相关的说明，但是编译器确实都支持**

>断言是C++里是提高代码质量的重要武器，标准库里的assert和MFC里的ASSERT宏都是此类，它们共同的作用都是在代码运行过程中对程序进行判断，而新的标准里的断言是针对编译期代码进行检查的.

	auto item = val1 + val2; //item initialized to the result of val1 + val2;
	template<int N>
	struct Kitten{
		static_assert(N>2, "Kitten need N > 2 !");
		};

	int main()
	{
		Kitten<1> pepermint;
		Kitten<3> jazz;
		return 0;
	}
	
	编译时提示：
	error: Kitten<N> need N > 2!;

>熟悉boost库的应该对static_assert很熟悉，boost里使用了BOOST_STATIC_ASSERT宏，但是这个宏并未使用用户自定义消息，如果断言失败会显示：
	
	error:use of undefined type 'boost::STATIC_ASSERTION_FAILUER<false>'


static_assert可以用在全局作用域，命名空间，类作用域，函数作用域中，几乎没有使用上的限制，当编译器遇到static_assert时，会将表达式进行演算，如果参数依赖于模板参数，类似上面的例子中，那么演算将会推迟到模板实例化时，这就让模板参数的检测成为了事实。

**注意既然是编译器演算，要求演算的值必须是一个编译器的常量**
	
	
	
	


