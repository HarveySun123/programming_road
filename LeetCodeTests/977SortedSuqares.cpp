/************************************************************************
*
* 文件名：977SortedSuqares.cpp
*
* 文件描述：力扣977题：有序数组的平方
*
* 创建人：Haohui Sun, 2021年11月28日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sortedSquares(vector<int>& nums) {

	// 定位正负分界点
	int left = nums.size() - 1, right = -1;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] >= 0) {
			right = i;
			left = i - 1;
			break;
		}
	}

	// 右指针向右，左指针向左
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