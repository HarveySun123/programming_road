#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void fun() {
		cout << "Base1()" << endl;
	}
};

class Base2 {
public:
	virtual void fun() {
		cout << "Base2()" << endl;
	}
}; 

class Base3 {
public:
	virtual void fun() {
		cout << "Base3()" << endl;
	}
};

class Derived :public Base1, public Base2, public Base3 {
public:
	virtual void fun() {
		cout << "Derived()" << endl;
	}
};

int main() {
	Base1 b1;
	Base2 b2;
	Base3 b3;
	Derived d;
	Base1* p1 = new Derived();
	Base1* p2 = new Derived();
	Base1* p3 = new Derived();
	p1->fun();
	p2->fun();
	p3->fun();
	getchar();
	return 0;
}