#include <iostream>
using namespace std;

class Base {
public:
	int _base = 1;
	virtual void fun() {
		cout << "Base()" << endl;
	}
};

class A : virtual public Base {
public:
	int _base = 2;
	virtual void fun() {
		cout << "A()" << endl;
	}
};

class C : virtual public Base {
public:
	//	int _base = 3;
	virtual void fun() {
		cout << "C()" << endl;
	}
};

class D :public A, public C {
public:
	virtual void fun() {
		cout << "D()" << endl;
	}
};

int main() {
	A a;
	C c;
	D d;
	d.fun();	//Base()
	d.A::fun(); //Base()
	d.C::fun(); //Base()
	cout << d.Base::_base << endl; //1
	cout << d.A::_base << endl;	   //2
	cout << d.C::_base << endl;	   //3
	cout << d._base << endl;

	getchar();
	return 0;
}