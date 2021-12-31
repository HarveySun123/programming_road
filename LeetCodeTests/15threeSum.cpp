/************************************************************************
*
* �ļ�����15threeSum.cpp
*
* �ļ�����������15�⣺����֮��
*
* �����ˣ�Haohui Sun, 2021��11��16��
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
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	vector<vector<int>> vecRes;

	for (int i = 0; i < size; ++i) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int left = i + 1, right = size - 1;
		if (left >= right)
			return vecRes;

		int target = -nums[i];
		while (left < right) {
			if (nums[left] + nums[right] == target) {
				vecRes.emplace_back(vector<int>({ nums[i], nums[left], nums[right] }));
				++left;
				--right;
				while (left < right && nums[left] == nums[left - 1])
					++left;
				while (left < right && nums[right] == nums[right + 1])
					--right;
			}
			else if (nums[left] + nums[right] < target)
				++left;
			else
				--right;

		}
	}

	return vecRes;
}

int main() {
	// ��ȡ����������
	int val;
	vector<int> vecData;
	while (cin >> val) {
		vecData.emplace_back(val);
		if (cin.get() == '\n')
			break;
	}

	vector<vector<int>> vecRes = threeSum(vecData);
	for (auto vec : vecRes) {
		for (int n : vec) {
			cout << n << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}
