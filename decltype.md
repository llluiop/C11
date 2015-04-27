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
