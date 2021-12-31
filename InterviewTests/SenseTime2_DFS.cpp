/************************************************************************
*
* �ļ�����SenseTime2_DFS.cpp
*
* �ļ������������������������(�����Ƽ�ͼ��SDK�������)
*
* �����ˣ�Haohui Sun, 2021��11��30��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* leftChild;
	TreeNode* rightChild;
	TreeNode(int val) :val(val), leftChild(nullptr), rightChild(nullptr) {};
};

void deepFirst(TreeNode* root) {
	TreeNode* node = root;
	stack<TreeNode*> stk;
	while (node != nullptr) {
		cout << node->val << " ";

		// ���һ���ӽڵ�
		if (node->leftChild == nullptr && node->rightChild == nullptr && stk.empty()) {
			return;
		}

		// �����ӽڵ���ջ
		if (node->rightChild != nullptr) {
			stk.push(node->rightChild);
		}

		// �����ӽڵ���������ӽڵ㣬
		// ���򷵻���������ӽڵ�
		if (node->leftChild != nullptr) {
			node = node->leftChild;
		}
		else if (!stk.empty()) {
			node = stk.top();
			stk.pop();
		}
	}
}

int main() {
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node1->leftChild = node2;
	node2->leftChild = node3;
	node2->rightChild = node4;
	node1->rightChild = node5;

	deepFirst(node1);

	getchar();
	return 0;
}