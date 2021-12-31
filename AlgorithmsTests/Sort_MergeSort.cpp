/************************************************************************
*
* 文件名：Sort_QuickSort.cpp
*
* 文件描述：归并排序
*
* 创建人：Haohui Sun, 2021年11月18日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> vecHelp(right - left + 1, -1); // 辅助空间
	int p1 = left, p2 = mid + 1, index = 0;

	// 合并事件复杂度O(N)
	while (p1 <= mid && p2 <= right)
		vecHelp[index++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];

	while (p1 <= mid)
		vecHelp[index++] = nums[p1++];
	while (p2 <= right)
		vecHelp[index++] = nums[p2++];

	for (int n : vecHelp)
		nums[left++] = n;
}

void mergeSortCore(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;
	// 需要O(lgN)次合并
	int mid = left + (right - left) / 2;
	mergeSortCore(nums, left, mid);
	mergeSortCore(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

void mergeSort(vector<int>& nums) {
	if (nums.size() < 2)
		return;
	mergeSortCore(nums, 0, nums.size() - 1);
}

int main() {
	vector<int> vecNums;
	int n;
	while (cin >> n) {
		vecNums.emplace_back(n);
		if (cin.get() == '\n')
			break;
	}

	mergeSort(vecNums);
	for (int n : vecNums) {
		cout << n << " ";
	}

	getchar();
	return 0;
}