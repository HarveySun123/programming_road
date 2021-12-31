/************************************************************************
*
* �ļ�����456Find132pattern.cpp
*
* �ļ�����������456�⣺132ģʽ
*
* �����ˣ�Haohui Sun, 2021��11��24��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <stack>
#include <vector> 
#include <algorithm>

using namespace std;
bool find132pattern(vector<int>& nums) {

	stack<int> stk;
	int k = INT_MIN;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] < k)
			return true;

		while (!stk.empty() && nums[i] > stk.top()) {
			k = max(k, stk.top());
			stk.pop();
		}
		stk.push(nums[i]);
	}

	return false;
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

		cout << find132pattern(vecData) << endl;

	getchar();
	return 0;
}