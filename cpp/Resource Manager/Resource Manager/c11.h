#pragma once

#include <functional>
using namespace std;

class C11ScopeGuard
{
public:
	explicit C11ScopeGuard(function<void()> onExitScope)
		: onExitScope_(onExitScope), dismissed_(false)
	{ }

	~C11ScopeGuard()
	{
		if (!dismissed_)
		{
			onExitScope_();
		}
	}

	void Dismiss()
	{
		dismissed_ = true;
	}

private:
	function<void()> onExitScope_;
	bool dismissed_;

private: // noncopyable
	C11ScopeGuard(C11ScopeGuard const&);
	C11ScopeGuard& operator=(C11ScopeGuard const&);
};

