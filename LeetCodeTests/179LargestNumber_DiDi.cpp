/************************************************************************
*
* �ļ�����179LargestNumber.cpp
*
* �ļ�����������179�⣺�����
* ˵����
* ����ʵ�ֿ���
*
* �����ˣ�Haohui Sun, 2021��11��18��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	void swap(vector<int>& nums, int n1, int n2) {
		if (n1 < 0 || n1 >= nums.size() || n2 < 0 || n2 >= nums.size())
			return;

		int nTemp = nums[n1];
		nums[n1] = nums[n2];
		nums[n2] = nTemp;
	}

	int partion(vector<int>& nums, int start, int end) {
		// ȡ�����
		int nRand = (rand() % (end - start)) + start;
		string strRand = std::to_string(nums[nRand]);
		swap(nums, start, nRand);

		int left = start, right = end;
		while (left < right) {
			string strL = std::to_string(nums[left]);
			string strR = std::to_string(nums[right]);
			while (right > left && strR + strRand <= strRand + strR) {
				right--;
				strR = std::to_string(nums[right]);
			}
			while (right > left && strL + strRand >= strRand + strL) {
				left++;
				strL = std::to_string(nums[left]);
			}

			swap(nums, left, right);
		}

		swap(nums, start, left);
		return left;
	}

	void quickSort(vector<int>& nums, int start, int end) {
		if (start >= end)
			return;
		int pivot = partion(nums, start, end);
		quickSort(nums, start, pivot - 1);
		quickSort(nums, pivot + 1, end);
	}

	string largestNumber(vector<int>& nums) {
		// ����һ������ʵ�ֿ�������
		// quickSort(nums, 0, nums.size() - 1);

		// ���������Զ���ȽϹ���
		auto myCom = [](int n1, int n2) {
			string str1 = std::to_string(n1);
			string str2 = std::to_string(n2);
			return (str2 + str1 < str1 + str2);
		};
		sort(nums.begin(), nums.end(), myCom);

		string strRes;
		for (int n : nums)
			strRes.append(std::to_string(n));

		// �߽紦��
		if (strRes[0] == '\0' || strRes[0] == '0')
			return "0";

		return strRes;
	}
};

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

	Solution s;
	cout << s.largestNumber(vecOri) << endl;

	getchar();
	return 0;
}