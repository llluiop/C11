#include <thread>
#include <future>
#include <iostream>

using namespace std;

int promise_test()
{
	promise<int> p;
	auto f = p.get_future();

	auto t = thread([&](promise<int>& p) {
		try
		{
			throw std::runtime_error("hi");
		}
		catch (const std::exception&)
		{
			p.set_exception(std::current_exception());
		}
	}, std::ref(p));

	try
	{
		cout << f.get();
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	t.join();

	return 0;
}