/************************************************************************
*
* 文件名：FactoryMethod.cpp
*
* 文件描述：工厂方法模式
*
* 创建人：Haohui Sun, 2021年11月25日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/


#include <iostream>

using namespace std;
// 产品基类
class LeiFeng {
public:
	virtual void sweep() = 0;
	virtual void wash() = 0;
};

// Student产品类
class Student : public LeiFeng {
public:
	void sweep() {
		cout << "student sweep" << endl;
	}

	void wash() {
		cout << "student wash" << endl;
	}
};

// Volunteer产品类
class Volunteer : public LeiFeng {
public:
	void sweep() {
		cout << "volunteer sweep" << endl;
	}

	void wash() {
		cout << "volunteer wash" << endl;
	}
};

// 工厂方法类
class IFactory {
public:
	virtual LeiFeng* CreateLeiFeng() = 0;
};

// 生产Student产品的具体工厂类
class StudentFactory : public IFactory {
public:
	LeiFeng* CreateLeiFeng() {
		return new Student();
	}
};

// 生产Volunteer产品的具体工厂类
class VolunteerFactory : public IFactory {
public:
	LeiFeng* CreateLeiFeng() {
		return new Volunteer();
	}
};

// 工厂方法客户端
int main() {
	IFactory* factory1 = new StudentFactory();
	LeiFeng* leifeng1 = factory1->CreateLeiFeng();
	leifeng1->sweep();
	leifeng1->wash();

	IFactory* factory2 = new VolunteerFactory();
	LeiFeng* leifeng2 = factory2->CreateLeiFeng();
	leifeng2->sweep();
	leifeng2->wash();

	getchar();
	return 0;
}