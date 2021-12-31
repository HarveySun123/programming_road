/************************************************************************
*
* �ļ�����977SortedSuqares.cpp
*
* �ļ�����������977�⣺���������ƽ��
*
* �����ˣ�Haohui Sun, 2021��11��28��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sortedSquares(vector<int>& nums) {

	// ��λ�����ֽ��
	int left = nums.size() - 1, right = -1;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] >= 0) {
			right = i;
			left = i - 1;
			break;
		}
	}

	// ��ָ�����ң���ָ������
	vector<int> vecRes(nums.size(), 0);
	int index = 0;
	while (right < nums.size() || left >= 0) {
		if (right >= nums.size())
			vecRes[index++] = pow(nums[left--], 2);
		else if (left < 0)
			vecRes[index++] = pow(nums[right++], 2);
		else
			vecRes[index++] = abs(nums[left]) < abs(nums[right]) ?
			pow(nums[left--], 2) : pow(nums[right++], 2);

	}

	return vecRes;
}

int main() {
	vector<int> vecOri;
	int n;
	while (cin >> n) {
		vecOri.emplace_back(n);
		if (cin.get() == '\n') {
			cout << endl;
			break;
		}
	}

	vector<int> vecSorted = sortedSquares(vecOri);
	for(int n : vecSorted)
		cout << n << " ";

	getchar();
	return 0;
}