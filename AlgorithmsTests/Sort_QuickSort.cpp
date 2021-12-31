/************************************************************************
*
* �ļ�����Sort_QuickSort.cpp
*
* �ļ���������������(�����Ƽ�ͼ��SDK����һ��)
*
* �����ˣ�Haohui Sun, 2021��11��25��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// void swap(int& n1, int& n2) {
// 	int temp = n1;
// 	n1 = n2;
// 	n2 = temp;
// }

int partion(vector<int>& nums, int left, int right) {

	// ȡ���ֵΪ��׼�������������ֵ����
	int pivot = rand() % (right - left + 1) + left;
	int temp = nums[pivot];
	swap(nums[left], nums[pivot]);

	// �ȽϹ��̣����Ӷ�ΪO(N)
	int l = left, r = right;
	while (l < r) {

		while (l < r && nums[l] <= temp)
			++l;
		while (l < r && nums[r] >= temp)
			--r;

		swap(nums[l], nums[r]);
	}

	// ����
	swap(nums[r], nums[left]);
	return l;
}

void quickSortCore(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;

	int pivot = partion(nums, left, right);
	quickSortCore(nums, left, pivot - 1);
	quickSortCore(nums, pivot + 1, right);
}

void quickSort(vector<int>& nums) {
	int size = nums.size();
	if (size > 0)
		quickSortCore(nums, 0, size - 1);
}

int main() {
	vector<int> vecData;
	int n;
	while (cin >> n) {
		vecData.emplace_back(n);
		if (cin.get() == '\n')
			break;
	}

	quickSort(vecData);
	for (int n : vecData)
		cout << n << " ";

	system("pause");
	return 0;
}