#pragma once
#include"dft.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class tree_traversal
{
public:
	void pre_order_recursive(TreeNode* root, vector<TreeNode*>& ret)
	{
		if (root == NULL)
			return;
		ret.push_back(root);
		pre_order_recursive(root->left, ret);
		pre_order_recursive(root->right, ret);
	}
	void in_order_recursive(TreeNode* root, vector<TreeNode*>& ret)
	{
		if (root == NULL)
			return;
		in_order_recursive(root->left, ret);
		ret.push_back(root);
		in_order_recursive(root->right, ret);
	}
	void post_order_recursive(TreeNode* root, vector<TreeNode*>& ret)
	{
		if (root == NULL)
			return;
		post_order_recursive(root->left, ret);
		post_order_recursive(root->right, ret);
		ret.push_back(root);
	}

	void pre_order(TreeNode* root, vector<TreeNode*>& ret)
	{
		if (root == NULL)
			return;
		stack<TreeNode*> sta;
		sta.push(root);
		while (!sta.empty())
		{
			auto* it = sta.top();
			sta.pop();

			ret.push_back(it);
			if (it->right != nullptr)
				sta.push(it->right);
			if (it->left != nullptr)
				sta.push(it->left);
		}
	}
};
