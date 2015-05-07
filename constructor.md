#Constructor#

**构造函数的改良**

> 在标准C++里，构造函数不可以调用其他构造函数，每个构造函数必须自己初始化所有的成员或者调用一个公共的成员函数。基类的构造函数不能作为派生类的构造函数。non-constant的数据成员不能够在声明的地方初始化，他们只能在构造函数中被初始化。

> C++ 11允许构造函数调用其他的构造函数，这种做法称为委托或者转接(delegation):

	class SomeType{
		int number;
		string name;
		SomeType(int i, string s): number(i), name(s){}
		
	public:
		SomeType(): SomeType(0, "invalid"){}
		SomeType(int i): SomeType(i, "invalid"){}
		SomeType(string s): SomeType(1, s){ PostInt();}
	};
	
	使用转接的构造函数，函数本体中的代码`eg:PostInt()`会在被转接的构造函数执行完后继续运行。
	

> C++11运行派生类手动继承基类的构造函数，这种继承要不然是全部继承，要不然是不继承，如果是多重继承，多个基类继承来的构造函数不可以有相同的函数签名，派生类的构造函数也不可以和基类构造函数同名：

	class Base
	{
	public:
		Base(int value);
	};
	
	Class Derived: public Base
	{
	public:
		using Base::Base;
	};	
	
	此语法的含义是为Derived声明一个Derived(int)的构造函数
	
> 成员初始化：

	class Foo
	{
	public:
		Foo() {}
		explicit Foo(int value): value(value) {}
		
	private:
		int value = 5;
	};
	
	Foo()将使用value的初始值5，explicit Foo(int value)将使用设定的值
