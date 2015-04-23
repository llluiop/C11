#For#

**C++ 0x For简介**

>The new standard introduced a simpler *for* statement that can be used to iterate through the elements of a container or other sequence. The syntactic form of the *range for statement* is:	
			
	for (declaration : expression)
		statement
		
> expression must represent a sequence, such as braced initializer list, an array, or an object of a type such as vector or string that has begin and end members that can return iterators.

>The easiest way to ensure that the declaration type matches is to use the *auto* type specifier. if we want to write to the elements in the sequence, the loop variable must be a reference type(使用引用类型来改变序列内元素).

	vector<int> v = {0, 1, 2, 3, 4, 5};
	for(auto &r : v)
		r *= 2;
		
> 迭代过程中容器不可增加或删除元素：We can **not use a range for to add elements to a vector(or other container).** In a range for, the value of *end()* is cached. If we add elements to(or remove them from) the sequence, the value of end might be invalidated. 
