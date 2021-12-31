#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		int len = INT_MIN, left = 0, right = 0;
		unordered_set<char> setChar;

		while (right < size) {

			// 维护滑动窗口，直到剔除所有重复元素
			while (setChar.find(s[right]) != setChar.end()) {
				setChar.erase(s[left]);
				++left;
			}

			len = max(right - left + 1, len);
			setChar.insert(s[right]);
			++right;
		}

		return len == INT_MIN ? 0 : len;
	}
};

int main() {
	string str = "aaabcbbcef";
	Solution s;
	cout << s.lengthOfLongestSubstring(str);
	getchar();
	return 0;
}