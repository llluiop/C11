#Initializer#

**初始化列表和统一初始化简介**

>下面这个构造函数很常见，同样众所周知的问题：成员变量在进入构造函数体以前已经初始化:	
			
	Sales_data::Sales_data(const string& s, unsigned cnt, double price)
	{
		bookNo = s; 
		units_sold = cnt;
		revenue = cnt * price;
	}
		
> 一般情况下我们可以忽略一个成员函数到底是初始化还是在被赋值，但是考虑下面的情况：

	class Ref
	{
		public:
			Ref( int ii);
		private:
			int i;
			const int ci;
			int& ri;
	};
	
	//error: ci and ri must be initialized
	Ref::Ref(int ii)
	{
		i = ii; // ok
		ci = ii; //error: can not assign to a const
		ri = i;  // error: ri was never initialized
	}
	
	//should be like this:
	Ref::Ref(int ii): i(ii), ci(ii), ri(i){}
	
	
##初始化列表##

> 标准C++从C带来了初始化列表的概念，C++ 03只允许严格遵守POD的定义和限制条件的结构和类上使用这项机能，STL容器可不可用，在新的标准下，引入了`std::initializer_list`， 允许构造函数或者其他函数像参数般使用初始化列表：

	class Sequence
	{
	public:
		Sequence(std::initializer_list<int> list);

	...
	};
	
	Sequence sq = {1 , 4, 5};
	
	这里的构造函数称为初始化列表构造函数
	
	void Function(std::initializer_list<int> list)
 	{
 	...
	}
	
	Function({1, 3, 4});
	
	同样标准容器因为实现了初始化列表构造函数也可以如此：
	vector<int> var = {1, 2, 3};

##统一初始化##

> C++ 11提供了一种统一的语法初始化任意的对象：

	struct Basic
	{
		int x;
		float y;
	};
	
	struct AltStruct
	{
		AltStruct(int x, float y):x(x), y(y){}
		
		private:
		...
	};
	
	Basic v1{1 ,2.0f};
	AltStruct v2{2, 3.0f};   //call AltStruct(int x, float y)
	
> 统一初始化不会取代构造函数语法，如果一个类拥有初始化列表构造函数，而初始化对象时用到的初始化列表符合此构造函数的类型`(initializer_list<SomeType>))`,那么它比其他构造函数的优先级都高，当：

	std::vector<int> vec{4};
	此时会调用初始化列表构造函数，因为vector拥有初始化列表构造函数，而不会去调用只接受一个参数的构造函数
	