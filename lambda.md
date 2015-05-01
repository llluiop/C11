#Lambda函数#

**简介**

> 很多STL的泛型算法会使用一个函数作为参数：We can pass any kind of callable object(*eg:仿函数,函数指针等*) algorithm. An object or expression is callable if we can apply the call operator to it. 

> A lambda expression represents a callable unit of code. It can be thought of as an unnamed inline function. Like any function, a lambda has a return type, a parameter list, and a function body. Unlike a function, lambda may be defined inside a function.

	[capture list] (parameter list) -> return type  {function body}

> where capture list is an list of local variables defined in the enclosing function; return type, parameter list and function body are the same as in any ordinary function. However, unlike ordinary functions,  a lambda must use a trailing return(参见上述*->return type*) to specify its return type.

> We can omit either or both of the parameter list and return type but must always include the capture list and function body:

	auto f = [] {return 42;}  //no arguments and return type
	
> We can use variables local like:

	int sz = 10;
	[sz](const string& a) {return a.size() >= sz;};
	
>Note: **Capture List is used for local non-static variables only; lambdas can use local statics and variables declared outside the function directly.**

	[]:empty capture list;
	[names]: by value
	[&]: by reference
	[=]:by value
	[&, identifier_list]: identifier_list by values
	[=,  identifier_list]: identifier_list by reference
	
> We have to capture variables by reference such as ostream(can not be copied), and When we **return a lambda** from a function,  the lambda must not contain reference captures. You have to make sure the whatever you captured has the intended meaning each time the lambda is executed. So **avoid** capturing pointers or references.


**mutable lambdas**

> A lambda can not change the value of a variable that it copied by value:

	int v1 = 32;
	auto f = [v1]()  {return ++v1; }; //compiler error: v1 can not be changed
	
	auto f = [v1]() mutable {return ++v1;} //ok
	
> A lambda body contains any statement other than a return is assumed to return void, lambdas inferred to return void may not return a value; 

	transform(v1.begin(), v1.end(), v1.begin(), [](int i){if (i < 0) return -i; else return i;});  //error
	transform(v1.begin(), v1.end(), v1.begin(), [](int i) -> int{if (i < 0) return -i; else return i;});  //ok, using trailing return 

> lambda类型是只有编译使用的类型，如果我们需要使用这个类型需要去创建模版或者使用std::function.