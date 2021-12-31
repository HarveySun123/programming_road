/************************************************************************
*
* 文件名：SenseTime2_DFS.cpp
*
* 文件描述：深度优先搜索二叉树(商汤科技图像SDK方向二面)
*
* 创建人：Haohui Sun, 2021年11月30日
*
* 版本号：1.0
*
* 修改记录：
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

		// 最后一个子节点
		if (node->leftChild == nullptr && node->rightChild == nullptr && stk.empty()) {
			return;
		}

		// 有右子节点入栈
		if (node->rightChild != nullptr) {
			stk.push(node->rightChild);
		}

		// 有左子节点则遍历左子节点，
		// 否则返回最近的右子节点
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