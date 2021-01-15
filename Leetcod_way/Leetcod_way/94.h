#pragma once
/****************************************
*94.二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

 

示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：


输入：root = [1,2]
输出：[2,1]
示例 5：


输入：root = [1,null,2]
输出：[1,2]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-12
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution_Recursive {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)
			return vector<int>{};

		vector<int> ret{};
		post_traveral(root, ret);

		return ret;
	}
	void post_traveral(TreeNode* root, vector<int>&ret)
	{
		if (root)
		{
			post_traveral(root->left, ret);
			ret.push_back(root->val);
			post_traveral(root->right, ret);
		}
	}

};

class Solution_Interation {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)
			return vector<int>{};
		stack<TreeNode*> stk{};
		stk.push(root);
		vector<int> ret{};
		while (!stk.empty())
		{
			while (root->left)
			{
				stk.push(root->left);
				root = root->left;
			}
			auto tmp = stk.top();
			while (!tmp->right)
			{
				ret.push_back(tmp->val);
				stk.pop();
				if (!stk.empty())
					tmp = stk.top();
				else
					break;
			}
			if (tmp->right)
			{
				stk.pop();
				ret.push_back(tmp->val);
				stk.push(tmp->right);
				root = tmp->right;
			}
		}
		return ret;
	}
};

/****************************************
*Morris 中序遍历改天再写 
***************************************/

