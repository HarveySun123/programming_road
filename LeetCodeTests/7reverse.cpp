/************************************************************************
*
* �ļ�����7reverse.cpp
*
* �ļ����������۵�7�⣺������ת
*
* �����ˣ�Haohui Sun, 2021��11��14��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
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