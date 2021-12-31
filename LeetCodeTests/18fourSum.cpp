/************************************************************************
*
* �ļ�����18fourSum.cpp
*
* �ļ�����������18�⣺����֮��
*
* �����ˣ�Haohui Sun, 2021��11��18��
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
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		vector<vector<int>> vecRes;

		for (int first = 0; first < size - 1; ++first) {
			// ȷ����һ���ı�
			if (first > 0 && nums[first] == nums[first - 1])
				continue;
			int target1 = target - nums[first];

			for (int second = first + 1; second < size - 1; ++second) {
				// ȷ���ڶ����ı�
				if (second > first + 1 && nums[second] == nums[second - 1])
					continue;
				int target2 = target1 - nums[second];

				int third = second + 1, fourth = size - 1;
				while (third < fourth && third < size - 1 && fourth > second) {
					if (nums[third] + nums[fourth] == target2) {
						vecRes.emplace_back(vector<int>{nums[first], nums[second], nums[third], nums[fourth]});

						// ȷ�������������ı�
						while (third < fourth && nums[third] == nums[third + 1])
							++third;
						while (third < fourth && nums[fourth] == nums[fourth - 1])
							--fourth;
						++third;
						--fourth;
					}
					else if (nums[third] + nums[fourth] < target2)
						++third;
					else
						--fourth;
				}
			}
		}

		return vecRes;
	}
};

int main() {
	// ��ȡ����������
	int val;
	vector<int> vecData;
	while (cin >> val) {
		vecData.emplace_back(val);
		if (cin.get() == '\n')
			break;
	}

	Solution s;
	vector<vector<int>> vecRes = s.fourSum(vecData, 8);
	for (auto vec : vecRes) {
		for (int n : vec) {
			cout << n << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}