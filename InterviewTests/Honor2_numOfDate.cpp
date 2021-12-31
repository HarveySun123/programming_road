/************************************************************************
*
* �ļ�����Honor2_numOfDate.cpp
*
* �ļ���������ҫ����
* ��Ŀ������
* ���������գ�����ǵ���ڼ��졣��ע��������
*
* �����ˣ�Haohui Sun, 2021��11��23��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
// ͨ��100%
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
	cout << "�ǵ���ĵ� " << numOfDate(year, month, day) << " ��" << endl;

	system("pause");
	return 0;
}