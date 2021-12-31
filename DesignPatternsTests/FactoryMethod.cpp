/************************************************************************
*
* �ļ�����FactoryMethod.cpp
*
* �ļ���������������ģʽ
*
* �����ˣ�Haohui Sun, 2021��11��25��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/


#include <iostream>

using namespace std;
// ��Ʒ����
class LeiFeng {
public:
	virtual void sweep() = 0;
	virtual void wash() = 0;
};

// Student��Ʒ��
class Student : public LeiFeng {
public:
	void sweep() {
		cout << "student sweep" << endl;
	}

	void wash() {
		cout << "student wash" << endl;
	}
};

// Volunteer��Ʒ��
class Volunteer : public LeiFeng {
public:
	void sweep() {
		cout << "volunteer sweep" << endl;
	}

	void wash() {
		cout << "volunteer wash" << endl;
	}
};

// ����������
class IFactory {
public:
	virtual LeiFeng* CreateLeiFeng() = 0;
};

// ����Student��Ʒ�ľ��幤����
class StudentFactory : public IFactory {
public:
	LeiFeng* CreateLeiFeng() {
		return new Student();
	}
};

// ����Volunteer��Ʒ�ľ��幤����
class VolunteerFactory : public IFactory {
public:
	LeiFeng* CreateLeiFeng() {
		return new Volunteer();
	}
};

// ���������ͻ���
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