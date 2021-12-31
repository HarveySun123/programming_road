/************************************************************************
*
* 文件名：456Find132pattern.cpp
*
* 文件描述：力扣456题：132模式
*
* 创建人：Haohui Sun, 2021年11月24日
*
* 版本号：1.0
*
* 修改记录：
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
	// 读取不定长数据
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