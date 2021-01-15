#pragma once
#include<vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (root->left != NULL && root->right != NULL)
			return max(root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right), rob(root->left) + rob(root->right));
		else if (root->left == NULL && root->right != NULL)
			return max(root->val + rob(root->right->left) + rob(root->right->right), rob(root->right));
		else if (root->left != NULL && root->right == NULL)
			return max(root->val + rob(root->left->left) + rob(root->left->right), rob(root->left));
		//		else if (root->left == NULL && root->right == NULL)
		else
			return root->val;
	}
};
