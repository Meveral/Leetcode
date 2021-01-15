#pragma once
/****************************************
*144. 二叉树的前序遍历
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
	\
	 2
	/
   3

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*递归
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		if (root == nullptr)
			return {};

		vector<int> ret{};
		do_preorderTraversal(root, ret);
		return ret;
	}
private:
	void do_preorderTraversal(TreeNode* root, vector<int>&ret)
	{
		if (root == nullptr)
			return;

		ret.push_back(root->val);
		do_preorderTraversal(root->left, ret);
		do_preorderTraversal(root->right, ret);
	}
};
*/
//迭代,利用栈数据结构
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		if (root == nullptr)
			return {};
		vector<int> ret;
		stack<TreeNode*> stc;
		stc.emplace(root);

		while (!stc.empty())
		{
			if (stc.top() == nullptr)
				stc.pop();
			else
			{
				auto it = stc.top();
				stc.pop();

				ret.push_back(it->val);
				stc.emplace(it->right);
				stc.emplace(it->left);
			}
		}
		return ret;
	}
};


