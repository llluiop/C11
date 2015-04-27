#Trailing return types#

**回返类型后置的函数声明**

> Using an explicit template argument to represent a template function's return type works well when we want to let the user determine the return type. In other cases, requiring an explicit template argument imposes a burden on the user with no compensating advantage. For example we might want to write a function that takes a pair of iterators denoting a sequence and returns a reference to an element in the sequence:
	
	template <typename It>
	??? &fcn(It beg, It end)
	{
		return *beg;  //return a reference to an element from the range
	}
	
> we don't know the exact type we want to return, but we do know that we want that type to be a reference to the element type of the sequence we are processing:

	auto &i = fcn(v.begin(), v.end());
	
> we can use decltype(*beg) to obtain the type of that expression:`decltype(*beg) &fcn(It beg, It end)`, but **beg** does not exist until the parameter list has been seen(在编译器看到后面的参数列表前，beg是没有定义的，所以无法通过编译),so:
> 
	template <typename It>
	auto fcn(It beg, It end) -> decltype(*beg)
	{
		return *beg;  //return a reference to an element from the range
	}
	
> Here we have told the compiler that fcn's return type is the same as the type returned by dereferencing its beg parameter. The dereference operator returns an **lvalue**, so the type deduced by decltype is a reference to type of the element that beg denotes. Thus, if fcn is called on a sequence of strings, the return type will be string&. if the sequence is int, the return will be int&.