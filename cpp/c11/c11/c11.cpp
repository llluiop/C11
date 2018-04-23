// c11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <thread>

using namespace std;

extern int promise_test();

int main()
{
	promise_test();

    return getchar();
}

