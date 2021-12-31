/************************************************************************
*
* 文件名：MicroSoft_MyClass.cpp
*
* 文件描述：微软Coding题目：实现空类的几个函数
* 
*
* 创建人：Haohui Sun, 2021年11月19日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <string>

using namespace std;
class MyClass
{
public:
	MyClass() {};
	~MyClass() {};
	// 默认拷贝构造函数
	MyClass(const MyClass & myclass) : m_val(myclass.m_val), m_str(myclass.m_str) {};
	// 默认移动构造函数
	MyClass(MyClass && myclass) : m_val(myclass.m_val), m_str(myclass.m_str) { myclass.m_val = myclass.m_str = nullptr; }; // 参考《C++ Primer》P473
	// 重载构造函数
	MyClass(const int & val, const string & str) : m_val(val), m_str(str) {};

	// 默认赋值运算符
	MyClass & operator = (const MyClass & myclass) {
		m_val = myclass.m_val; 
		m_str = myclass.m_str; 
		return *this;
	};
	// 移动赋值构造函数

private:
	int			m_val;
	std::string m_str;
};