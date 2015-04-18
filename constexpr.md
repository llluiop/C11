#constexpr#

##简介##
> A constant expression is an expression whose value cannot change and that can be evaluated at complile time.A literal is a constant expression.A const object that is initialized from a constant expression is also a constant expression.

const表达式就是值不可改变，并且可以在编译器被求值，因此像字面值或者是被const类型初始化的变量都属于此类型。


	const int max_files = 20; // max_files is a constant expression
	const int sz = get_size(); //sz is ont a constant expression


> In C++ 11, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration.Variables declared as constexpr are implicitly const and must be initialized by constant exprssions

新标准下，我们可以使用constexpr关键字来告诉编译器显式的将一个变量定义为const类型：

	constexpr int mf = 10; 
	constexpr int sz = size(); //only if size() is a constexpr function

**那么什么样的类型可以声明为constexpr呢？**

> The arithmetic,reference and pointer types are literal types. Some Class like library IO and string types are not literal types. We can make some class as literal types.
An aggregate class whose date members are all of literal type is a literal class. A nonaggregate class, that meet the following restrictions is also a literal class:

* The data members all must have literal type.
* The class must have at least one constexpr constructor.
* If a data member has an in-class initializer, the initializer for a member of built- type must be a constant expression. or if the member has class type, the initializer must use the member's own constexpr constructor.
* The class must use default definition for its destructor which is the member that destroys objects of the class type.


	    class Debug {
	    public:
	    	constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
	    	constexpr Debug(bool h, bool i, bool o):hw(h), io(i), other(0){}
	    
	    private:
	    	bool hw;
	    	bool io;
	    	bool other;
	    };
    
**Pointer  and constexpr**

	const int *p = nullptr;    //p is a pointer to a const int
	constexpr int *q = nullptr; //a is a const pointer to int
	
	
**constexpr有什么用呢？**

* 提供了更多的通用的值不发生变化的表达式
* 运行用户自定义的类型成为常量表达式
* 提供了一种保证在编译器完成初始化的方法(执行编译器函数调用)

		enum Flag {good = 0, fail = 1, bad = 2, eof = 4};
		
		constepxr int operator|( Flag f1, Flag f2){return Flag(int(f1) | int(f2));}
		
		void fun(Flag x)
		{
			switch(x)
			{...}
		}	


**存在const很多约束失效的情况，这是需要constexpr：**

![const](http://p.blog.csdn.net/images/p_blog_csdn_net/hikaliv@gmail.com/576581/o_Capture_thumb_633868356432343750.jpg)

**我们可以看到，constexpr的运用有着严格的限制，而且增加了语言的复杂度，VS2013并未支持**