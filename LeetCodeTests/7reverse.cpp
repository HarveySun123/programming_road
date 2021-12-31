/************************************************************************
*
* 文件名：7reverse.cpp
*
* 文件描述：力扣第7题：整数反转
*
* 创建人：Haohui Sun, 2021年11月14日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int res = 0;

		while (x != 0) {
			if (res < INT_MIN / 10 || res > INT_MAX / 10)
				return 0;

			res = res * 10 + x % 10;
			x /= 10;
		}

		return res;
	}
};
int main() {
	Solution s;
	int i = s.reverse(-120);
	cout << i;
	getchar();
	return 0;
}