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
	// �����̺߳������ý���ʱ���̶߳����Ѿ���������
	// �������ʱ�������������detach�����
	// ����������̶߳������̺߳��������ϵ
	// ʵ�ʱ��벢���Ƽ�����Ϊ������Ҫ�������߳������ڼ���Ч
	std::thread t(threadproc);
	t.detach();

}

int main()
{
	func();

	while (true)
	{
		Sleep(1000);
		//Ȩ��֮�ƣ������̲߳�Ҫ��ǰ�˳�
	}

	return 0;
}