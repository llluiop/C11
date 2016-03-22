#std::thread#

**简介**

> 标准库提供了std::thread，可以创建一个类thread的实体，初始参数为一个函数对象，以及该函数对象所需的参数

> std::thread构造：

|:-------------- | :-------------|
|default(1) | thread() noexcept;|
|initialization(2) | template<class Fn, class... Arg> explicit thread(Fn&& fn, Args&&... args);|
|copy(3) | thread(const thread&) = delete;|
|move(4) | thread(thread&& x) noexcept;|

1. 默认构造，创建一个空对象
1. 初始化拷贝构造函数，该函数可被joinable，新产生的线程会调用fn函数，参数为args
1. 拷贝构造函数被禁用，意味着thread不可拷贝构造
1. move构造，调用成功后x无效

	int main()
	{
		int n = 0;
		std::thread t1;
		std::thread t2(f1, n+1);
		std::thread t3(f2, std::ref(n));
		std::trhead t4(std::move(t3));
	}	
	
	
> std::thread move:

|:-------------- | :-------------|
|move(1) | thread& operator= (thread&& rhs) noexcept ;|
|copy(2) | thread& operator=(const thread&) = delete;|


1. move赋值，如果当前对象不可joinable， 需要传递一个右值引用；负责teminate()报错
1. 拷贝赋值被禁用

	int main()
	{
		std::thread threads[5];
		for(int i = 0; i < 5; i++)
			thread[i] = std::thread(fn, i+1);  //move
			
		for(auto& t: threads){          
			t.join();
		}
	}	
