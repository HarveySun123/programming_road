/************************************************************************
*
* 文件名：ProxyTest.cpp
*
* 文件描述：代理模式
*
* 创建人：Haohui Sun, 2021年11月17日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>

using namespace std;
// 定义RealSubject类和Proxy类的公共接口
class Subject
{
public:
	virtual void Request() = 0;
};

// 定义Proxy类所代理的真实类
class RealSubject : public Subject
{
public:
	void Request() {
		cout << "真实请求" << endl;
	}
};

// 定义Proxy类，保存一个实体类对象的引用，并实现公共接口
class Proxy : public Subject
{
public:
	void Request() {
		if (realSubject == nullptr) {
			realSubject = new RealSubject;
		}
		realSubject->Request();
	}

private:
	RealSubject* realSubject;
};

// 客户端
int main() {
	Proxy* proxy = new Proxy();
	proxy->Request();
	delete proxy;

	getchar();
	return 0;
}