/************************************************************************
*
* 文件名：BaiDuXiaoDu_BinarySearch.cpp
*
* 文件描述：百度小度面试题2
* 题目描述：
* 给定一个字符数组，和一个target字符。（target可能在也可能不在数组中）
* 返回比target小的最近的字符下标
*
* 附：
* 看我思考困难，改成了二分查找
* 
* 第一个题目是，让我手敲观察者模式（观察者在momenta二面中考过，没有弄明白，吃了亏）
*
* 创建人：Haohui Sun, 2021年12月3日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
int findChar(vector<char>& vecData, char target) {
	int size = vecData.size();

	int left = 0, right = size - 1;
	int mid = (right - left) / 2 + left;
	while (left < right) {
		if (vecData[mid] > target) {
			right = mid - 1;
		}
		else if (vecData[mid] < target) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

int main() {
	vector<char> vecData;
	char c;
	while (cin >> c) {
		vecData.emplace_back(c);
		if (cin.get() == '\n') {
			break;
		}
	}

	char target;
	cin >> target;
	cout << findChar(vecData, target) << endl;

	system("pause");
	return 0;
}