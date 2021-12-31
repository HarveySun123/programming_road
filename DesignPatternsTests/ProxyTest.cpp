/************************************************************************
*
* �ļ�����ProxyTest.cpp
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
#include <iostream>

using namespace std;
// ����RealSubject���Proxy��Ĺ����ӿ�
class Subject
{
public:
	virtual void Request() = 0;
};

// ����Proxy�����������ʵ��
class RealSubject : public Subject
{
public:
	void Request() {
		cout << "��ʵ����" << endl;
	}
};

// ����Proxy�࣬����һ��ʵ�����������ã���ʵ�ֹ����ӿ�
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

// �ͻ���
int main() {
	Proxy* proxy = new Proxy();
	proxy->Request();
	delete proxy;

	getchar();
	return 0;
}