#include <iostream>
#include <cstdio>
using namespace std;

/*
题解：
如果这两个节点不在同一个子树下面，那么这棵树的根节点就是他们的共同最低父节点。
如果两个都在右子树，那么以右子树的最上面的那个节点作为根节点，重新进行判断，递归调用。
同理两个都在左子树，则方法同上。
也就是说，最终的结果分别只有三种情况，一个节点在右子树，一个节点在左子树。两个节点都在右子树，两个节点都在左子树。
*/

struct TreeNode {
	int m_nvalue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

TreeNode *getLCA(TreeNode *root, TreeNode *X, TreeNode *Y) {
	if (root == NULL) return NULL;              // 空树的情况
	if (X == root || Y == root) return root;    // 只有根节点的情况
	// 分别以当前节点的左右节点为节点查找
	TreeNode *left = getLCA(root->m_pLeft, X, Y);
	TreeNode *right = getLCA(root->m_pRight, X, Y);
	if (left == NULL)           // 左子树没有找到
		return right;
	else if (right == NULL)     // 右子树没有找到
		return left;
	else
		return root;
}

int main() 
{
	return 0;
}
