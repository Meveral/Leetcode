#pragma once
/****************************************
*110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"dft.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return 1;
		queue<TreeNode*> nodes;
		map<TreeNode*, int> height{};

		nodes.emplace(root);

		while (!nodes.empty())
		{
			
			int dif;
			auto opt = nodes.front();
			nodes.pop();
			
			if (opt == NULL)
				continue;

			int left = find_height(opt ->left, height);
			int right = find_height(opt->right, height);
			height[opt] = max(left, right) + 1;

			dif = left - right;
			if (dif > 1 || dif < (-1))
				return 0;
			else
			{
				nodes.emplace(opt->left);
				nodes.emplace(opt->right);
			}
		}
			return 1;
	}

	int find_height(TreeNode* root, map<TreeNode*, int>& mp)
	{
		if (root == NULL)
			return 0;
		else
		{
			if (mp.find(root) != mp.end())
				return mp[root];
			else 
			{
				int left = find_height(root->left,mp);
				int right= find_height(root->right,mp);
				int tmp= max(left, right);
				mp[root] = tmp + 1;
				return  mp[root];
			}
		}
	}
};
