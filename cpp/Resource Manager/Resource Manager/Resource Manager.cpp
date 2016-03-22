// Resource Manager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "c11.h"
#include "c98.h"
#include <iostream>

void leave(char* msg)
{
	cout << msg << endl;
}

int leave2(char* msg, int count)
{
	cout << msg << ":" << count << endl;
	return count;
}

void c98()
{
	leave("i am leaving");
}

void c982()
{
	leave2("i am leaving", 1);
}

int main()
{	
	//HANDLE h = CreateFile(...);
	//ScopeGuard onExit([&] { CloseHandle(h); });  //匿名节省代码量，同时可以引用环境上下文中的变量，可以包装类成员函数，远远优于之前c98的实现

	C11ScopeGuard OnExit([&] { leave("i am leaving");  });   
	C11ScopeGuard OnExit2([&] { leave2("i am leaving", 1);  });

	C98ScopeGuard OnExit3(c98);  //poor
	C98ScopeGuard OnExit4(c982);


	cout << "end" << endl;
    return getchar();
}

