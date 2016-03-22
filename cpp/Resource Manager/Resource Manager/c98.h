#pragma once


typedef void(*Fn)();

class C98ScopeGuard
{
public:
	explicit C98ScopeGuard(Fn onExitScope)
		: onExitScope_(onExitScope), dismissed_(false)
	{ }

	~C98ScopeGuard()
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
	Fn onExitScope_;
	bool dismissed_;

private: // noncopyable
	C98ScopeGuard(C98ScopeGuard const&);
	C98ScopeGuard& operator=(C98ScopeGuard const&);
};
