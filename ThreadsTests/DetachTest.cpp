#include <stdio.h>
#include <thread>
#include <Windows.h>

void threadproc()
{
	while (true)
	{
		printf("I am New Thread!\n");
	}
}

void func()
{
	// 由于线程函数调用结束时，线程对象已经被销毁了
	// 因此运行时会崩溃，可以用detach来解决
	// 这个方法让线程对象与线程函数脱离关系
	// 实际编码并不推荐，因为我们需要尽量让线程运行期间有效
	std::thread t(threadproc);
	t.detach();

}

int main()
{
	func();

	while (true)
	{
		Sleep(1000);
		//权宜之计，让主线程不要提前退出
	}

	return 0;
}