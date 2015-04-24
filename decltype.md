#decltype#

##简介##
> Sometimes we want to define a variale with a type that complier deduces from an expression but do not want to use that expression to initializer the variable. 
	decltype(f()) sum = x;

	auto sum; //error


> The way decltype handles top-level cosnt and reference dirrers subtly from the way *auto* does. When the expression to wihch we apply decltype is a variable, decltype returns the type of that variable, **including top-level const and reference**:
	
	const int ci = 0; &cj = ci;
	decltype(ci) x = 0; //const int
	decltype(cj) y = x; //const int&
	decltype(cj) z;     //error: not initialzed

> Gnereally speaking, decltype returns a reference type for expressions that yield objects that can stand on the left-hand side of the assignment(如果表达式返回左值，decltype推断的为引用类型):

	int i= 42， *p = &i, &r = i;
	decltype(r+0) b; //b is an int
	decltype(*p) c;  //c is an int& 

> Enclosing the name of a variable in parentheses affects the type returned by decltype. When we apply decltype to a variable without any parenthese, we get the type of that variable. If we wrap the variable's name in one or more sets of parenthese, the complier will evaluate the operand as an expression.A variable is an expression that can be the left-hand side of an assignment. As a result, decltype on such an expression yields a reference:

	decltype(i) d; //ok
	decltype((i)) e; //error : e is an int&
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

**考虑：**

	int i = 0;
	const int& i_am_const = i; //ok, but i could change and makes i_am_const change too.
	constexpr int i_am_constexpr = j; //complie error

**我们可以看到，constexpr的运用有着严格的限制，而且增加了语言的复杂度，VS2013并未支持**
