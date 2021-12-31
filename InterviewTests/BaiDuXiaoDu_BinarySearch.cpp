/************************************************************************
*
* �ļ�����BaiDuXiaoDu_BinarySearch.cpp
*
* �ļ��������ٶ�С��������2
* ��Ŀ������
* ����һ���ַ����飬��һ��target�ַ�����target������Ҳ���ܲ��������У�
* ���ر�targetС��������ַ��±�
*
* ����
* ����˼�����ѣ��ĳ��˶��ֲ���
* 
* ��һ����Ŀ�ǣ��������ù۲���ģʽ���۲�����momenta�����п�����û��Ū���ף����˿���
*
* �����ˣ�Haohui Sun, 2021��12��3��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
int findChar(vector<char>& vecData, char target) {
	int size = vecData.size();

	int left = 0, right = size - 1;
	int mid = (right - left) / 2 + left;
	while (left < right) {
		if (vecData[mid] > target) {
			right = mid - 1;
		}
		else if (vecData[mid] < target) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

int main() {
	vector<char> vecData;
	char c;
	while (cin >> c) {
		vecData.emplace_back(c);
		if (cin.get() == '\n') {
			break;
		}
	}

	char target;
	cin >> target;
	cout << findChar(vecData, target) << endl;

	system("pause");
	return 0;
}