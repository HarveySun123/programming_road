/************************************************************************
*
* �ļ�����395LongestSubstring.cpp
*
* �ļ�����������395�⣺����k���ظ��ַ�����Ӵ�
*
* �����ˣ�Haohui Sun, 2021��11��24��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
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
		// �Գ���Ƶ��С��k���ַ��ָ�
		if (it->second < k) {
			split(s, vecSplit, it->first);
			break;
		}
	}

	// �ָ���Ӵ��з��ϵ���Ӵ�����
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