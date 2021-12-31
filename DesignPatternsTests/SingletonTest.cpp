/************************************************************************
*
* �ļ�����SingletonTest.cpp
*
* �ļ�����������ģʽ
*
* �����ˣ�Haohui Sun, 2021��11��17��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <mutex>
#include <iostream>
using namespace std;

std::mutex mtx;           // mutex for critical section
class SingletonLazily1
{
public:
	static SingletonLazily1* getInstance() {
				
			// ���ж�ʵ���Ƿ���ڣ�����ʵ���Ѵ�����Ҫ���м�������
			if (instance == nullptr) {
				// ������̴߳������ʵ��
				std::lock_guard<std::mutex> lck(mtx);
				// ���������߳�ͬʱͨ����һ���ж�
				if (instance == nullptr) {
					instance = new SingletonLazily1;
				}
			}
	}

private:
	SingletonLazily1() {};	// �����������new����ʵ����·
	SingletonLazily1(const SingletonLazily1&) = delete;
	SingletonLazily1& operator = (const SingletonLazily1&) = delete;
	static SingletonLazily1* instance;
};

class SingletonLazily2
{
public:
	static SingletonLazily2* getInstance() {
		static SingletonLazily2 instance;
		return &instance;
	}

private:
	SingletonLazily2() {};	// �����������new����ʵ����·
	SingletonLazily2(const SingletonLazily2&) = delete;
	SingletonLazily2& operator = (const SingletonLazily2&) = delete;
};
SingletonLazily2 SingletonLazily2::instance;


// ����ʽ
class SigletonEarly
{
public:
	static SigletonEarly* getInstance() {
		return &instance;
	}

private:
	static SigletonEarly instance;
	SigletonEarly() {};	// �����������new����ʵ����·
	SigletonEarly(const SigletonEarly&) = delete;
	SigletonEarly& operator = (const SigletonEarly&) = delete;
};
SigletonEarly SigletonEarly::instance;

int main() {
	SigletonEarly* instance1 = SigletonEarly::getInstance();
	SigletonEarly* instance2 = SigletonEarly::getInstance();
	SigletonEarly* instance3 = SigletonEarly::getInstance();
	cout << instance1 << endl << instance2 << endl << instance3 << endl;

	getchar();
	return 0;
}