/************************************************************************
*
* �ļ�����7reverse.cpp
*
* �ļ���������ҫ����
* ��Ŀ����:
* ����һ��N�׷���0<N<10��������˷���˳ʱ����תM��0 <= M <= 10000���κ�ķ�������������˳ʱ����ת����תһ���൱����ת90�㣩
* ��������:
* �����һ��һ�������� N (0< N <10)
* ������ N ��ÿ�� N �������ÿո�ֿ�,Ϊ��������ݽ�����һ��һ�������� M (0<= M ��=10000)
* ˵��:���ÿ����쳣����,�������붼��������,�ϸ����ȡֵ��
* �������:
* N ��,ÿ�� N ������,�ÿո�ֿ�,Ϊ��ת�������
*
* �����ˣ�Haohui Sun, 2021��11��15��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// ͨ��100%
vector<vector<int>> matrixRota(vector<vector<int>> vec) {
	int count = vec.size();
	vector<vector<int>> vecRes(count, vector<int>(count));	// ��ʼ��

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