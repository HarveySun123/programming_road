/************************************************************************
*
* 文件名：Honor2_numOfDate.cpp
*
* 文件描述：荣耀机试
* 题目描述：
* 输入年月日，输出是当年第几天。（注意闰年概念）
*
* 创建人：Haohui Sun, 2021年11月23日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
// 通过100%
int numOfDate(int year, int month, int day) {
	int res = day;
	vector<int> vecMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < month - 1; ++i) {
		res += vecMonth[i];
	}

	if (year % 4 == 0)
		++res;

	return res;
}

int main() {
	int year, month, day;
	cin >> year >> month >> day;
	cout << "是当年的第 " << numOfDate(year, month, day) << " 天" << endl;

	system("pause");
	return 0;
}