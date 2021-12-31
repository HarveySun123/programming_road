/************************************************************************
*
* 文件名：395LongestSubstring.cpp
*
* 文件描述：力扣395题：至少k个重复字符的最长子串
*
* 创建人：Haohui Sun, 2021年11月24日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <unordered_map>

using namespace std;
void split(const string& str, vector<string>& vecSplit, char c = ' ') {

	int left = 0;
	for (int i = 0; i <= str.size(); ++i) {

		if (str[i] == c || str[i] == '\0') {
			if (i > left)
				vecSplit.emplace_back(str.substr(left, i - left));
			left = i + 1;
		}
	}
}

int longestSubstring(string s, int k) {
	if (s.size() < k)
		return 0;

	unordered_map<char, int> hash;
	for (char c : s) {
		++hash[c];
	}

	vector<string> vecSplit;
	for (auto it = hash.begin(); it != hash.end(); ++it) {
		// 以出现频次小于k的字符分割
		if (it->second < k) {
			split(s, vecSplit, it->first);
			break;
		}
	}

	// 分割后子串中符合的最长子串长度
	if (!vecSplit.empty()) {
		int nMax = 0;

		for (string str : vecSplit) {
			nMax = max(nMax, longestSubstring(str, k));
		}
		return nMax;
	}


	return s.size();
}

int main() {
	
	string str;
	int k;
	cin >> str >> k;

	cout << longestSubstring(str, k) << endl;

	system("pause");
	return 0;
}