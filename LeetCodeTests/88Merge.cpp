#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int index1 = m - 1;
	int index2 = n - 1;
	int index3 = m + n - 1;
	while (index2 >= 0) {
		if (nums1[index1] > nums2[index2]) {
			nums1[index3--] = nums1[index1];
			nums1[index1] = INT_MIN;
			--index1;
		}
		else
			nums1[index3--] = nums2[index2--];
	}

	return;
}

int main() {
	// 读取不定长数据
	int val;
	vector<int> vecNums1;
	while (cin >> val) {
		vecNums1.emplace_back(val);
		if (cin.get() == '\n')
			break;
	}

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