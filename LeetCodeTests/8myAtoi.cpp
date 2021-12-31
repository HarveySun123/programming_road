#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	int myAtoi1(string s) {
		const char *str = s.c_str();
		while (*str == ' ')
			*str++;

		// 读取正负号
		bool isNeg = false;
		if (*str == '-' || *str == '+') {
			isNeg = *str == '-' ? true : false;
			*str++;
		}

		// 读取数字位
		int sum = 0;
		while (*str >= '0' && *str <= '9') {
			int digit = *str - '0';
			if (sum > INT_MAX / 10 ||
				(sum == INT_MAX / 10 &&
					digit > 7)
				) {
				return isNeg ? INT_MIN : INT_MAX;
			}

			sum = sum * 10 + digit;
			*str++;
		}

		return isNeg ? -sum : sum;
	}

	int myAtoi2(string s) {
		int i = 0, flag = 1, sum = 0;
		while (s[i] == ' ') i++; // 读取空格

		// 读取正负号
		if (s[i] == '-') flag = -1;
		if (s[i] == '-' || s[i] == '+') i++;

		// 读取数字位
		while (s[i] >= '0' && s[i] <= '9') {
			if (sum > INT_MAX / 10 ||
				(sum == INT_MAX / 10 &&
				s[i] - '0' > 7)
				) {
				return flag == 1 ? INT_MAX : INT_MIN;
			}

			sum = sum * 10 + s[i] - '0';
			i++;
		}

		return sum*flag;
	}
};

int main() {
	string str;
	cout << "input :";
	Solution s;
	while (getline(cin, str))
		cout <<"result :" << s.myAtoi1(str) << endl;
	getchar();
	return 0;
}
