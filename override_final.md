#Override#

**显示虚函数重载**

**Override**

> 在C++里，子类容易意外的重载虚函数：

	struct Base
	{
		virtual void fun();
	};
	
	struct Derived: Base
	{
		void fun();
	};
	
	Derived::fun()可能是重载，但也可能是用户自定义的一个函数刚好和父类的虚函数同名，如果是前者，一旦父类函数改变签名，那么子类的函数就变成了一个新的函数而用户无法得到任何的通知。
	
> 在C11中，加入了override指示字在编译器捕获此类错误，同时为了向后兼容，此功能是可选的：

	
	struct Base
	{
		virtual void fun(float);
	};
	
	struct Derived: Base
	{
		virtual void fun(int) override;  //错误，父类无此虚函数
		virtual void fun(float) override; //正确
	};
	
**final**	

> C11中现在提供新的指示字final，避免类被继承或者是基类函数被改写：

	struct Base1 final { };
 
	struct Derived1 : Base1 { }; // 錯誤格式：class Base1已標明為final
	 
	struct Base2 {
	    virtual void f() final;
	};
	 
	struct Derived2 : Base2 {
	    void f(); // 錯誤格式：Base2::f已標明為final
	};
	
> override和final都不是关键字	

	