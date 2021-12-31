/************************************************************************
*
* 文件名：SingletonTest.cpp
*
* 文件描述：单例模式
*
* 创建人：Haohui Sun, 2021年11月17日
*
* 版本号：1.0
*
* 修改记录：
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
				
			// 先判断实例是否存在，避免实例已创建仍要进行加锁操作
			if (instance == nullptr) {
				// 避免多线程创建多个实例
				std::lock_guard<std::mutex> lck(mtx);
				// 避免两个线程同时通过第一层判断
				if (instance == nullptr) {
					instance = new SingletonLazily1;
				}
			}
	}

private:
	SingletonLazily1() {};	// 堵死外界利用new创建实例的路
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
	SingletonLazily2() {};	// 堵死外界利用new创建实例的路
	SingletonLazily2(const SingletonLazily2&) = delete;
	SingletonLazily2& operator = (const SingletonLazily2&) = delete;
};
SingletonLazily2 SingletonLazily2::instance;


// 饿汉式
class SigletonEarly
{
public:
	static SigletonEarly* getInstance() {
		return &instance;
	}

private:
	static SigletonEarly instance;
	SigletonEarly() {};	// 堵死外界利用new创建实例的路
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