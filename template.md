#Varying Template#

**变长模版简介**

> C++ 11运行任意个数，任意类别的模版函数，不必在定义时将参数的个数固定：

	template <typename T, typename... Args>
	void foo(const T& t, const Args& ... rest);
	
	foo(1, 3,14, "hi");
	
> 变长部分的个数可以是0或者多个

> 一个实例：

	void printf(const char* s)
	{
		while (*s)
		{
			if (*s == '%' && *(++s) != '%')
				throw std::runtime_error("invalid format string");
				
			std::cout<<*s++;
		}
	}
	

	template <typename T, typename... Args>
	void printf(const char* s, T value, Args... args)
	{
		while(*s)
		{
			if (*s == '%' && *(++s) != '%')
			{
				std::cout<<value;
				printf(*s ? ++s : s, args...);      //args 将被解析成value和args， 递归
				return;
			}
			
			std::cout<< *s++;
		}
		throw std::runtime_error("extra arguments provided to printf");
	}
	
> 类似：

	template<typename... args>
	struct Count{};
	
	template<>
	struct Count<>{
		static const int value = 0;
	};
	
	template<typename T, typename... Args>
	struct Count<T, Args...>{
		static const int value = 1 + Count<Args...>::value;   //Args被拆分出一个T和剩余的Args
	};
	
		
> Sometimes, we want to write a variadic function that calls a function like debug_reg on *each of its arguments*:

	template <typename... Args>
	ostream& errormsg(ostream& os, const Args... rest)
	{
		return print(os, debug_rep(rest)...);  //每个剩余的rest都会调用debug_rep
	}	
	
	//watch out:
		return print(os, debug_rep(rest...)); //error: no matching function to call