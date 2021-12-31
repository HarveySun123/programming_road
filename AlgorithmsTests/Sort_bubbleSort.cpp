/************************************************************************
*
* �ļ�����Sort_bubbleSort.cpp
*
* �ļ�������ð������
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
// ��������
void swap(int& a, int& b) {
	// 1. a ^ 0 = a; 2. a ^ a = 0; 
	// 3. a ^ b ^ c = a ^ (b ^ c); 4. ����൱�ڲ���λ��
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

// ð��
void bubbleSort(vector<int>& nums) {
	int size = nums.size();
	for (int i = size - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}
}

// ����������ֵ�����ⳤ�ȵ�����
vector<int> generateRandomVector(int maxSize, int maxValue) {
	vector<int> vec1;
	int size = rand() % maxSize;
	for (int i = 0; i < size; ++i) {
		vec1.emplace_back(rand() % maxValue - rand() % maxValue);
	}
	return vec1;
}

int main() {
	int testTimes = 1000;
	int maxSize = 100;
	int maxValue = 100;

	vector<int> vec1 = generateRandomVector(maxSize, maxValue);
	vector<int> vec2(vec1);

//	bubbleSort(vec1);
	quickSort(vec1);
	sort(vec2.begin(), vec2.end());

	bool succeed = true;
	for (int i = 0; i < testTimes; ++i) {
		if (vec1 != vec2) {
			succeed = false;
			break;
		}
	}
	printf(succeed ? "Congratulations!\n" : "Fuck!\n");
	// scanf("%d", &n);
	puts("Nice");
		
	system("pause");
	return 0;
};