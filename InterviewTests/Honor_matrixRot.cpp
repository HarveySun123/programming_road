/************************************************************************
*
* 文件名：7reverse.cpp
*
* 文件描述：荣耀机试
* 题目描述:
* 输入一个N阶方阵（0<N<10），输出此方阵顺时针旋转M（0 <= M <= 10000）次后的方阵（数字绕中心顺时针旋转，旋转一次相当于旋转90°）
* 输入描述:
* 输入第一行一个正整数 N (0< N <10)
* 接下来 N 行每行 N 个整数用空格分开,为方阵的数据接下来一行一个正整数 M (0<= M く=10000)
* 说明:不用考虑异常输入,所有输入都是正常的,严格遵从取值池
* 输出描述:
* N 行,每行 N 个整数,用空格分开,为旋转后的数据
*
* 创建人：Haohui Sun, 2021年11月15日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// 通过100%
vector<vector<int>> matrixRota(vector<vector<int>> vec) {
	int count = vec.size();
	vector<vector<int>> vecRes(count, vector<int>(count));	// 初始化

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			vecRes[j][count - i - 1] = vec[i][j];
		}
	}
	return vecRes;
}

int main() {
	int N, M;
	vector<vector<int>> vec;
	
	cin >> N;
	int n;
	vector<int> vecRow;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			vecRow.emplace_back(n);
		}
		vec.emplace_back(vecRow);
		vecRow.clear();
	}
	cin >> M;

	vector<vector<int>> vecLas(vec);
	vector<vector<int>> vecCur(vec);
	for (int r = 0; r < (M % 4); r++) {
		vecCur = matrixRota(vecLas);
		vecLas = vecCur;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << vecCur[i][j];
			if (j != N - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}