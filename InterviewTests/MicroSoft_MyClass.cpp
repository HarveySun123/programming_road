/************************************************************************
*
* �ļ�����MicroSoft_MyClass.cpp
*
* �ļ�������΢��Coding��Ŀ��ʵ�ֿ���ļ�������
* 
*
* �����ˣ�Haohui Sun, 2021��11��19��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <string>

using namespace std;
class MyClass
{
public:
	MyClass() {};
	~MyClass() {};
	// Ĭ�Ͽ������캯��
	MyClass(const MyClass & myclass) : m_val(myclass.m_val), m_str(myclass.m_str) {};
	// Ĭ���ƶ����캯��
	MyClass(MyClass && myclass) : m_val(myclass.m_val), m_str(myclass.m_str) { myclass.m_val = myclass.m_str = nullptr; }; // �ο���C++ Primer��P473
	// ���ع��캯��
	MyClass(const int & val, const string & str) : m_val(val), m_str(str) {};

	// Ĭ�ϸ�ֵ�����
	MyClass & operator = (const MyClass & myclass) {
		m_val = myclass.m_val; 
		m_str = myclass.m_str; 
		return *this;
	};
	// �ƶ���ֵ���캯��

private:
	int			m_val;
	std::string m_str;
};